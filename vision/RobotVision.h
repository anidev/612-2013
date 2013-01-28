#ifndef ROBOT_VISION_H
#define ROBOT_VISION_H

#include "vision.h"
#include "../target.h"
#include <vector>

class RobotVision: public vision
{
    void startVision();
    void stopVision();
    std::vector<Target>* getTargets();
};

#endif // ROBOT_VISION_H
