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
    for (int f = 1; f <= NUMBUTTONS; f++){
        for (int s = 1; s < WAIT_TIME; s++){
            buttons[f][s - 1] = buttons [f][s];
        }
        buttons[f][WAIT_TIME - 1] = GetRawButton(f);
    }
}
bool joysmooth::GetButton(UINT32 btn) {
   for (int i = 0; i < WAIT_TIME; i++){
       if (!buttons[btn][i]){
           return false;
       }
   }
   return true;
}
void joysmooth::updateHelper(void* o) {
    ((joysmooth*)o) -> update();
}
