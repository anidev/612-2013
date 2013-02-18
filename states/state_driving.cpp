#include <cmath>
#include <Timer.h>
#include "state_driving.h"
#include "../ports.h"
#include "../auto_encoders.h"
#include "../shifter.h"
#include "../drivetrain.h"
#include "../EnhancedJoystick.h"

const float DRIVE_TURN_SPEED = 0.6f;
const float ARCADE_SPEED = 0.4f;

void driving_state() {
    //Todo add driver check update here
    if(driverOperation) 
    {
        // swiveling
        if (drive_gamepad.GetRawButton(5))// L1 
        {
            drive_train.TankDrive(-DRIVE_TURN_SPEED,DRIVE_TURN_SPEED);
            return;
        }
        else if(drive_gamepad.GetRawButton(6)) // R1
        {
            drive_train.TankDrive(DRIVE_TURN_SPEED,-DRIVE_TURN_SPEED);
            return;
        }

        float arcade_y=drive_gamepad.GetRawAxis(6);
        if(!joyzero(arcade_y)) {
            drive_train.TankDrive(arcade_y*ARCADE_SPEED,arcade_y*ARCADE_SPEED);
            return;
        }

        // driving
        float left_axis = drive_gamepad.GetRawAxis(2);
        float right_axis = drive_gamepad.GetRawAxis(4);
        if (joyzero(left_axis) && joyzero(right_axis)) {
            drive_train.TankDrive(0, 0);
        }
        else
        {
            drive_train.TankDrive(left_axis, right_axis);
        }
    }
}
