#ifndef JOYSMOOTH_H_INCLUDED
#define JOYSMOOTH_H_INCLUDED

#include <Joystick.h>
#include <bitset>

class joysmooth : public GenericHID {
private:
    Joystick real_joy;
    const static int NUMBUTTONS = 11;
    const static int WAIT_TIME = 3; //total amount of clicks to wait for
    std::bitset<3> buttons[NUMBUTTONS];
public:
    joysmooth (UINT32 port);
    ~joysmooth ();
    float GetX (JoystickHand hand = kRightHand);
    float GetY (JoystickHand hand = kRightHand);
    float GetZ ();
    float GetTwist ();
    float GetThrottle ();
    float GetRawAxis (UINT32 axis);
    bool GetTrigger (JoystickHand hand = kRightHand);
    bool GetTop (JoystickHand hand = kRightHand);
    bool GetBumper (JoystickHand hand = kRightHand);
    bool GetRawButton (UINT32);
    bool GetButton (UINT32);
    void update();
};

#endif
