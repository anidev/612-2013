#include <Joystick.h>
#include <bitset>
#include "joysmooth.h"

//defines the constants from .h
const int joysmooth::NUMBUTTONS;
const int joysmooth::WAIT_TIME;
int true_filter;

joysmooth::joysmooth(UINT32 port):real_joy(port) {
}

joysmooth::~joysmooth () {
}

void joysmooth::update(){
    for (int f = 1; f <= NUMBUTTONS; f++){
        for (int s = 1; s < WAIT_TIME; s++){
            buttons[f][s - 1] = buttons [f][s];
        }
        buttons[f][WAIT_TIME - 1] = real_joy.GetRawButton(f);      //me no leik pointers, swarage fix dis
    }
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
   for (int i = 0; i < WAIT_TIME; i++){
       if (!buttons[btn][i]){
           return false;
       }

   }
   return true;

    /*
    int true_filter = 0;
    for (int i = 0; i < 3; i++ ){
        if (real_joy.GetRawButton(btn)){
            true_filter += 1;
        }
    }
    if (true_filter == 3){
        return true;
    }
    return false;
    */

    // return GetRawButton(btn);
}
