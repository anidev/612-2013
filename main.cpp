#include "main.h"
#include "Controls.h"

const float LOWGEAR=0.8f;
const float HIGHGEAR=0.2f;

robot_class::robot_class():left_front(2,2),
                           left_rear(2,3),
                           right_front(1,3),
                           right_rear(1,4),
                           drive(left_front,left_rear,right_front,right_rear),
                           controller1(1),
                           controller2(2),
                           shift_left(1,6),
                           shift_right(2,4)
{
}

robot_class::~robot_class() {
}

void robot_class::RobotInit() {
    shift_left.Set(LOWGEAR);
    shift_right.Set(LOWGEAR);
}

void robot_class::DisabledInit() {
    drive.TankDrive(0.0f,0.0f);
}

void robot_class::AutonomousInit() {
    drive.TankDrive(0.0f,0.0f);
}

void robot_class::TeleopInit() {
    drive.TankDrive(0.0f,0.0f);
}

void robot_class::DisabledPeriodic() {
}

void robot_class::AutonomousPeriodic() {
}

void robot_class::TeleopPeriodic() {
    bool shiftLow=false;
    bool shiftHigh=false;
#ifdef JOYSTICK
    float left=controller1.GetY();
    float right=controller2.GetY();
#else
    float left=controller1.GetRawAxis(DRIVER_LEFT_DRIVE_AXIS);
    float right=controller1.GetRawAxis(DRIVER_RIGHT_DRIVE_AXIS);
    if(controller1.GetRawButton(DRIVER_SHIFT_LOW)) {
        shiftLow=true;
    } else if(controller1.GetRawButton(DRIVER_SHIFT_HIGH)) {
        shiftHigh=true;
    }
#endif
    drive.TankDrive(left,right);
    if(shiftLow) {
        shift_left.Set(LOWGEAR);
        shift_right.Set(LOWGEAR);
    } else if(shiftHigh) {
        shift_left.Set(HIGHGEAR);
        shift_right.Set(HIGHGEAR);
    }
}

START_ROBOT_CLASS(robot_class)
