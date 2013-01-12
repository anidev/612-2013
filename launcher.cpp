#include "launcher.h"


void Launcher::start() {
    //insert code here
}

void Launcher::stop() {
    //insert more code here
}


bool Launcher::atSpeed(){
    if(abs(getSpeed()-ON_SPEED) < AT_SPEED_TOLERANCE){
        return true;
    }
    return false;
}

void Launcher::resetFrisbeeCount(){
    count = 0;
}

void Launcher::update(){
    //insert code here
}

unsigned int Launcher::getFrisbeeCount(){
    return count;
}
