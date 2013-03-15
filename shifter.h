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
    GEAR get();
    void update();
    void shift();
private:
    static void setHighBtnHelper(void*);
    static void setLowBtnHelper(void*);
    GEAR cur_gear;
    Servo servo1;
    Servo servo2;
};

#endif
