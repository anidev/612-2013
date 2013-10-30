#include <cmath>
#include "Joystick.h"
#include "EnhancedJoystick.h"
#include "Controls.h"
#include "main.h"

EnhancedJoystick::EnhancedJoystick(UINT32 a,void* o) : Joystick(a) {
    (((robot_class*)o) -> updateRegistry).addUpdateFunction(&updateEJHelper,(void*)this);
}

EnhancedJoystick::~EnhancedJoystick() {
}

void EnhancedJoystick::addBtn(UINT32 btn,funcName help,obj o) {
    btnNumbers.push_back(btn);
    helpers.push_back(help);
    previousState.push_back(false);
    objects.push_back(o);
}

void EnhancedJoystick::updateEJ() {
    for (unsigned int f = 0; f < NUMBUTTONS; f++){
        for (unsigned int s = 1; s < WAIT_TIME; s++){
            buttons[f][s - 1] = buttons [f][s];
        }
        buttons[f][WAIT_TIME - 1] = Joystick::GetRawButton(f+1);
    }
    for(unsigned int x = 0; x < btnNumbers.size(); x++)
    {
        if(GetRawButton(btnNumbers.at(x)) && previousState.at(x) == false)
        {
            callFunct(x);
            previousState.at(x) = true;
        }
        else if(GetRawButton(btnNumbers.at(x)) == false)
            previousState.at(x) = false;
    }
}

void EnhancedJoystick::callFunct(unsigned int x) {
    (helpers.at(x))(objects.at(x));
}

void EnhancedJoystick::updateEJHelper(obj object) {
    ((EnhancedJoystick*)(object)) -> updateEJ();
}
bool EnhancedJoystick::GetRawButton(UINT32 btn) {
   for (unsigned int i = 0; i < WAIT_TIME; i++){
       if (!buttons[btn - 1][i]){
           return false;
       }
   }
   return true;
}
bool EnhancedJoystick::IsAxisZero(unsigned int i) {
    float value=GetRawAxis(i);
    return std::fabs(value)<=JOYSTICK_ZERO_TOLERANCE;
}
Trigger EnhancedJoystick::GetTriggerState() {
    float value=GetRawAxis(TRIGGER_AXIS);
    if(value<TRIGGER_TOLERANCE-1) {
        return TRIG_R;
    } else if(value>1-TRIGGER_TOLERANCE) {
        return TRIG_L;
    }
    return TRIG_NONE;
}
