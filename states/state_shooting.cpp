#include <Joystick.h>       // for GetRawButton () and GetRawAxis ()
#include "state_shooting.h"
#include "../lift.h"           // for lift_up () and lift_down ()
#include "../launcher.h"       // for setSpeed () and getCurrentSpeed()
#include "../612.h"
#include "../drivetrain.h"
#include "../ports.h"
#include "../shooter.h"
#include "../launcher.h"
#include "../EnhancedJoystick.h"

double new_shooter_wheel_speed=55.0; // decrease by 0.1 or 0.2
bool is_turning;
bool speed_set=false;
bool speed_changed=false;
const float TURN_SPEED=0.6f;
const float WHEEL_CHANGE=1.0f;

void shooting_auto() {
    if (left_joystick.GetRawButton (1)) {     // button Y on joystick
        // manual revision
        global_state.set_state(DRIVE);
        return;
    }
}

void shooting_manual() {
    if (left_joystick.GetRawButton (1)) {             // button Y on joystick
        global_state.set_state(SHOOT_AUTO);
        return;
    }

    float angle_axis=right_joystick.GetY();
    if(joyzero(angle_axis)) {
        angleAdjuster.lift_stop();
    }
    else
    {
        if(angle_axis>0) {
            std::printf("angle up %f\n",angleAdjuster.get_current_angle());
            angleAdjuster.lift_up();
        }
        else
        {
            std::printf("angle down to %f\n",angleAdjuster.get_current_angle());
            angleAdjuster.lift_down();
        }
    }

    float launcher_axis=(left_joystick.GetZ()/2.0+0.5)*Launcher::MAX;
    if (gunner_joystick.GetRawButton (5)) {             // slow down shooter wheel
        // save new speed, change speed when buton is not pressed
        if(new_shooter_wheel_speed-0.2>=0.0) {
            std::printf("launcher slowed to %f\n",new_shooter_wheel_speed);
            new_shooter_wheel_speed -= WHEEL_CHANGE;
            speed_changed = true;
        }
    }

    if (gunner_joystick.GetRawButton (6)) {             // speed up shooter wheel
        std::printf("launcher sped up to %f\n",new_shooter_wheel_speed);
        new_shooter_wheel_speed += WHEEL_CHANGE;
        speed_changed = true;
    }

    if (gunner_joystick.GetRawButton (1)) {
        if(!speed_set||speed_changed) {
            std::printf("launcher set to %f\n",new_shooter_wheel_speed);
            shooter.setSpeed (new_shooter_wheel_speed);
            speed_set=true;
            speed_changed=false;
        }
        std::printf("launcher speed: %f\n",shooter.getCurrentSpeed());
    }
    else {
        if(speed_set) {
            std::printf("launcher stopped\n");
            shooter.stopLauncher();
            speed_set=false;
        }
    }

    if(!driverOperation) {
        if (gunner_joystick.GetRawButton (7)) {             // turn robot left
            std::printf("swivel left\n");
            drive_train.TankDrive(TURN_SPEED, -TURN_SPEED);
            is_turning = true;
        }
        else if (gunner_joystick.GetRawButton (8)) {             // turn robot right
            std::printf("swivel right\n");
            drive_train.TankDrive(-TURN_SPEED, TURN_SPEED);
            is_turning = true;
        }
        else
        {
            if (is_turning) {
                // stop turning
                drive_train.TankDrive(0, 0);
                is_turning = false;
            }
        }
    }
}
