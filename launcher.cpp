#include "Launcher.h"
#include <cmath>

Launcher::Launcher() {
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
