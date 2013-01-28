#include <cmath>
#include <Jaguar.h>
#include "ports.h"
#include "launcher.h"

double Counter (hw_info) {

}

Launcher::Launcher(hw_info wheel,hw_info sensor) : launcherWheel(sensor.moduleNumber, sensor.channel)
                                   launcherSensor(sensor.moduleNumber, sensor.channel ) {
    count = 0;
}

Launcher::~Launcher() {
}

void Launcher::stop() {
    setSpeed(0.0f);
    //insert more code here
}

void Launcher::setSpeed(float newSpeed) {
    targetSpeed=newSpeed;
}

float Launcher::getCurrentSpeed() {
    return 1/(launcherSensor.GetPeriod());
}

float Launcher::getTargetSpeed() {
    return targetSpeed;
}

bool Launcher::atSpeed(){
    if(fabs(getCurrentSpeed()-ON_SPEED) < AT_SPEED_TOLERANCE){
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

