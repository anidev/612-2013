#ifndef VISION_H
#define VISION_H
#include "../target.h"
#include <vector>
#include <Vision/AxisCamera.h>

class vision
{
public:
    //AxisCamera camera;
    virtual void startVision()=0;
    virtual void stopVision()=0;
    virtual std::vector<Target>* getTargets()=0;
    int vision_entry();
protected:
    vision();
    virtual ~vision();
};
#endif
