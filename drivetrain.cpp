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
    if(drivetrain->operation==MANUAL) {
        return;
    }
    double cur_left_dist=drivetrain->encoders.get_left_dist();
    double cur_right_dist=drivetrain->encoders.get_right_dist();
    float speed=(drivetrain->operation==DRIVING?DriveTrain::DRIVE_SPEED:DriveTrain::TURN_SPEED);
    float left_dir=((cur_left_dist-drivetrain->left_dist)>0?1.0f:-1.0f);
    float right_dir=((cur_right_dist-drivetrain->right_dist)>0?1.0f:-1.0f);
    float left_speed=0.0f;
    float right_speed=0.0f;
    if(std::fabs(cur_left_dist-drivetrain->left_dist)>DriveTrain::DIST_TOLERANCE) {
        left_speed=left_dir*speed;
    }
    if(std::fabs(cur_right_dist-drivetrain->right_dist)>DriveTrain::DIST_TOLERANCE) {
        right_speed=right_dir*speed;
    }
    drivetrain->robotDrive->TankDrive(left_speed,right_speed);
}

DriveTrain::DriveTrain(drivetrain_info dinfo,encoders_info einfo):encoders(einfo) {
    Jaguar left_front_jag(dinfo.left_front.moduleNumber,dinfo.left_front.channel);
    Jaguar left_rear_jag(dinfo.left_rear.moduleNumber,dinfo.left_rear.channel);
    Jaguar right_front_jag(dinfo.right_front.moduleNumber,dinfo.right_front.channel);
    Jaguar right_rear_jag(dinfo.right_rear.moduleNumber,dinfo.right_rear.channel);
    robotDrive=new RobotDrive(left_front_jag,left_rear_jag,right_front_jag,right_rear_jag);
    encoders.reset_distance();
    finished=false;
    updateRegistry.addUpdateFunction(update_helper,(void*)this);
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
    operation=TURNING;
    this->angle=angle;
    double dist=0.0; // TODO angle distance calculation
    left_dist=dist;
    right_dist=-dist;
    encoders.reset_distance();
    finished=false;
}

void DriveTrain::drive(double dist) {
    operation=DRIVING;
    left_dist=right_dist=dist;
    encoders.reset_distance();
    finished=false;
}

void DriveTrain::abort() {
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
