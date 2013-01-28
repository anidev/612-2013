#ifndef VISION_H
#define VISION_H
#include "../target.h"
#include <vector>

class vision
{
public:
    virtual void startVision()=0;
    virtual void stopVision()=0;
    virtual std::vector<Target>* getTargets()=0;
protected:
    vision();
    virtual ~vision();
};
#endif
