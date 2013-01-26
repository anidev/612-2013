#ifndef FEEDER_H
#define FEEDER_H

#include <Talon.h>
#include "ports.h"

class Feeder {
private:
    direction_t direction;
    void set_motor();
    Talon feederMotor;
    void update();
    static const double SPEED = 0.5;
public:
    enum direction_t { // Will change to proper motor speed later
        FORWARD = 1,
        BACKWARD = -1,
        STOP = 0
    };
    Feeder(hw_info);
    ~Feeder();
    void forward();
    void backward();
    void stop();
    direction_t getDirection();
};


#endif // FEEDER_H
