#ifndef VISION_H
#define VISION_H
#include "../target.h"
#include <vector>
#include <Vision/AxisCamera.h>
#include <cmath>

class vision
{
public:
    //AxisCamera camera;
    virtual void startVision()=0;
    virtual void stopVision()=0;
    virtual std::vector<Target>* getTargets()=0;
    int vision_entry();
    double getGroundDist(double,double);
protected:
    vision();
    virtual ~vision();
};
#endif
