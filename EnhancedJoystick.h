#ifndef ENHANCEDJOYSTICK_H
#define ENHANCEDJOYSTICK_H

#include <vector>
#include "Joysmooth.h"

class EnhancedJoystick : public joysmooth {
public:
    typedef void (*functName)(void *);
    typedef void* obj;
    void addToggleBtn(UINT32,functName,obj);
    EnhancedJoystick(UINT32);
    ~EnhancedJoystick();
    void update();
private:
    void callFunct(int);
    std::vector<UINT32> btnNumbers;
    std::vector<functName> helpers;
    std::vector<obj> objects;
    std::vector<bool> previousState;
};

#endif
