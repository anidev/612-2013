#ifndef FEEDER_H
#define FEEDER_H

#include <Talon.h>
#include <Relay.h>
#include "two_controller.h"
#include "ports.h"
#include "612.h"
#include <Counter.h>

class Feeder {
public:
    enum direction_t { // Will change to proper motor speed later
        FORWARD = 1,
        BACKWARD = -1,
        STOP = 0
    };
#ifdef Suzie
    Feeder(hw_info,hw_info);
#else
    Feeder(hw_info,hw_info);
#endif //Suzie
    ~Feeder();
    void forward();
    void backward();
    void stop();
    void setRawPower(double);
    direction_t getDirection();
private:
    bool counting;
    direction_t direction;
    void set_motor();
#ifdef Suzie
    two_controller<Relay> feederMotor;
#else
    Talon feederMotor;
    Counter counter;
#endif //Suzie
    void update();
    static const float SPEED = 0.25f;
};


#endif // FEEDER_H
