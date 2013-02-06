//amusement
#include "AutoShooter.h"
#include "shooter.h"
#include "612.h"

AutoShooter::AutoShooter(Shooter* s) {
    updateRegistry.addUpdateFunction(&update_helper, (void*)this);
    cur_state = OFF;
    shooter = s;
}
AutoShooter::~AutoShooter() {
    delete shooter;
}
bool AutoShooter::isAimed() {
    // check with vision if we are done
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
            doAngleSetting();
        break;
        case SHOOTING:
        break;
        case DONE:
        break;
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
