#include "EnhancedJoystick.h"
#include "612.h"
void EnhancedJoystick::addBtn(UINT32 btn,funcName help,obj o) {
    btnNumbers.push_back(btn);
    helpers.push_back(help);
    previousState.push_back(false);
    objects.push_back(o);
}
void EnhancedJoystick::updateEJ() {
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
EnhancedJoystick::EnhancedJoystick(UINT32 a) : joysmooth(a) {
    updateRegistry.addUpdateFunction(&updateEJHelper,(void*)this);
}
EnhancedJoystick::~EnhancedJoystick() {
}
void EnhancedJoystick::callFunct(int x) {
    helpers.at(x)(objects.at(x));
}
void EnhancedJoystick::updateEJHelper(obj object) {
    ((EnhancedJoystick*)(object)) -> updateEJ();
}
