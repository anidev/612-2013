#include "realityEngine.h"
#include "vision/vision.h"
float getTurnAngle(float,float,float);
float getTargetLiftAngle(float,float,float = INITIAL_VELOCITY);
RealityData getReality(float liftAngle) {
    RealityData realWorld;
    realWorld.angleOffset = getTurnAngle(1,2,3); // Todo set Parameter
    realWorld.liftAngle = getTargetLiftAngle(1,2); // Todo set Parameter
    return realWorld;
}
float getTurnAngle(float width,float height, float liftAngle) {
    return 0.0; //Todo Finish This
}
float getTargetLiftAngle(float distance, float liftAngle, float initialVelocity) {
    return 0.0;//Todo Finish This
}
