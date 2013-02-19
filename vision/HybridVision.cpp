#include <vector>
#include "../target.h"
#include "DriverVision.h"
#include "RobotVision.h"
#include "HybridVision.h"

void HybridVision::startContinuous() {
    driver.startRemoteContinuous();
}

void HybridVision::stopContinuous() {
    driver.stopRemoteContinuous();
}

std::vector<Target>* HybridVision::getTargetsNow() {
    return robot.getTargetsNow();
}
