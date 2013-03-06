#include "feeder.h"
#include "612.h"

//Todo find a way to cleanly set the original value of counter to false

#ifdef Suzie
Feeder::Feeder(hw_info info1,hw_info info2) : feederMotor(info1,info2) {
#else
Feeder::Feeder(hw_info motorInfo,hw_info hallInfo) : feederMotor(motorInfo.moduleNumber,motorInfo.channel),
                                                     counter(hallInfo.moduleNumber,hallInfo.channel)
{
    counter.Start();
#endif //Suzie
    updateRegistry.addUpdateFunction(&update_helper,(void*)this);
    direction = STOP;
    counting = false; 
}


Feeder::~Feeder() {
}
void Feeder::setRawPower(double power)
{
    feederMotor.Set(power);
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
    counting = false;
    direction = STOP;
    feederMotor.Set(direction * SPEED);
#ifndef Suzie
    counter.Stop();
    counter.Reset();
#endif
}

Feeder::direction_t Feeder::getDirection() {
    return direction;
}

void Feeder::update() {
#ifndef Suzie
    static int count=0;
    if(count%25==0) {
        //std::printf("feeder hall effect: %d\n",counter.Get());
    }
    count++;
    if(direction == STOP)
        return;
    if(!counting) {
        counter.Start();
        counting = true;
    }
    if (counting && counter.Get() > 0) {
        stop();
        count = 0;
        return;
    }
    feederMotor.Set(direction * SPEED);
#endif
}

void Feeder::update_helper(void* obj) {
    ((Feeder*)obj)->update();
}
