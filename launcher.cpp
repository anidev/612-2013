#include <cmath>
#include <Jaguar.h>
#include "ports.h"
#include "launcher.h"
#include "612.h"

Launcher::Launcher(hw_info wheel1,hw_info wheel2,hw_info sensor) : launcherWheel(wheel1,wheel2),
                                                                   launcherSensor(sensor.moduleNumber, sensor.channel ) {
    count = 0;
    targetSpeed = 0;
    targetSet = false;
    updateRegistry.addUpdateFunction(&update_helper,(void*)this);
}

Launcher::~Launcher() {
}

void Launcher::stop() {
    targetSet = false;
    setSpeed(0.0f);
    launcherWheel.Set(0.0f);
    //insert more code here
}

void Launcher::setSpeed(float newSpeed) {
    targetSpeed = newSpeed;
    targetSet = true;
}

float Launcher::getCurrentSpeed() {
    return 1.0/(launcherSensor.GetPeriod());
}

float Launcher::getTargetSpeed() {
    return targetSpeed;
}

bool Launcher::atSpeed(){
    if(fabs(getCurrentSpeed()-targetSpeed) < AT_SPEED_TOLERANCE){
        return true;
    }
    return false;
}

void Launcher::resetFrisbeeCount(){
    count = 0;
}

unsigned int Launcher::getFrisbeeCount(){
    return count;
}

void Launcher::update() {
    if(targetSet)
    {
        launcherWheel.Set(targetSpeed);
    }
    //Todo Add Frisbee Count Here
}
void Launcher::update_helper(void* o) {
    ((Launcher*)o) -> update();
}
