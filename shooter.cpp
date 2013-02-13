#include "shooter.h"
#include "launcher.h"
#include "feeder.h"
#include "612.h"
#include "ports.h"

Shooter::Shooter(hw_info launchWheel1,hw_info launchWheel2,hw_info launchSensor,hw_info feedInfo1,hw_info feedInfo2) : launch(launchWheel1,launchWheel2,launchSensor), feed(feedInfo1,feedInfo2)
{
    shooting = false;
    updateRegistry.addUpdateFunction(&update_helper, (void*)this);
}

Shooter::~Shooter() {
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
        if(launch.atSpeed()) {
            feed.forward();
            feedTimer.Start();
            if(feedTimer.Get()>FEEDER_TIMEOUT) {
                // feeder moving but launcher hasn't slowed down for a while
                // meaning no more frisbees
                feedTimer.Stop();
                feed.stop();
                shooting=false;
            }
        }
        else
        {
            feed.stop();
        }
    }
}
void Shooter::shoot(double launchSpeed) {
    if(shooting) {
        return;
    }
    shooting=true;
    launch.resetFrisbeeCount();
    launch.setSpeed(launchSpeed);
}

void Shooter::abort() {
    launch.stop();
    feed.stop();
    shooting=false;
}
bool Shooter::isShooting() {
    return shooting;
}
void Shooter::update_helper(void* a) {
    ((Shooter*)a) -> update();
}

