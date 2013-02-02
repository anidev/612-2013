#include "state_climbing.h"
#include "state_shooting.h"
#include "../lift.h"           // for lift_up () and lift_down ()
#include "../launcher.h"       // for setSpeed () and getCurrentSpeed()
#include <Joystick.h>       // for GetRawButton () and GetRawAxis ()
#include "../612.h"
#include "../drivetrain.h"
#include "../ports.h"
#include "../shooter.h"

double new_shooter_wheel_speed; // decrease by 0.1 or 0.2
bool is_turning;

void shooting_auto() {
    if (gunner_joystick.GetRawButton (4)) {     // button Y on joystick
        // manual revision
        global_state.set_state(DRIVE);
        return;
    }
}

void shooting_manual() {
    if (gunner_joystick.GetRawButton (4)) {             // button Y on joystick
        global_state.set_state(SHOOT_AUTO);
        return;
    }

    if (gunner_joystick.GetRawAxis (5) == -1) {         // angle down
        angleAdjuster.lift_down();
    }
    else if(gunner_joystick.GetRawAxis (5) == 1) {      // angle up
        angleAdjuster.lift_up();
    }

    if (gunner_joystick.GetRawButton(1)) {
        shooter.setSpeed (new_shooter_wheel_speed);
    }
    else {
        shooter.abort();
    }

    if (gunner_joystick.GetRawButton (5)) {             // slow down shooter wheel
        // save new speed, change speed when buton is not pressed
        new_shooter_wheel_speed -= 0.2;
    }

    if (gunner_joystick.GetRawButton (6)) {             // speed up shooter wheel
        new_shooter_wheel_speed += 0.2;
    }

    if (gunner_joystick.GetRawButton (7)) {             // turn robot left
        drive_train.TankDrive(-.2, .2);
        is_turning = true;
    }
    else if (gunner_joystick.GetRawButton (8)) {             // turn robot right
        drive_train.TankDrive(.2, -.2);
        is_turning = true;
    }
    else
    {
        if (is_turning) {
            // stop turning
            drive_train.TankDrive(0, 0);
        }
    }
}
