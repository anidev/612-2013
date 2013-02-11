//amusement
#include "AutoShooter.h"
#include "shooter.h"
#include "612.h"
#include "ports.h"
#include "lift.h"
#include "driveTrain.h"

AutoShooter::AutoShooter(Shooter* s) {
    updateRegistry.addUpdateFunction(&update_helper, (void*)this);
    gunner_joystick.addBtn(4,&toggle_helper,(void*)this);
    done = false;
    cur_state = OFF;
    shooter = s;
    targetShotCount = 0;
    shooter -> resetFrisbeeCount();
}
AutoShooter::~AutoShooter() {
    delete shooter;
}
bool AutoShooter::isAimed() {
    setCurrentTarget();
    if(currentTarget.angleOffset > ANGLE_TOLERANCE) 
    {
        return false;
    }
    if((fabs(currentTarget.liftAngle - angleAdjuster.get_target_angle()) > LIFT_TOLERANCE) || !angleAdjuster.at_angle())
    {
        return false;
    }
    return true;
}
void AutoShooter::update() {
    switch(cur_state)
    {
        case OFF:
            break;
        case VISION:
            setCurrentTarget();
            cur_state = SETTING;
            break;
        case SETTING:
            doSetting();
            cur_state = WAITING;
            break;
        case WAITING:
            if(angleAdjuster.at_angle() && drive_train.isFinished())
            {
                if(isAimed())
                {
                    cur_state = SHOOTING;
                }
            }   
            break;
        case SHOOTING:
            doShooting();
            break;
    }
}
void AutoShooter::setCurrentTarget(){
    currentTarget = getReality(angleAdjuster.get_current_angle());
}
void AutoShooter::doSetting(){
    angleAdjuster.set_angle(currentTarget.liftAngle);
    switch (currentTarget.direction) {
        case LEFT:
            drive_train.turn(currentTarget.angleOffset);
            break;
        case RIGHT:
            drive_train.turn((-1.0 * currentTarget.angleOffset));
            break;
        case DONT_TURN:
            drive_train.turn(0);
            break;
    };
}
void AutoShooter::doShooting() {
    if((shooter -> getFrisbeeCount()) >= targetShotCount)
        cur_state = DONE;
    else
    {
        shooter -> shoot();
    }
}
void AutoShooter::update_helper(void* obj) {
    ((AutoShooter*)(obj)) -> update();
}
void AutoShooter::AutoShoot(int target) {
    if(cur_state == OFF)
    {
        shooter -> resetFrisbeeCount();
        cur_state = VISION;
        targetShotCount = target;
    }
}
bool AutoShooter::doneShooting() {
    return done;
}
bool AutoShooter::isShooting() {
    return cur_state != OFF;
}
void AutoShooter::abort() {
    shooter -> abort();
    cur_state = OFF;
}
void AutoShooter::toggle_helper(void* obj) {
    AutoShooter* autoShoot=(AutoShooter*)obj;
    if(autoShoot->isShooting()) {
        autoShoot->abort();
    }
    else
    {
        autoShoot->AutoShoot();
    }
}
