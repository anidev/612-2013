#include "state_climbing.h"
#include "state_shooting.h"
#include "lift.h"           // for lift_up () and lift_down ()
#include "launcher.h"       // for setSpeed () and getCurrentSpeed()
#include <Joystick.h>       // for GetRawButton () and GetRawAxis ()

void shooting_auto() {
    if (GetRawButton (1)) {     // button X on joystick
        // manual revision
        shooting_manual();
    }
}

void shooting_manual() {
    if (GetRawButton (4)) {             // button Y on joystick
        shooting_auto ();
    }

    if (GetRawAxis (5) == -1) {         // angle down
        lift_down();
    }
    else if(GetRawAxis (5) == 1) {      // angle up
        lift_up();
    }

    if (GetRawButton (5)) {             // slow down shooter wheel
        setSpeed (getCurrentSpeed()--);
    }
    if (GetRawButton (6)) {             // speed up shooter wheel
        setSpeed (getCurrentSpeed()++);
    }

    if (GetRawButton (7)) {             // turn robot left
        // TO DO
    }
    if (GetRawButton (8)) {             // turn robot right
        // TO DO
    }
}
