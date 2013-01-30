#include "state_climbing.h"
#include "state_shooting.h"
#include <Joystick.h>           // for GetRawButton ()

void shooting_auto() {
    // TODO
}

void shooting_manual() {
    if (GetRawButton (1)) {     // X
        // unreadable in pdf file
    }
    if (GetRawButton (4)) {     // Y
        auto_shoot ();
    }
    if (GetRawButton ()) {      // angle up
        lift_up();
    }
    if (GetRawButton ()) {      // angle down
        lift_down();
    }
}
