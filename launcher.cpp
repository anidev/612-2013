#include <cmath>
#include <Jaguar.h>
#include "ports.h"
#include "Launcher.h"


Launcher::Launcher(hw_info info) {
	count = 0;
	shooterWheel(info.moduleNumber,info.channel);
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
float Launcher::getSpeed() {
	return 0.0f; //Todo
}
