#include "shifter.h"

const float klowgear = 0.8;
const float khighgear = 0.2;

shifter::shifter(hw_info a,hw_info b) : servo1(a.moduleNumber,a.channel), servo2(b.moduleNumber,b.channel){
    cur_gear = LOW;
}

shifter::~shifter() {
}

void shifter::set(GEAR g) {
    cur_gear = g;
}

void shifter::update() {
    float servoval;
    switch (cur_gear) {
        case LOW:
            servoval = klowgear;
            break;
        case HIGH:
            servoval = khighgear;
            break;
    }
    servo1.Set(servoval);
    servo2.Set(servoval);
}

