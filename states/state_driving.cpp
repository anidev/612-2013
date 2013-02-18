#include <cmath>
#include <Timer.h>
#include "state_driving.h"
#include "../ports.h"
#include "../auto_encoders.h"
#include "../shifter.h"
#include "../drivetrain.h"
#include "../EnhancedJoystick.h"

const float DRIVE_TURN_SPEED = 0.6f;
void driver_check_update(void* dummy) {
    if(!joyzero(drive_gamepad.GetRawAxis(2))||!joyzero(drive_gamepad.GetRawAxis(4))) { // axis controls
        driverOperation = true;
        return;
    }
    if(drive_gamepad.GetRawButton(7)||drive_gamepad.GetRawButton(8)) {
        driverOperation = true;
        return;
    }
    driverOperation = false;
}

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
