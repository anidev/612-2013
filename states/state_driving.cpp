#include <cmath>
#include <Timer.h>
#include "state_driving.h"
#include "../ports.h"
#include "../auto_encoders.h"
#include "../shifter.h"
#include "../drivetrain.h"
#include "../EnhancedJoystick.h"
#include "../controls.h"

const float DRIVE_TURN_SPEED = 0.7f;
const float ARCADE_SPEED = 0.4f;

// 9== select/climbing|10 == start/driving
void driving_state() {
    if (drive_gamepad.GetRawButton(Driver_Btn_ClimbMode))
    {
        global_state.set_state(CLIMBING);
        return;
    }
    drive_train.setScale(1.0);
    do_driving();
}

void do_driving() {
    if(gunner_gamepad.GetRawButton(Gunner_Btn_SwivelLeft)||gunner_gamepad.GetRawButton(Gunner_Btn_SwivelRight)) {
        driverOperation = false;
    }
    else if(!joyzero(drive_gamepad.GetRawAxis(Driver_Axis_TankLeft))||!joyzero(drive_gamepad.GetRawAxis(Driver_Axis_TankRight))) // axis controls
    {
        driverOperation = true;
    }
    else if(drive_gamepad.GetRawButton(Driver_Btn_SwivelLeft)||drive_gamepad.GetRawButton(Driver_Btn_SwivelRight))
    {
        driverOperation = true;
    }
    else if(!joyzero(drive_gamepad.GetRawAxis(Driver_Axis_Arcade))) // arcade drive
    {
        driverOperation = true;
    }
    else
    {
        driverOperation = false;
    }
    if(driverOperation)
    {
        // swiveling
        if (drive_gamepad.GetRawButton(Driver_Btn_SwivelLeft))
        {
            drive_train.TankDrive(-DRIVE_TURN_SPEED,DRIVE_TURN_SPEED);
            return;
        }
        else if(drive_gamepad.GetRawButton(Driver_Btn_SwivelRight))
        {
            drive_train.TankDrive(DRIVE_TURN_SPEED,-DRIVE_TURN_SPEED);
            return;
        }

        float arcade_y = drive_gamepad.GetRawAxis(Driver_Axis_Arcade);
        if(!joyzero(arcade_y)) {
            drive_train.TankDrive(arcade_y*ARCADE_SPEED,arcade_y*ARCADE_SPEED);
            return;
        }

        // driving
        float left_axis = drive_gamepad.GetRawAxis(Driver_Axis_TankLeft);
        float right_axis = drive_gamepad.GetRawAxis(Driver_Axis_TankRight);
        if (joyzero(left_axis) && joyzero(right_axis)) {
            drive_train.TankDrive(0, 0);
        }
        else
        {
            drive_train.TankDrive(left_axis, right_axis);
        }
    }
}
