#ifndef TWO_CONTROLLER_H
#define TWO_CONTROLLER_H

#include <SpeedController.h>
#include "ports.h"

// Control two SpeedControllers together
template<class T> class two_controller : public SpeedController {
private:
    T one;
    T two;
public:
    two_controller(hw_info,hw_info);
    ~two_controller();
    void Set(float,UINT8 syncGroup=0);
    float Get();
    void Disable();
    void PIDWrite(float);
};

#endif // TWO_CONTROLLER_H

