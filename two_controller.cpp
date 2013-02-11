#include <SpeedController.h>
#include "two_controller.h"

template<class T>
two_controller<T>::two_controller(hw_info ione,hw_info itwo):one(ione.moduleNumber,ione.channel),two(itwo.moduleNumber,itwo.channel) {
}

template<class T>
two_controller<T>::~two_controller() {
}

template<class T>
void two_controller<T>::Set(float speed,UINT8 syncGroup) {
    one.Set(speed,syncGroup);
    two.Set(speed,syncGroup);
}

template<class T>
float two_controller<T>::Get() {
    return (one.Get()+two.Get())/2.0f;
}

template<class T>
void two_controller<T>::Disable() {
    one.Disable();
    two.Disable();
}

template<class T>
void two_controller<T>::PIDWrite(float output) {
    one.PIDWrite(output);
    two.PIDWrite(output);
}
