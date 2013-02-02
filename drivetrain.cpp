#include <cmath>
#include <Jaguar.h>
#include "612.h"
#include "auto_encoders.h"
#include "drivetrain.h"

double torad(double deg) {
    return deg*(M_PI/180.0);
}

double todeg(double rad) {
    return rad/(M_PI/180.0);
}

void DriveTrain::update_helper(void* param) {
    DriveTrain* drivetrain=(DriveTrain*)param;
    drivetrain->update();
}

DriveTrain::DriveTrain(drivetrain_info dinfo,encoders_info einfo):encoders(einfo) {
    operation=MANUAL;
    left_front_jag=new Jaguar(dinfo.left_front.moduleNumber,dinfo.left_front.channel);
    left_rear_jag=new Jaguar(dinfo.left_rear.moduleNumber,dinfo.left_rear.channel);
    right_front_jag=new Jaguar(dinfo.right_front.moduleNumber,dinfo.right_front.channel);
    right_rear_jag=new Jaguar(dinfo.right_rear.moduleNumber,dinfo.right_rear.channel);
    robotDrive=new RobotDrive(left_front_jag,left_rear_jag,right_front_jag,right_rear_jag);
    robotDrive->SetSafetyEnabled(false);
    encoders.reset_distance();
    finished=false;
    updateRegistry.addUpdateFunction(&update_helper,(void*)this);
}

DriveTrain::~DriveTrain() {
    delete robotDrive;
}

void DriveTrain::TankDrive(float left,float right) {
    operation=MANUAL;
    finished=false;
    robotDrive->TankDrive(left,right);
}

void DriveTrain::ArcadeDrive(GenericHID& joystick) {
    operation=MANUAL;
    finished=false;
    robotDrive->ArcadeDrive(joystick);
}

// calculated assuming robot facing 0deg
// therefore negative angle=turn right, positive angle=turn left
// angle in DEGREES
void DriveTrain::turn(double angle) {
    std::printf("turning\n");
    operation=TURNING;
    this->angle=angle;
    double radAngle=torad(angle);
    double dist=radAngle*16;
    left_dist=-dist;
    right_dist=dist;
    encoders.reset_distance();
    finished=false;
}

void DriveTrain::drive(double dist) {
    std::printf("driving\n");
    operation=DRIVING;
    left_dist=dist;
    right_dist=dist;
    encoders.reset_distance();
    finished=false;
}

void DriveTrain::abort() {
    std::printf("aborting\n");
    operation=MANUAL;
    left_dist=right_dist=0;
    encoders.reset_distance();
    finished=false;
}

double DriveTrain::getDrivingDistance() {
    if(operation!=DRIVING) {
        return 0.0;
    }
    return left_dist; // Assuming left_dist==right_dist;
}

double DriveTrain::getTurningAngle() {
    if(operation!=TURNING) {
        return 0.0;
    }
    return angle;
}

bool DriveTrain::isManual() {
    return operation==MANUAL;
}

bool DriveTrain::isTurning() {
    return operation==TURNING;
}

bool DriveTrain::isDriving() {
    return operation==DRIVING;
}

bool DriveTrain::isFinished() {
    return finished;
}

void DriveTrain::update() {
    static int counter=0;
    std::printf("operation: %d\n",operation);
    if(operation==MANUAL) {
        return;
    }
    double cur_left_dist=encoders.get_left_dist();
    double cur_right_dist=encoders.get_right_dist();
    float speed=(operation==DRIVING?DriveTrain::DRIVE_SPEED:DriveTrain::TURN_SPEED);
    float left_dir=((cur_left_dist-left_dist)>0?1.0f:-1.0f);
    float right_dir=((cur_right_dist-right_dist)>0?1.0f:-1.0f);
    float left_speed=0.0f;
    float right_speed=0.0f;
    bool left_reached=(std::fabs(cur_left_dist-left_dist)<DriveTrain::DIST_TOLERANCE);
    bool right_reached=(std::fabs(cur_right_dist-right_dist)<DriveTrain::DIST_TOLERANCE);
    std::printf("cur_left_dist: %f\n",cur_left_dist);
    std::printf("cur_right_dist: %f\n",cur_right_dist);
    std::printf("left_dir: %f\n",left_dir);
    std::printf("right_dir: %f\n",right_dir);
    if(left_reached&&right_reached) {
        std::printf("tankdrive stopping\n");
        encoders.reset_distance();
        robotDrive->TankDrive(0.0f,0.0f);
        operation=MANUAL;
        finished=true;
        return;
    }
    if(!left_reached) {
        left_speed=left_dir*speed;
    }
    if(!right_reached) {
        right_speed=right_dir*speed;
    }
    std::printf("left_speed: %f\n",left_speed);
    std::printf("right_speed: %f\n",right_speed);
    robotDrive->TankDrive(left_speed,right_speed);
}
