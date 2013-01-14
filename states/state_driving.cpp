#include <RobotDrive.h>
#include "ports.h"
#include "state_driving.h"

void driving_state() {
    float left_axis = left_joystick.getY ();
    float right_axis = right_joystick.getY ();
    drive_train.TankDrive (left_axis, right_axis);
}
