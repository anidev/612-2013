#ifndef JOYSMOOTH_H_INCLUDED
#define JOYSMOOTH_H_INCLUDED

#include <Joystick.h>
#include <bitset>

class joysmooth : public Joystick {
private:
    const static int NUMBUTTONS = 11;
    const static int WAIT_TIME = 3; //total amount of checks
    std::bitset<WAIT_TIME> buttons[NUMBUTTONS];
public:
    joysmooth (UINT32 port);
    ~joysmooth ();
    bool GetButton (UINT32);
    void update();
    static void updateHelper(void*);
};

#endif
