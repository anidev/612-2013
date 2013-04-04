#include <cstdio>
#include <Relay.h>
#include <networktables/NetworkTable.h>
#include "vision.h"
#include "main.h"

NetworkTable* robot_class::mainTable=NULL;

robot_class::robot_class():left_front(2,2),
                           left_rear(2,3),
                           right_front(1,3),
                           right_rear(1,4),
                           drive(left_front,left_rear,right_front,right_rear),
                           controller1(1),
                           controller2(2)
{
}

robot_class::~robot_class() {
}

void robot_class::RobotInit() {
}

void robot_class::DisabledInit() {
    drive.TankDrive(0,0);
}

void robot_class::AutonomousInit(); {
    drive.TankDrive(0,0);
}

void robot_class::TeleopInit() {
    drive.TankDrive(0,0);
}

void robot_class::DisabledPeriodic() {
}

void robot_class::AutonomousPeriodic() {
}

void robot_class::TeleopPeriodic() {
#ifdef JOYSTICK
    float left=controller1.GetY();
    float right=controller2.GetY();
#else
    float left=controller1.GetRawAxis(2);
    float right=controller1.GetRawAxis(4);
#endif
    drive.TankDrive(left,right);
}

START_ROBOT_CLASS(robot_class)
