#include "shooter.h"
#include "launcher.h"
#include "feeder.h"
#include "612.h"
#include "ports.h"

Shooter::Shooter(hw_info launchWheel,hw_info launchSensor,hw_info feedInfo) : launch(launchWheel,launchSensor), feed(feedInfo)
{
    gunner_joystick.addBtn(4,&shotBtnHelper,(void*)this);
    shooting = false;
    updateRegistry.addUpdateFunction(&update_helper, (void*)this);
}

Shooter::~Shooter() {s
}

// Launcher

void Shooter::setSpeed(float target) {
    launch.setSpeed(target);
}

float Shooter::getTargetSpeed() {
    return launch.getTargetSpeed();
}

float Shooter::getCurrentSpeed() {
    return launch.getCurrentSpeed();
}

bool Shooter::atSpeed() {
    return launch.atSpeed();
}

unsigned int Shooter::getFrisbeeCount() {
    return launch.getFrisbeeCount();
}

void Shooter::resetFrisbeeCount() {
    launch.resetFrisbeeCount();
}

// Feeder

Feeder::direction_t Shooter::getFeederDirection(){
    return feed.getDirection();
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

// Global shooter stuff

void Shooter::update() {
    if(shooting)
    {
        curCount = launch.getFrisbeeCount();
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
// toggle shooting
void Shooter::shoot() {
    if(shooting) {
        abort();
        return;
    }
    shooting=true;
    startCount = launch.getFrisbeeCount();
}

void Shooter::abort() {
    launch.stop();
    feed.stop();
    shooting=false;
}
void Shooter::update_helper(void* a) {
    ((Shooter*)a) -> update();
}
void Shooter::shotBtnHelper(void* obj) {
    ((Shooter*)obj) -> shoot();
}

bool Shooter:isShooting(){
    return shooting;
}
