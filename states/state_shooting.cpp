#include "state_shooting.h"
#include "../lift.h"           // for lift_up () and lift_down ()
#include "../launcher.h"       // for setSpeed () and getCurrentSpeed()
#include "../612.h"
#include "../drivetrain.h"
#include "../ports.h"
#include "../shooter.h"
#include "../EnhancedJoystick.h"
#include "../AutoShooter.h"

//Constants
const float SHOOT_TURN_SPEED = 0.7f;
const float WHEEL_CHANGE = 5.0f;

//Global Variables
double new_shooter_wheel_speed = 60.0; // decrease by 0.1 or 0.2
bool is_turning;
bool speed_set = false;
bool speed_changed = false;
bool state_changed = false;
unsigned int speed_adjust_counter = 0;

void shooting_auto() {
    if (gunner_gamepad.GetRawButton (4)) // button Y on joystick
    {
        // manual revision
        auto_shoot.abort();
        global_state.set_state(DRIVE);
        state_changed = true;
        return;
    }
    if(state_changed) 
    {
        auto_shoot.AutoShoot();
        state_changed = false;
    }
}

void shooting_manual() {
    state_changed = false;
    if (gunner_gamepad.GetRawButton (4)) // button Y on gamepad
    {   
        global_state.set_state(SHOOT_AUTO);
        state_changed = true;
        return;
    }
    if(gunner_gamepad.GetRawAxis(6) > 0.98f) 
    {
        angleAdjuster.lift_up();
    }
    else if(gunner_gamepad.GetRawAxis(6) < -0.98f)
    {
        angleAdjuster.lift_down();
    }
    else
    {
        angleAdjuster.lift_stop();
    }
    netcom -> lift_angle(angleAdjuster.get_current_angle());
    if (gunner_gamepad.GetRawButton(5)) // slow down shooter wheel
    {
        // save new speed, change speed when buton is not pressed
        if(new_shooter_wheel_speed-WHEEL_CHANGE >= 0.0 && speed_adjust_counter % 3 == 0)
        {
            new_shooter_wheel_speed -= WHEEL_CHANGE;
            speed_changed = true;
        }
        speed_adjust_counter++;
    }
    else if (gunner_gamepad.GetRawButton (6)) // speed up shooter wheel
    {
        if(new_shooter_wheel_speed+WHEEL_CHANGE <= Launcher::MAX && speed_adjust_counter%3==0)
        {
            new_shooter_wheel_speed += WHEEL_CHANGE;
            speed_changed = true;
        }
        speed_adjust_counter++;
    }
    else
    {
        speed_adjust_counter = 0;
    }
    netcom -> launcher_target_speed(new_shooter_wheel_speed);
    //Todo Fix Below Its Important for VCU
    /*if (gunner_gamepad.GetRawButton(1)) 
    {
        if(!speed_set||speed_changed) 
        {
            shooter.setSpeed (new_shooter_wheel_speed);
            speed_set = true;
            speed_changed = false;
        }
    }
    else 
    {
        if(speed_set) 
        {
            shooter.stopLauncher();
            speed_set = false;
        }
    } This looks like a toggle btn but it will go through to fast for user to let go use
      the enhanced joysticks */
    netcom -> launcher_current_speed(shooter.getCurrentSpeed());
    if(gunner_gamepad.GetRawAxis(5) < -0.98f) // right
    {
        shooter.setFeederForward();
    }
    else if(gunner_gamepad.GetRawAxis(5) > 0.98f) // left
    {
        shooter.setFeederBackward();
    }
    else
    {
        shooter.setFeederStop();
    }
    if(!driverOperation)
    {
        if (gunner_gamepad.GetRawButton (7)) // turn robot left
        {
            drive_train.TankDrive(SHOOT_TURN_SPEED, -SHOOT_TURN_SPEED);
        }
        else if (gunner_gamepad.GetRawButton (8)) // turn robot right
        {
            std::printf("swivel right\n");
            drive_train.TankDrive(-SHOOT_TURN_SPEED, SHOOT_TURN_SPEED);
        }
        else
        {
            // stop turning
            drive_train.TankDrive(0,0);
        }
    }
}
