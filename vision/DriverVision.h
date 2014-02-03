#ifndef DRIVER_VISION_H
#define DRIVER_VISION_H

#include <Task.h>
#include <networktables/NetworkTable.h>
#include "vision.h"
#include "target.h"

// Everything on driver station
class DriverVision : public vision
{
private:
    NetworkTable* table;
    Task vision_task;
public:
    DriverVision();
    ~DriverVision();
    void startContinuous();
    void stopContinuous();
    std::vector<Target>* getTargetsNow();
};

#endif // DRIVER_VISION_H
