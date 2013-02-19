#include "state_climbing.h"
#include "../ports.h"
#include "../auto_encoders.h"
#include "../drivetrain.h"
#include "../EnhancedJoystick.h"

float CLIMBING_SPEED = 0.2f;
// 9== select/climbing|10 == start/driving
void climbing_state () 
{
    if (drive_gamepad.GetRawButton(10))    
    {
        global_state.set_state(DRIVE);
        drive_train.Scale();
    }
}
