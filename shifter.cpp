#include "shifter.h"

const float klowgear = 0.8;
const float khighgear = 0.2;

shifter::shifter(hw_info a,hw_info b) : servo1(a.moduleNumber,a.channel), servo2(b.moduleNumber,b.channel){
    cur_gear = LOW;
    //set High
    left_joystick.addBtn(6,&setHighBtnHelper,((void*)this));
    right_joystick.addBtn(11,&setHighBtnHelper,((void*)this));
    //set LOW
    left_joystick.addBtn(7,&setLowBtnHelper,((void*)this));
    right_joystick.addBtn(10,&setLowBtnHelper,((void*)this));
}

shifter::~shifter() {
}

void shifter::set(GEAR g) {
    cur_gear = g;
    update();
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
void shifter::setHighBtnHelper(void* obj) {
    ((shifter*)obj) -> set(HIGH);
}
void shifter::setLowBtnHelper(void* obj) {
    ((shifter*)obj) -> set(LOW);
}
// left 6 right 11 
// downL 7 right 10
