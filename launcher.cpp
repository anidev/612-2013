#include "Launcher.h"
#include <math.h>
Launcher::Launcher() {
	count = 0;
}
Launcher::~Launcher() {
	
}

void Launcher::start() {
    //insert code here
}

void Launcher::stop() {
    //insert more code here
}


bool Launcher::atSpeed(){
    if(fabs(getSpeed()-ON_SPEED) < AT_SPEED_TOLERANCE){
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
