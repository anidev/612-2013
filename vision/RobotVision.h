#ifndef ROBOT_VISION_H
#define ROBOT_VISION_H

#include <vector>
#include <Task.h>
#include <networktables/NetworkTable.h>
#include <Vision/AxisCamera.h>
#include "vision.h"
#include "target.h"

// Everything on robot
class RobotVision : public vision
{
private:
    NetworkTable* table;
    AxisCamera* camera;
    Task vision_task;
    static int vision_entry(void*);
public:
    RobotVision(AxisCamera* camera);
    ~RobotVision();
    void startContinuous();
    void stopContinuous();
    std::vector<Target>* getTargetsNow();
};

#endif // ROBOT_VISION_H
