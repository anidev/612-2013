#include <Joystick.h>       // for GetRawButton () and GetRawAxis ()
#include "state_climbing.h"
#include "state_shooting.h"
#include "../lift.h"           // for lift_up () and lift_down ()
#include "../launcher.h"       // for setSpeed () and getCurrentSpeed()
#include "../612.h"
#include "../drivetrain.h"
#include "../ports.h"
#include "../shooter.h"
#include "../EnhancedJoystick.h"

double new_shooter_wheel_speed; // decrease by 0.1 or 0.2
bool is_turning;
bool speed_set=false;

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

    if (gunner_joystick.GetRawAxis (6) > 0.98f) {       // angle down
        std::printf("angle down to %f\n",angleAdjuster.get_current_angle());
        angleAdjuster.lift_down();
    }
    else if(gunner_joystick.GetRawAxis (6) < -0.98f) {  // angle up
        std::printf("angle up\n");
        angleAdjuster.lift_up();
    }
    else
    {
        angleAdjuster.lift_stop();
    }

    if (gunner_joystick.GetRawButton(1)) {
        if(!speed_set) {
            std::printf("launcher set%f\n",angleAdjuster.get_current_angle());
            shooter.setSpeed (new_shooter_wheel_speed);
            speed_set=true;
        }
    }
    else {
        if(speed_set) {
            std::printf("launcher stopped\n");
            shooter.abort();
            speed_set=false;
        }
    }

    if (gunner_joystick.GetRawButton (5)) {             // slow down shooter wheel
        // save new speed, change speed when buton is not pressed
        std::printf("shooter slowed to %f\n",new_shooter_wheel_speed);
        new_shooter_wheel_speed -= 0.2;
    }

    if (gunner_joystick.GetRawButton (6)) {             // speed up shooter wheel
        std::printf("shooter sped up to %f\n",new_shooter_wheel_speed);
        new_shooter_wheel_speed += 0.2;
    }

    if (gunner_joystick.GetRawButton (7)) {             // turn robot left
        std::printf("swivel left\n");
        drive_train.TankDrive(-.2, .2);
        is_turning = true;
    }
    else if (gunner_joystick.GetRawButton (8)) {             // turn robot right
        std::printf("swivel right\n");
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
