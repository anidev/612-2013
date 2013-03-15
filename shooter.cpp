#include "shooter.h"
#include "launcher.h"
#include "feeder.h"
#include "612.h"
#include "ports.h"

#ifdef Suzie
Shooter::Shooter(hw_info launchWheel1,hw_info launchWheel2,hw_info launchSensor,hw_info feedInfo1,hw_info feedInfo2):
        feed(feedInfo1,feedInfo2),launch(launchWheel1,launchWheel2,launchSensor)
{
    shooting = false;
    updateRegistry.addUpdateFunction(&update_helper, (void*)this);
    cur_state = SPINNING_UP;
}
#else
Shooter::Shooter(canport_t canJag,hw_info sensorInfo,hw_info feedInfo, hw_info feedSensor, hw_info IRInfo):
         feed(feedInfo,feedSensor), launch(canJag,sensorInfo),IRSensor(IRInfo.moduleNumber,IRInfo.channel)
{
    shooting = false;
    cur_state = SPINNING_UP;
    previousCount = 0;
    launch.resetFrisbeeCount();
    updateRegistry.addUpdateFunction(&update_helper, (void*)this);
    enter=false;
    exit=false;
}
#endif //Suzie

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

void Shooter::stopLauncher() {
    launch.stop();
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
void Shooter::setRawFeederPower(double b) {
    feed.setRawPower(b);
}
void Shooter::update() {
#ifndef Suzie
    if(!shooting) {
        return;
    }
    if(launch.getFrisbeeCount() < targetCount)
    {
        if(cur_state == SPINNING_UP)
        {
            if(launch.atSpeed())
            {
                cur_state = FEEDING;
            }
        }
        else
        {
            if(!launch.atSpeed())
            {
                feed.stop();
                feedTimer.Stop();
                feedTimer.Reset();
                cur_state = SPINNING_UP;
            }
            if (IRSensor.GetVoltage() > DEFAULT_IR_RETURN) {
                enter = true;
            }
            if (enter && IRSensor.GetVoltage() < DEFAULT_IR_RETURN) {
                exit = true;
            }
            //todo add uses for enter/exit
            feed.forward();
            feedTimer.Start();
            if(launch.getFrisbeeCount() > previousCount)
            {
                feedTimer.Reset();
                previousCount = launch.getFrisbeeCount();
            }
            if(feedTimer.Get() > FEEDER_TIMEOUT)
            {
                // feeder moving but launcher hasn't slowed down for a while
                // meaning no more frisbees
                abort();
            }
        }
    }
    else
    {
        shooting = false;
        launch.stop();
    }
#endif
}
void Shooter::shoot(unsigned int tCount,double launchSpeed) {
    if(shooting) {
        return;
    }
    shooting = true;
    cur_state = SPINNING_UP;
    previousCount = 0;
    launch.resetFrisbeeCount();
    launch.setSpeed(launchSpeed);
    targetCount = tCount;
}

void Shooter::abort() {
    launch.stop();
    feed.stop();
    feedTimer.Stop();
    frisCounter.Stop();
    shooting = false;
    cur_state = SPINNING_UP;
}

bool Shooter::isShooting() {
    return shooting;
}

bool Shooter::isShot() {
#ifdef Suzie
    return false;
#else
    if ((isShooting()) && (enter && exit) && (launch.dropDetected())) {
        printf("out of frisbees");
        return true;
    }
    else 
    {
        return false;
    }
#endif
}

bool Shooter::noFrisbees() {
    if ((frisCounter.Get() > 2) && (launch.dropDetected())) {
        ledstrip_spike.Set(Relay::kOn);
        return true;
    }    
    return false;
}

void Shooter::update_helper(void* a) {
    ((Shooter*)a) -> update();
}
