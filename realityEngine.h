#ifndef REALITY_ENGINE_H
#define REALITY_ENGINE_H
    const float INITIAL_VELOCITY = 300; // Feet per second
    struct RealityData {
        float angleOffset;
        float liftAngle;
    };
   RealityData getReality(float); // LiftAngle
#endif
