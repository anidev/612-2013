#include <RobotDrive.h>
#include "../ports.h"
#include "../auto_encoders.h"
#include "state_driving.h"

void driving_state() {
    float left_axis = left_joystick.GetY ();
    float right_axis = right_joystick.GetY ();
    if (left_joystick.GetRawButton(6)) {
        encoders.reset_distance();
    }
    if (left_joystick.GetRawButton(1)) {
        drive_train.ArcadeDrive(left_joystick);
    } else {
        drive_train.TankDrive(left_axis, right_axis);
    }
}
