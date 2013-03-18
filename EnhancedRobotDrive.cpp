#include <cmath>
#include <RobotDrive.h>
#include "EnhancedRobotDrive.h"
#include "main.h"

EnhancedRobotDrive::EnhancedRobotDrive(SpeedController* a,SpeedController* b,SpeedController* c,SpeedController* d,void* o):
        RobotDrive(a,b,c,d),
        rightShifter(2,6),
        leftShifter(2,5) 
{
    robot_class* robot = (robot_class*)o;
    driver = &(robot -> drive_gamepad);
    gunner = &(robot -> gunner_gamepad);
    driver -> addBtn(DRIVER_SHIFT_LOW,&shiftLowGear,(void*)this);
    driver -> addBtn(DRIVER_SHIFT_HIGH,&shiftHighGear,(void*)this);
    robot -> disableRegistry.addUpdateFunction(&disable,(void*)this);
}
EnhancedRobotDrive::~EnhancedRobotDrive() {
    
}
void EnhancedRobotDrive::doControls() {
    if((std::fabs(driver -> GetRawAxis(DRIVER_LEFT_DRIVE_AXIS)) > EnhancedJoystick::JOYSTICK_ZERO_TOLERANCE) || (std::fabs(driver -> GetRawAxis(DRIVER_RIGHT_DRIVE_AXIS)) > EnhancedJoystick::JOYSTICK_ZERO_TOLERANCE))
    {
        //Skyler Driving
        TankDrive(driver -> GetRawAxis(DRIVER_LEFT_DRIVE_AXIS),driver -> GetRawAxis(DRIVER_RIGHT_DRIVE_AXIS));
    }
    else if(gunner -> GetRawButton(GUNNER_SWIVLE_RIGHT) || gunner -> GetRawButton(GUNNER_SWIVLE_LEFT))
    {
        //Ben Swivle
        if(gunner -> GetRawButton(GUNNER_SWIVLE_RIGHT))
        {
            swivle(RIGHT);
        }
        else
        {
            swivle(LEFT);
        }
    }
    else if(driver -> GetRawButton(DRIVER_SWIVLE_RIGHT) || driver -> GetRawButton(DRIVER_SWIVLE_LEFT))
    {
        //Skyler Swivle
        if(driver -> GetRawButton(DRIVER_SWIVLE_RIGHT))
        {
            swivle(RIGHT);
        }
        else
        {
            swivle(LEFT);
        }
    }
    else
        TankDrive(0.0f,0.0f);
}

void EnhancedRobotDrive::swivle(dir d) {
    if(d == LEFT)
        TankDrive(DRIVE_TURN_SPEED,-1.0 * DRIVE_TURN_SPEED);
    else
        TankDrive(-1.0 *DRIVE_TURN_SPEED,DRIVE_TURN_SPEED);
}
void EnhancedRobotDrive::disable(void* o) {
    ((EnhancedRobotDrive*)o) -> TankDrive(0.0f,0.0f);   
}
void EnhancedRobotDrive::shiftLowGear(void* o) {
    static const float kleftgear[]  = {0.8, 0.2};
    static const float krightgear[] = {0.2, 0.8};
    (((EnhancedRobotDrive*)o) -> leftShifter).Set(kleftgear[0]);
    (((EnhancedRobotDrive*)o) -> rightShifter).Set(krightgear[0]);
}
void EnhancedRobotDrive::shiftHighGear(void* o) {
    static const float kleftgear[]  = {0.8, 0.2};
    static const float krightgear[] = {0.2, 0.8};
    (((EnhancedRobotDrive*)o) -> leftShifter).Set(kleftgear[1]);
    (((EnhancedRobotDrive*)o) -> rightShifter).Set(krightgear[1]);
}
