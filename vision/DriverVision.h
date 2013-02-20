#ifndef DRIVER_VISION_H
#define DRIVER_VISION_H

#include <vector>
#include <Task.h>
#include <networktables/NetworkTable.h>
#include "vision.h"
#include "../target.h"

// Everything on driver station
class DriverVision : public vision
{
private:
    NetworkTable* table;
    Task vision_task;
    void setRemoteEnabled(bool);
    static int vision_entry(void*);
public:
    DriverVision();
    void startContinuous();
    void stopContinuous();
    void startRemoteContinuous();
    void stopRemoteContinuous();
    std::vector<Target>* getTargetsNow();
};

#endif // DRIVER_VISION_H
