#include "state_climbing.h"
#include "state_driving.h"
#include "../ports.h"
#include "../auto_encoders.h"
#include "../drivetrain.h"
#include "../EnhancedJoystick.h"
#include "../lift.h"

float CLIMBING_SPEED = 0.55f;
// 9== select/climbing|10 == start/driving
void climbing_state ()
{
    if (drive_gamepad.GetRawButton(10))
    {
        global_state.set_state(DRIVE);
        return;
    }
    angleAdjuster.lift_down();
    drive_train.setScale(CLIMBING_SPEED);
    do_driving();
}
