#ifndef JOYSMOOTH_H_INCLUDED
#define JOYSMOOTH_H_INCLUDED
#include <Joystick.h>

class joysmooth : public GenericHID {
private:
    Joystick real_joy;
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
};

#endif // JOYSMOOTH_H_INCLUDED
