#include "feeder.h"

Feeder::Feeder(hw_info info) : feederMotor(info.moduleNumber,info.channel)
{
    direction = STOP;
} 

Feeder::~Feeder() {

}

void Feeder::forward() {
    directon = FORWARD;
}

void Feeder::backward() {
    direction = BACKWARD;
}

void Feeder::stop() {
    direction = STOP;
}

void Feeder::set_motor() {
    feederMotor.Set(dir);
}
void Feeder::update() {
    set_Motor();
}
