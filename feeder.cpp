#include "feeder.h"

Feeder::Feeder(hw_info info) : feederMotor(info.moduleNumber,info.channel)
{
    direction = STOP;
} 

Feeder::~Feeder() {

}

void Feeder::forward() {
    direction = FORWARD;
    update();
}

void Feeder::backward() {
    direction = BACKWARD;
    update();
}

void Feeder::stop() {
    direction = STOP;
    update();
}

Feeder::direction_t Feeder::getDirection() {
    return direction;
}

void Feeder::update() {
    feederMotor.Set(direction*SPEED);
}
