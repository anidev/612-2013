#include <cmath>
#include <Timer.h>
#include "state_driving.h"
#include "../ports.h"
#include "../auto_encoders.h"
#include "../shifter.h"
#include "../drivetrain.h"
#include "../EnhancedJoystick.h"
#include "../612.h"

void driving_state() {
    if(driverOperation) {
        if (left_joystick.GetRawButton(1)) {
            drive_train.ArcadeDrive(left_joystick);
        } else {
            float left_axis = left_joystick.GetRawAxis(2);
            float right_axis = right_joystick.GetRawAxis(4);
            if (joyzero(left_axis) && joyzero(right_axis)) {
                drive_train.TankDrive(left_axis, right_axis);
            } else {
                drive_train.TankDrive(0, 0);
            }    
        }
    }
}
