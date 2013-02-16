#include <cmath>
#include <Timer.h>
#include "state_driving.h"
#include "../ports.h"
#include "../auto_encoders.h"
#include "../shifter.h"
#include "../drivetrain.h"
#include "../EnhancedJoystick.h"

void driving_state() {
    if(driverOperation) {
        if (left_joystick.GetRawButton(1)) {
            drive_train.ArcadeDrive(left_joystick);
        } else {
            float left_axis = left_joystick.GetRawAxis(2);
            float right_axis = right_joystick.GetRawAxis(4);
            drive_train.TankDrive(left_axis, right_axis);
        }
    }
}
