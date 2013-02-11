#include "feeder.h"

Feeder::Feeder(hw_info info1,hw_info info2) : feederMotor(info1,info2)
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
