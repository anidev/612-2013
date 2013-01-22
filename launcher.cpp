#include <cmath>
#include <Jaguar.h>
#include "ports.h"
#include "launcher.h"


Launcher::Launcher(hw_info info) {
    count = 0;
    shooterWheel=new Jaguar(info.moduleNumber,info.channel);
}
Launcher::~Launcher() {
    delete shooterWheel;
}

void Launcher::stop() {
    setSpeed(0.0f);
    //insert more code here
}

void Launcher::setSpeed(float newSpeed) {
    targetSpeed=newSpeed;
}

float Launcher::getCurrentSpeed() {
    // TODO
    return 0.0f;
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
