#ifndef ENHANCED_ROBOT_DRIVE_H
#define ENHANCED_ROBOT_DRIVE_H

#include <RobotDrive.h>
#include <SpeedController.h>
#include <Servo.h>
#include "EnhancedJoystick.h"
class EnhancedRobotDrive : public RobotDrive {
public:
    static const float DRIVE_TURN_SPEED = 0.7f;
    static const unsigned int DRIVER_LEFT_DRIVE_AXIS  = 2;
    static const unsigned int DRIVER_RIGHT_DRIVE_AXIS = 4;
    static const unsigned int DRIVER_SWIVLE_RIGHT = 8;
    static const unsigned int DRIVER_SWIVLE_LEFT  = 7;
    static const unsigned int GUNNER_SWIVLE_RIGHT = 8;
    static const unsigned int GUNNER_SWIVLE_LEFT  = 7;
    static const unsigned int DRIVER_SHIFT_LOW = 5;
    static const unsigned int DRIVER_SHIFT_HIGH = 6;
    EnhancedRobotDrive(SpeedController*,SpeedController*,SpeedController*,SpeedController*,void*);
    ~EnhancedRobotDrive();
    void doControls();
    static void disable(void*);
    static void shiftLowGear(void*);
    static void shiftHighGear(void*);
private:                            // Low  High  
    Servo rightShifter;
    Servo leftShifter;
    enum dir {
        LEFT,
        RIGHT
    };
    void swivle(dir);
    EnhancedJoystick* driver;
    EnhancedJoystick* gunner;
};
#endif
