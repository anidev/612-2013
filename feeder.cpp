#include "feeder.h"
#include "612.h"

#ifdef Suzie
Feeder::Feeder(hw_info info1,hw_info info2) : feederMotor(info1,info2)
#else
Feeder::Feeder(hw_info info) : feederMotor(info.moduleNumber,info.channel)
#endif //Suzie
{
    direction = STOP;
    //Add update helper
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
    feederMotor.Set(direction * SPEED);
}

Feeder::direction_t Feeder::getDirection() {
    return direction;
}

void Feeder::update() {
    if(direction == STOP)
        return;
    feederMotor.Set(direction * SPEED);
    //TODO Add Sensors here and update helper
}
