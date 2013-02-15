#include "presets.h"
#include "lift.h"
#include "shooter.h"
#include "ports.h"

presets::presets(float angle, int speed) {
     lift_angle = angle;
     wheel_speed = speed;
}
presets::~presets() {
}
void presets::setShooter(Shooter* shooter) {
    shooter->setSpeed((float)wheel_speed);
}
void presets::setLifter(Lift* lifter){
    lifter->set_angle(lift_angle);
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

