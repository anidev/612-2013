#ifndef DRIVER_VISION_H
#define DRIVER_VISION_H

#include "vision.h"
#include "../target.h"
#include <vector>

class DriverVision: public vision
{
    void startVision();
    void stopVision();
    std::vector<Target>* getTargets();
};

#endif // DRIVER_VISION_H
