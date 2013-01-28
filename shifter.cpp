#include "shifter.h"

const float klowgear = 0.8;
const float khighgear = 0.2;

shifter::shifter(hw_info a,hw_info b) : servo1(a.moduleNumber,a.channel), servo2(b.moduleNumber,b.channel){
    cur_gear = LOW;
    gunner_joystick.addToggleBtn(7,&toggleHelper,((void*)this)); //todo test then set to actual btn
}

shifter::~shifter() {
}

void shifter::set(GEAR g) {
    cur_gear = g;
}
void shifter::shift() {
    switch (cur_gear) {
        case LOW:
            set(HIGH);
            break;
        case HIGH:
            set(LOW);
            break;
    }
    update();
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
void shifter::toggleHelper(void* obj) {
    ((shifter*)obj) -> shift();
}
