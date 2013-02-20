#include "state_climbing.h"
#include "state_driving.h"
#include "../ports.h"
#include "../auto_encoders.h"
#include "../drivetrain.h"
#include "../EnhancedJoystick.h"
#include "../lift.h"
#include "../shifter.h"

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
<<<<<<< HEAD
    drive_train.shiftLow();
    drive_train.setScale(0.2);
=======
    drive_train.setScale(CLIMBING_SPEED);
>>>>>>> 6a3421139bfc87260c2107978c087ce5dd6785f3
    do_driving();
}
