#include "presets.h"
#include "lift.h"
#include "AutoShooter.h"
#include "launcher.h"
#include "shooter.h"

presets::presets(float angle, int speed) {
     lift_angle = angle;
     wheel_speed = speed;
}
presets::~presets() {
    
}
float presets::get_pre_lift(){
    return lift_angle;
}
int presets::get_pre_speed(){
    return wheel_speed;
}

/*
bool presets::shootAgain(){
    if (isFinished){
         return true;
    }
    else{
        return false;
    }
}
*/
void presets::set_lift_angle(float angle) {
    lift_angle = angle;
}
void presets::set_wheel_speed(int speed){
    wheel_speed = speed;
}
void presets::check_presets() {
    isAtAngle = false;
    isAtSpeed = false;
    while (!(isAtAngle) && !(isAtSpeed)){
        if ((angleAdjuster.get_current_angle() != lift_angle)){
            angleAdjuster.set_angle(lift_angle);
            angleAdjuster.lift_stop();
            isFinished = false;
        } else {
            isAtAngle = true;
        }
        if (!(shooter.getCurrentSpeed() == wheel_speed)){
            shooter.setSpeed(wheel_speed);
            isFinished = false;
        } else {
            isAtSpeed = true;
        }
    }
}
void presets::pre_update(){
    while (!(isFinished == true)){
        if (!(isAtSpeed == true) && !(isAtAngle == true)){
            check_presets();
        }
        else {
            isFinished = true;
        }
    }
}
void presets::prep_shoot(){
    if (isFinished == false){
        pre_update();
    }
    else {
        shooter.shoot();
    }
}
void presets::pre_abort(){
    shooter.abort();  // uses shooter.h's own abort method, everything else is stopped and isFinished set to false
    angleAdjuster.lift_stop();
    isFinished = false;
}
/*
To-Do-List for Presets: Suggestions from Adrian
    @ if the joystick configs change, then some of my methods may need to be changed
    @ might need to enable shooter/shooterAim/launcher to access the preset method(s)
    @ PURPOSE: this file is meant to check to make sure that lift angle is correct,
               wheel speed is at the desired rpm, and that the process is complete to shoot
    @ shootAgain is supposed to stop the launcher from shooting again (I think)
      anirudh should check, otherwise it is commented out
    @ To anyone with working git: check if this code can compile, otherwise send a pull request
*/

