#ifndef REALITY_ENGINE_H
#define REALITY_ENGINE_H
    const float INITIAL_VELOCITY = 300; // Feet per second Todo set correct Value
    enum TurnDirection {
        LEFT,
        RIGHT,
        DONT_TURN
    };
    struct RealityData {
        float angleOffset;
        float liftAngle;
        TurnDirection direction;
    };
   RealityData getReality(float); // LiftAngle
#endif
