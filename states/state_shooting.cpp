#include "state_shooting.h"
#include "../lift.h"           // for lift_up () and lift_down ()
#include "../launcher.h"       // for setSpeed () and getCurrentSpeed()
#include "../612.h"
#include "../drivetrain.h"
#include "../ports.h"
#include "../shooter.h"
#include "../EnhancedJoystick.h"
#include "../AutoShooter.h"
#include "../controls.h"

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
<<<<<<< HEAD
    if (gunner_gamepad.GetRawButton (Gunner_Btn_PresetTwo)) {          // button Y on joystick
=======
    if (gunner_gamepad.GetRawButton (4)) // button Y on joystick
    {
>>>>>>> f3e2d4ff9fb2fdd423b3beee10bff8d87642709b
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
<<<<<<< HEAD
    if (gunner_gamepad.GetRawButton (Gunner_Btn_PresetTwo)) {          // button Y on gamepad
=======
/*    if (gunner_gamepad.GetRawButton (4)) // button Y on gamepad
    {
>>>>>>> f3e2d4ff9fb2fdd423b3beee10bff8d87642709b
        global_state.set_state(SHOOT_AUTO);
        state_changed = true;
        return;
    }*/

    // Lift
    if(gunner_gamepad.GetRawButton(Gunner_Btn_LiftUp))
    {
        angleAdjuster.lift_up();
    }
    else if(gunner_gamepad.GetRawButton(Gunner_Btn_LiftDown))
    {
        angleAdjuster.lift_down();
    }
    else
    {
        angleAdjuster.lift_stop();
    }
    netcom -> lift_angle(angleAdjuster.get_current_angle());

    // Target wheel speed
    if (gunner_gamepad.GetRawAxis(Gunner_Axis_ShooterSpeed) < -0.98f) // slow down shooter wheel
    {
        // save new speed, change speed when buton is not pressed
        if(new_shooter_wheel_speed-WHEEL_CHANGE >= 0.0 && speed_adjust_counter % 3 == 0)
        {
            new_shooter_wheel_speed -= WHEEL_CHANGE;
            speed_changed = true;
        }
        speed_adjust_counter++;
    }
    else if (gunner_gamepad.GetRawAxis(Gunner_Axis_ShooterSpeed) > 0.98f) // speed up shooter wheel
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

<<<<<<< HEAD
    if (gunner_gamepad.GetRawButton(Gunner_Btn_PresetOne)) 
=======
    // Manual shooting
    if (gunner_gamepad.GetRawButton(Gunner_Btn_ShooterRev))
>>>>>>> f3e2d4ff9fb2fdd423b3beee10bff8d87642709b
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
    }
    netcom -> launcher_current_speed(shooter.getCurrentSpeed());

<<<<<<< HEAD
    if(gunner_gamepad.GetRawAxis(Gunner_Axis_Feeder)<-0.98f) // right
    { 
        shooter.setFeederForward();
    }
    else if(gunner_gamepad.GetRawAxis(Gunner_Axis_Feeder)>0.98f) // left
=======
    // Feeder
    // When let go, feeder will continue until it hits hall effect
    if(gunner_gamepad.GetRawAxis(Gunner_Axis_Feeder) < -0.98f) // right
    {
        shooter.setFeederForward();
    }
    else if(gunner_gamepad.GetRawAxis(Gunner_Axis_Feeder) > 0.98f) // left
>>>>>>> f3e2d4ff9fb2fdd423b3beee10bff8d87642709b
    {
        shooter.setFeederBackward();
    }

<<<<<<< HEAD
    if(!driverOperation) {
=======
    // Swivel
    if(!driverOperation)
    {
>>>>>>> f3e2d4ff9fb2fdd423b3beee10bff8d87642709b
        if (gunner_gamepad.GetRawButton (Gunner_Btn_SwivelLeft)) // turn robot left
        {
            drive_train.TankDrive(SHOOT_TURN_SPEED, -SHOOT_TURN_SPEED);
        }
        else if (gunner_gamepad.GetRawButton (Gunner_Btn_SwivelRight)) // turn robot right
<<<<<<< HEAD
        { 
//            std::printf("swivel right\n");
=======
        {
            std::printf("swivel right\n");
>>>>>>> f3e2d4ff9fb2fdd423b3beee10bff8d87642709b
            drive_train.TankDrive(-SHOOT_TURN_SPEED, SHOOT_TURN_SPEED);
        }
        else
        {
            // stop turning
            drive_train.TankDrive(0,0);
        }
    }
}
