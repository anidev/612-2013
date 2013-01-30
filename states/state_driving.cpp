#include <Timer.h>
#include "../ports.h"
#include "../auto_encoders.h"
#include "../shifter.h"
#include "../drivetrain.h"
#include "state_driving.h"

void driving_state() {
    if (left_joystick.GetRawButton(1)) {
        drive_train.ArcadeDrive(left_joystick);
    } else {
        float left_axis = left_joystick.GetY ();
        float right_axis = right_joystick.GetY ();
        drive_train.TankDrive(left_axis, right_axis);
    }
}
