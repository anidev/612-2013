#include "EnhancedJoystick.h"
#include "shifter.h"
#include "controls.h"

//                          LOW   HI
const float kleftgear[] =  {0.8, 0.2};
const float krightgear[] = {0.2, 0.8};

shifter::shifter(hw_info a,hw_info b) : servo1(a.moduleNumber,a.channel), servo2(b.moduleNumber,b.channel){
    cur_gear = LOW;
    //set High
    drive_gamepad.addBtn(Driver_Btn_ShiftLow,&setHighBtnHelper,((void*)this)); // L1
    //set LOW
    drive_gamepad.addBtn(Driver_Btn_ShiftHigh,&setLowBtnHelper,((void*)this)); // R1
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
    if(cur_gear == LOW)
    {
        set(HIGH);
    }
    else
    {
        set(LOW);
    }
}

void shifter::update() {
    float leftval;
    float rightval;
    if(cur_gear == LOW) 
    {
        leftval = kleftgear[0];
        rightval = krightgear[0];
    }
    else
    {
        leftval = kleftgear[1];
        rightval = krightgear[1];
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
