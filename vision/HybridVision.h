#ifndef HYBRID_VISION_H
#define HYBRID_VISION_H

#include <vector>
#include "vision.h"
#include "DriverVision.h"
#include "RobotVision.h"
#include "../target.h"

// Continuous on driver station, on demand processing on robot
class HybridVision : public vision {
private:
    DriverVision driver;
    RobotVision robot;
public:
    void startContinuous();
    void stopContinuous();
    std::vector<Target>* getTargetsNow();
};

#endif // HYBRID_VISION_H
