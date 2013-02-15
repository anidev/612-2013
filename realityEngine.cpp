#include "realityEngine.h"
#include "vision/vision.h"
struct AngleOffsetData {
    float angleOffset;
    TurnDirection direction;
};
AngleOffsetData getTurnAngle(float,float,float);
float getTargetLiftAngle(float,float,float = INITIAL_VELOCITY);
RealityData getReality(float liftAngle) {
    RealityData realWorld;
    AngleOffsetData angleDat = getTurnAngle(1,2,3); // Todo set Parameter
    realWorld.liftAngle = getTargetLiftAngle(1,2); // Todo set Parameter
    realWorld.angleOffset = angleDat.angleOffset;
    realWorld.direction = angleDat.direction;
    return realWorld;
}
AngleOffsetData getTurnAngle(float width,float height, float liftAngle) {
    AngleOffsetData dir;
    dir.angleOffset = 5; // Todo calculate this degrees
    dir.direction = LEFT; // Todo Determine this
    return dir; //Todo Finish This
}
float getTargetLiftAngle(float distance, float liftAngle, float initialVelocity) {
    return 0.0;//Todo Finish This
}

