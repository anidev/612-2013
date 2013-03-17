#ifndef LIFT_H_INCLUDED
#define LIFT_H_INCLUDED

#include <SpeedController.h>
#include <CANJaguar.h>
#include <Jaguar.h>
#include <AnalogChannel.h>
#include "ports.h"
#include "updateRegistry.h"

class Lift {
private:
    static const float AT_ANGLE_TOLERANCE = 0.1f;
    bool manual;
    float target_angle;
    void set_direction(int);
    void update();
    static void updateHelper(void*);
public:    SpeedController * liftMotor;
private:
    static float potToAngle(float);
    static float angleToPot(float);
    #ifdef Suzie
        AnalogChannel pot;
    #else
        static const float LOWER_LIMIT = 0.0; //Todo Set Value
        static const float HIGHER_LIMIT = 1.0; //Todo Set Value
        static const UINT16 POT_TURNS = 50; //Todo SetValue
    #endif //Suzie only
    bool loaded;
    static void gunner_loaded_helper(void*);
public:
#ifdef Suzie
    Lift(hw_info,hw_info);
#else
    Lift(canport_t);
#endif//Suzie
    ~Lift();
    void lift_up();
    void lift_down();
    void lift_stop();
    void set_angle(float);
    float get_current_angle();
    float get_target_angle();
    bool at_angle();
    float getRawPotValue(); 
};

#endif // LIFT_H_INCLUDED
