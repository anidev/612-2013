/*      GunnerUI.h
 * This file is for the gunners user interface.
 * It will contain the gunners controller and its update function will
 * be how the gunner controller controls the robot.
 */
#if 0
#ifndef GUNNERUI_H
#define GUNNERUI_H
#include <Joystick.h> //Make joysmooth type later
#include "ports.h"
class gunnerUI { // Make derived class of joysmooth
    private:
    //todo
    Joystick gunnerJoystick; //Make Joysmooth later
    void update();

    public:
    gunnerUI(UINT32);
    ~gunnerUI();
    //todo
};

#endif
#endif
