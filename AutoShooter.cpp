//amusement
#include "AutoShooter.h"
#include "shooter.h"
#include "612.h"

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
    // check with vision if we are done
    //Todo Finish This
    return true;
}
void AutoShooter::update() {
    switch(cur_state)
    {
        case OFF:
            break;
        case VISION:
            break;
        case HORIZONTAL:
            break;
        case ANGLE_SETTING:
            if(isAimed())
            {
                cur_state = SHOOTING;
            }
            else
            {
                doAngleSetting();
            }
            break;
        case SHOOTING:
            doShooting();
            break;
    }
}

void AutoShooter::doVision(){
    
}
void AutoShooter::doHorizontalAlign() {
    
}
void AutoShooter::doAngleSetting() {
    
}
void AutoShooter::doShooting() {
    if((shooter -> getFrisbeeCount())>=targetShotCount)
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
