//amusement
#include "AutoShooter.h"
#include "shooter.h"
#include "612.h"

AutoShooter::AutoShooter(Shooter* s) {
    updateRegistry.addUpdateFunction(&update_helper, (void*)this);
    //Add Abort Btn Here
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
        case DONE:
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
void AutoShooter::AutoShoot(int target = MAX_FRISBEE_COUNT) {
    if(cur_state == OFF)
    {
        shooter -> resetFrisbeeCount();
        cur_state = VISION;
        targetShotCount = target;
    }
}
void AutoShooter::StopAutoShoot() {
    cur_state = OFF;
}
bool AutoShooter::doneShooting() {
    if(cur_state == DONE)
        return true;
    return false;
}
void AutoShooter::toggle_helper(void* o) {
    if(((AutoShooter*)o) -> cur_state == OFF)
    {
        ((AutoShooter*)(o)) -> AutoShoot();
    }
    else
    {
        ((AutoShooter*)(o)) -> abort();
    }
}
void AutoShooter::abort() {
    shooter -> abort();
    cur_state = OFF;
}
