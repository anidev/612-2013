#ifndef JOYSMOOTH_H_INCLUDED
#define JOYSMOOTH_H_INCLUDED
#include <GenericHID.h>

class joysmooth : public GenericHID {
private:
    Joystick real_joy;

public:
    joysmooth (int port);
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
    bool GetRawButton (UINT32 button);
};

#endif // JOYSMOOTH_H_INCLUDED
