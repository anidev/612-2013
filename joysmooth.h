#ifndef JOYSMOOTH_H_INCLUDED
#define JOYSMOOTH_H_INCLUDED

#include <Joystick.h>
#include <bitset>

class joysmooth : public Joystick {
private:
    const static unsigned int NUMBUTTONS = 12;
    const static unsigned int WAIT_TIME = 3; //total amount of checks
    std::bitset<WAIT_TIME> buttons[NUMBUTTONS];
    static void updateHelper(void*);
public:
    joysmooth (UINT32 port);
    ~joysmooth ();
    void update();
    bool GetRawButton(UINT32);
};

#endif
