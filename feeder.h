#ifndef FEEDER_H
#define FEEDER_H

#include "Talon.h"
#include "ports.h"

class Feeder {
private:
    enum feederDirection { // Will change to proper motor speed later
        FORWARD = 1,
        BACKWARD = -1,
        STOP = 0
    } direction;
    void set_motor();
    Talon feederMotor;
    void update();
public:
    Feeder(hw_info);
    ~Feeder();
    void forward();
    void backward();
    void stop();
    feederDirection getDirection { return direction; }
};

#endif // FEEDER_H
