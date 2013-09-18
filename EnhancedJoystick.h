#ifndef ENHANCED_JOYSTICK_H
#define ENHANCED_JOYSTICK_H

#include <vector>
#include <bitset>
#include <Joystick.h>
#include "Controls.h"

class EnhancedJoystick : public Joystick {
public:
    static const float JOYSTICK_ZERO_TOLERANCE = 0.08;
    static const float TRIGGER_TOLERANCE = 0.25;
    typedef void* obj;
    typedef void(*funcName)(obj);
    void addBtn(UINT32,funcName,obj);
    EnhancedJoystick(UINT32,void*);
    ~EnhancedJoystick();
    void updateEJ();
    static void updateEJHelper(obj);
    bool GetRawButton(UINT32 btn);
    bool IsAxisZero(unsigned int);
    Trigger GetTrigger();
private:
    const static unsigned int NUMBUTTONS = 12;
    const static unsigned int WAIT_TIME = 3; //total amount of checks
    std::bitset<WAIT_TIME> buttons[NUMBUTTONS];
    void callFunct(unsigned int);
    std::vector<UINT32> btnNumbers;
    std::vector<funcName> helpers;
    std::vector<obj> objects;
    std::vector<bool> previousState;
};

#endif
