#ifndef SHIFTER_H_INC
#define SHIFTER_H_INC

#include <Servo.h>
#include "ports.h"
class shifter {
public:
    enum GEAR {
        LOW,
        HIGH
    };
    shifter(hw_info,hw_info);
    ~shifter();
    void set(GEAR);
    GEAR cur_gear;
    void update();
private:
    Servo servo1;
    Servo servo2;
};

#endif
