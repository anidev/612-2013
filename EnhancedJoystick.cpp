#include "EnhancedJoystick.h"
void EnhancedJoystick::addToggleBtn(UINT32 btn,functName help,obj o) {
    btnNumbers.push_back(btn);
    helpers.push_back(help);
    previousState.push_back(false);
    objects.push_back(o);
}
void EnhancedJoystick::update() {
    for(unsigned int x = 0; x < btnNumbers.size(); x++)
    {
        if(GetButton(btnNumbers.at(x)) && previousState.at(x) == false)
        {
            callFunct(x);
            previousState.at(x) = true;
        }
        else if(GetButton(btnNumbers.at(x)) == false)
            previousState.at(x) = false;
    }
}
EnhancedJoystick::EnhancedJoystick(UINT32 a) : joysmooth(a) {
}
EnhancedJoystick::~EnhancedJoystick() {
    
}
void EnhancedJoystick::callFunct(int x) {
    helpers.at(x)(objects.at(x));
}
