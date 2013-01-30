#if 0
#include "shooter.h"
#include "612.h"
#include "ports.h"

Shooter::Shooter(hw_info launchInfo,hw_info feedInfo) : launch(launchInfo), feed(feedInfo)
{
    gunner_joystick.addBtn(4,&shotBtnHelper,(void*)this);
    shooting = false;
    updateRegistry.addUpdateFunction(&update_helper, (void*)this);
}

Shooter::~Shooter() {
}

void Shooter::getFeederDirection(){
    return direction_t1;
}
void Shooter::setFeederForward() {
    feed.forward();
}
void Shooter::setFeederBackward(){
    feed.backward();
}
void Shooter::setFeederStop(){
    feed.stop();
}

void Shooter::update() {
    if(shooting)
    {
        curCount = launch.getFrisbeeCount;
        if(startCount < curCount)
        {
            if(launch.atSpeed()) {
                feed.forward();
            }
            else
            {
                feed.stop();
            }
        }
        else
        {
            shooting = false;
        }
    }
}
void Shooter::shoot() {
    shooting = true;
    startCount = launch.getFrisbeeCount;
}
void Shooter::update_helper(void* a) {
    ((Shooter*)a) -> update();
}
void Shooter::shotBtnHelper(void* obj) {
    ((Shooter*)obj) -> shoot;
}
#endif
