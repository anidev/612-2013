#include <Joystick.h>
#include "joysmooth.h"

joysmooth::joysmooth(UINT32 port):real_joy(port) {
}

joysmooth::~joysmooth () {
}

float joysmooth::GetX(JoystickHand hand){
    return real_joy.GetX(hand);
}

float joysmooth::GetY(JoystickHand hand){
    return real_joy.GetY(hand);
}

float joysmooth::GetZ(){
    return real_joy.GetZ();
}

float joysmooth::GetTwist () {
    return real_joy.GetTwist();
}
float joysmooth::GetThrottle () {
    return real_joy.GetThrottle();
}
float joysmooth::GetRawAxis (UINT32 axis) {
    return real_joy.GetRawAxis(axis);
}
bool joysmooth::GetTrigger (JoystickHand hand) {
    return real_joy.GetTrigger();
}
bool joysmooth::GetTop (JoystickHand hand) {
    return real_joy.GetTop();
}
bool joysmooth::GetBumper (JoystickHand hand) {
    return real_joy.GetBumper();
}
bool joysmooth::GetRawButton (UINT32 button) {
    return real_joy.GetRawButton(button);
}
bool joysmooth::GetButton(UINT32 btn) {
    //Todo filter Btn Inputs
    return GetRawButton(btn);
}
