#include "state_climbing.h"
#include "state_driving.h"
#include "../ports.h"
#include "../auto_encoders.h"
#include "../drivetrain.h"
#include "../EnhancedJoystick.h"
#include "../lift.h"
#include "../shifter.h"
#include "../controls.h"

float CLIMBING_SPEED = 0.6f;
// 9== select/climbing|10 == start/driving
void climbing_state ()
{
    if (drive_gamepad.GetRawButton(Driver_Btn_NormalMode))
    {
        global_state.set_state(DRIVE);
        return;
    }
    angleAdjuster.lift_down();
    drive_train.setScale(CLIMBING_SPEED);
    do_driving();
}
