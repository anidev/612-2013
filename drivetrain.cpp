#include <cmath>
#include <Jaguar.h>
#include <Talon.h>
#include "612.h"
#include "auto_encoders.h"
#include "drivetrain.h"
#include "ports.h"
#include "shifter.h"

DriveTrain::DriveTrain(drivetrain_info dinfo,encoders_info einfo,hw_info s1,hw_info s2):encoders(einfo),shift(s1,s2) {
#ifdef Suzie
    left_front = new Jaguar(dinfo.left_front.moduleNumber,dinfo.left_front.channel);
    left_rear = new Jaguar(dinfo.left_rear.moduleNumber,dinfo.left_rear.channel);
    right_front = new Jaguar(dinfo.right_front.moduleNumber,dinfo.right_front.channel);
    right_rear = new Jaguar(dinfo.right_rear.moduleNumber,dinfo.right_rear.channel);
#else
    left_front = new Talon(dinfo.left_front.moduleNumber,dinfo.left_front.channel);
    left_rear = new Talon(dinfo.left_rear.moduleNumber,dinfo.left_rear.channel);
    right_front = new Talon(dinfo.right_front.moduleNumber,dinfo.right_front.channel);
    right_rear = new Talon(dinfo.right_rear.moduleNumber,dinfo.right_rear.channel);
#endif
    operation = MANUAL;
    robotDrive = new RobotDrive(left_front,left_rear,right_front,right_rear);
    robotDrive -> SetSafetyEnabled(false);
    encoders.reset_distance();
    finished = false;
    updateRegistry.addUpdateFunction(&update_helper,(void*)this);
}

DriveTrain::~DriveTrain() {
    delete robotDrive;
    delete left_front;
    delete left_rear;
    delete right_front;
    delete right_rear;
}

void DriveTrain::Scale ()
{
    if (global_state.get_state() == CLIMBING)  
    {
        DRIVE_SPEED = 0.2f;
        TURN_SPEED = 0.2f;
    }
    else
    {
        DRIVE_SPEED = 0.75f;
        TURN_SPEED = 0.4f;
    }
}

void DriveTrain::TankDrive(float left,float right) {
    operation = MANUAL;
    finished = false;
    std::printf("left: %f, right: %f\n",left,right);
    robotDrive -> TankDrive(left,right);
}

void DriveTrain::ArcadeDrive(GenericHID& joystick) {
    operation = MANUAL;
    finished = false;
    robotDrive -> ArcadeDrive(joystick);
}

// calculated assuming robot facing 0deg
// therefore negative angle=turn right, positive angle=turn left
// angle in DEGREES
void DriveTrain::turn(double a) { //a - Degrees
    shift.set(shifter::LOW);
    std::printf("turning\n");
    operation = TURNING;
    //angle*=1.13333333333;
    this -> angle = a;
    double dist = (angle/360.0) * CIRCUMFERENCE;
    left_dist = -dist;
    right_dist = dist;
    encoders.reset_distance();
    finished = false;
}

void DriveTrain::drive(double dist) {
    std::printf("driving\n");
    shift.set(shifter::LOW);
    operation = DRIVING;
    left_dist = dist;
    right_dist = dist;
    encoders.reset_distance();
    finished = false;
}

void DriveTrain::abort() {
    std::printf("aborting\n");
    operation = MANUAL;
    left_dist = right_dist = 0;
    encoders.reset_distance();
    finished = false;
}

double DriveTrain::getDrivingDistance() {
    if(operation != DRIVING) {
        return 0.0;
    }
    return left_dist; // Assuming left_dist==right_dist;
}

double DriveTrain::getTurningAngle() {
    if(operation != TURNING) {
        return 0.0;
    }
    return angle; //Target Angle
}

bool DriveTrain::isManual() {
    return (operation == MANUAL);
}

bool DriveTrain::isTurning() {
    return (operation == TURNING);
}

bool DriveTrain::isDriving() {
    return (operation == DRIVING);
}

bool DriveTrain::isFinished() {
    return finished;
}

void DriveTrain::shiftHigh() {
    shift.set(shifter::HIGH);
}

void DriveTrain::shiftLow() {
    shift.set(shifter::LOW);
}

shifter::GEAR DriveTrain::getGear() {
    return shift.get();
}

void DriveTrain::update() {
    if(operation == MANUAL) {
        return;
    }
    double cur_left_dist = encoders.get_left_dist();
    double cur_right_dist = encoders.get_right_dist();
    float speed = (operation == DRIVING?DriveTrain::DRIVE_SPEED:DriveTrain::TURN_SPEED);
    float left_dir = ((cur_left_dist-left_dist) > 0?1.0f:-1.0f);
    float right_dir = ((cur_right_dist-right_dist) > 0?1.0f:-1.0f);
    float left_speed = 0.0f;
    float right_speed = 0.0f;
    bool left_reached = (std::fabs(cur_left_dist-left_dist) < DriveTrain::DIST_TOLERANCE);
    bool right_reached = (std::fabs(cur_right_dist-right_dist) < DriveTrain::DIST_TOLERANCE);
    if(left_reached && right_reached) {
        robotDrive -> TankDrive(0.0f,0.0f);
        encoders.reset_distance();
        operation = MANUAL;
        finished = true;
        return;
    }
    if(!left_reached) {
        left_speed = left_dir * speed;
    }
    if(!right_reached) {
        right_speed = right_dir * speed;
    }
    robotDrive -> TankDrive(left_speed,right_speed);
}
double torad(double deg) {
    return (deg * (M_PI/180.0));
}

double todeg(double rad) {
    return (rad / (M_PI/180.0));
}

void DriveTrain::update_helper(void* param) {
    ((DriveTrain*)param) -> update();
}
