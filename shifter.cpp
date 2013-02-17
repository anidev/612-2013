#include "EnhancedJoystick.h"
#include "shifter.h"

//                          LOW   HI
const float kleftgear[] =  {0.8, 0.2};
const float krightgear[] = {0.2, 0.8};

shifter::shifter(hw_info a,hw_info b) : servo1(a.moduleNumber,a.channel), servo2(b.moduleNumber,b.channel){
    cur_gear = LOW;
    //set High
    drive_gamepad.addBtn(5,&setHighBtnHelper,((void*)this)); // L1
    //set LOW
    drive_gamepad.addBtn(6,&setLowBtnHelper,((void*)this)); // R1
}

shifter::~shifter() {
}

void shifter::set(GEAR g) {
    cur_gear = g;
    update();
}

shifter::GEAR shifter::get() {
    return cur_gear;
}

// toggle shifting from high to low
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
    float leftval;
    float rightval;
    switch (cur_gear) {
        case LOW:
            leftval = kleftgear[0];
            rightval = krightgear[0];
            break;
        case HIGH:
            leftval = kleftgear[1];
            rightval = krightgear[1];
            break;
    }
    servo1.Set(leftval);
    servo2.Set(rightval);
}
void shifter::setHighBtnHelper(void* obj) {
    ((shifter*)obj) -> set(HIGH);
}
void shifter::setLowBtnHelper(void* obj) {
    ((shifter*)obj) -> set(LOW);
}
// left 6 right 11 
// downL 7 right 10
