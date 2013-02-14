#ifndef TWO_CONTROLLER_H
#define TWO_CONTROLLER_H

#include <SpeedController.h>
#include <Relay.h>
#include "ports.h"

// Control two SpeedControllers together
template<class T> class two_controller : public SpeedController {
private:
    T one;
    T two;
public:
    two_controller(hw_info ione,hw_info itwo):one(ione.moduleNumber,ione.channel),two(itwo.moduleNumber,itwo.channel) {
    }
    ~two_controller() {
    }
    void Set(float speed,UINT8 syncGroup=0) {
        one.Set(speed,syncGroup);
        two.Set(speed,syncGroup);
    }
    float Get() {
        return (one.Get()+two.Get())/2.0f;
    }
    void Disable() {
        one.Disable();
        two.Disable();
    }
    void PIDWrite(float output) {
        one.PIDWrite(output);
        two.PIDWrite(output);
    }
};

template<>
class two_controller<Relay> {
private:
    Relay one;
    Relay two;
public:
    two_controller(hw_info ione,hw_info itwo):one(ione.moduleNumber,ione.channel),two(itwo.moduleNumber,itwo.channel) {
    }
    ~two_controller() {
    }
    void Set(float speed,UINT8 syncGroup=0) {
        std::printf("tworelay set %f\n",speed);
        Relay::Value dir;
        if(speed>0) {
            dir=Relay::kForward;
        }
        else if(speed<0) {
            dir=Relay::kReverse;
        }
        else
        {
            dir=Relay::kOff;
        }
        std::printf("setting relay 1 to %d\n",dir);
        one.Set(dir);
        std::printf("setting relay 2 to %d\n",dir);
        two.Set(dir);
    }
    float Get() {
        if(one.Get()==two.Get()) {
            return (float)one.Get();
        }
        return 0.0f;
    }
    void Disable() {
        one.Set(Relay::kOff);
        two.Set(Relay::kOff);
    }
    void PIDWrite(float output) {
        Set(output);
    }
};

#endif // TWO_CONTROLLER_H
