#if 0
#include "AutoShooter.h"
#include "shooter.h"
#include "612.h"

AutoShooter::AutoShooter(Shooter* s) {
    updateRegistry.addUpdateFunction(&update_helper, (void*)this);
    //Add Abort Btn Here
    cur_state = OFF;
    shooter = s;
}
AutoShooter::~AutoShooter() {
    delete shooter;
}
bool AutoShooter::isAimed() {
    // check with vision if we are done
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
            doAngleSetting();
        break;
        case SHOOTING:
            doShooting();
        break;
        case DONE:
        break
    }
}

void AutoShooter::doVision(){
    
}
void AutoShooter::doHorizontalAlign() {
    
}
void AutoShooter::doAngleSetting() {
    
}
void AutoShooter::doShooting() {
    if((shooter -> getFrisbeeCount())>=4)
        cur_state = DONE;
    else
    {
        shooter -> shoot();
    }
}
void AutoShooter::update_helper(void* obj) {
    ((AutoShooter*)(obj)) -> update();
}
void AutoShooter::AutoShoot() {
    if(cur_state == OFF)
        cur_state = VISION;
}
void AutoShooter::StopAutoShoot() {
    cur_state = OFF;
}
bool AutoShooter::doneShooting() {
    if(cur_state == DONE)
        return true;
    return false;
}
void AutoShooter::abort_helper(void* o) {
    ((AutoShooter*)(o)) -> abort();
}
void AutoShooter::abort() {
    shooter -> abort();
    cur_state = OFF;
}
#endif
