#include <Joystick.h>
#include <bitset>
#include "612.h"
#include "joysmooth.h"

joysmooth::joysmooth(UINT32 port):Joystick(port) {
    updateRegistry.addUpdateFunction(&updateHelper,(void*)this);
}

joysmooth::~joysmooth () {
}

void joysmooth::update(){
    for (unsigned int f = 0; f < NUMBUTTONS; f++){
        for (unsigned int s = 1; s < WAIT_TIME; s++){
            buttons[f][s - 1] = buttons [f][s];
        }
        buttons[f][WAIT_TIME - 1] = Joystick::GetRawButton(f+1);
    }
    
}
bool joysmooth::GetRawButton(UINT32 btn) {
   for (unsigned int i = 0; i < WAIT_TIME; i++){
       if (!buttons[btn - 1][i]){
           return false;
       }
   }
   return true;
}
void joysmooth::updateHelper(void* o) {
    ((joysmooth*)o) -> update();
}
