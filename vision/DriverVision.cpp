#include "vision.h"
#include "../target.h"
#include <vector>
#include "DriverVision.h"

void DriverVision::startVision(){}
void DriverVision::stopVision(){}
std::vector<Target>* DriverVision::getTargets() {
    return new std::vector<Target>();
}



