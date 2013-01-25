#include "feeder.h"

Feeder::Feeder(hw_info info) : feederMotor(info.moduleNumber,info.channel)
{
    direction = STOP;
} 

Feeder::~Feeder() {

}

void Feeder::forward() {
    direction = FORWARD;
}

void Feeder::backward() {
    direction = BACKWARD;
}

void Feeder::stop() {
    direction = STOP;
}

Feeder::direction_t Feeder::getDirection() {
    return direction;
}

void Feeder::update() {
    feederMotor.Set(direction*SPEED);
}
