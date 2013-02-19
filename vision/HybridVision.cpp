#include <vector>
#include "../target.h"
#include "DriverVision.h"
#include "RobotVision.h"
#include "HybridVision.h"

void HybridVision::startContinuous() {
    driver.startContinuous();
}

void HybridVision::stopContinuous() {
    driver.stopContinuous();
}

std::vector<Target>* HybridVision::getTargetsNow() {
    return robot.getTargetsNow();
}
