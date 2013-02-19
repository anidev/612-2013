#ifndef ENHANCED_JOYSTICK_H
#define ENHANCED_JOYSTICK_H

#include <vector>
#include "joysmooth.h"
#include "612.h"

class EnhancedJoystick : public joysmooth {
public:
    typedef void* obj;
    typedef void(*funcName)(obj);
    void addBtn(UINT32,funcName,obj);
    EnhancedJoystick(UINT32);
    ~EnhancedJoystick();
    void updateEJ();
    static void updateEJHelper(obj);
private:
    void callFunct(int);
    std::vector<UINT32> btnNumbers;
    std::vector<funcName> helpers;
    std::vector<obj> objects;
    std::vector<bool> previousState;
};

#endif
