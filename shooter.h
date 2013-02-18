#ifndef SHOOTER_H
#define SHOOTER_H

#include <Timer.h>
#include "feeder.h"
#include "ports.h"
#include "launcher.h"
#include "updateRegistry.h"
#include "612.h"
#include <AnalogChannel.h>

class Shooter {
private:
    enum ShooterStates {
        SPINNING_UP,
        FEEDING
    } cur_state;
    unsigned int targetCount;
    unsigned int previousCount;
    Launcher launch;
    Feeder feed;
    bool shooting;
    Timer feedTimer;
    static void shotBtnHelper(void*);
    static void update_helper(void*);
    static const double FEEDER_TIMEOUT = 2.0;
    static const double DEFAULT_LAUNCH_SPEED = 0.9;
    //~IR SENSOR STUFF
    AnalogChannel IRSensor; 
    bool enter;
    bool exit;
    static const float FRISBEE_PRESENCE_TOLERANCE = 0.8;
    bool voltage_changed; //I'm guessing that we are going to have a base voltage and that we detect a change
    int update_cnt;
    //~IR SENSOR STUFF
public:
#ifdef Suzie
    Shooter(hw_info, hw_info, hw_info, hw_info, hw_info);
#else
    Shooter(canport_t, hw_info, hw_info, hw_info, hw_info);
#endif //Suzie
    ~Shooter();
    // Launcher
    void setSpeed(float);
    float getTargetSpeed();
    float getCurrentSpeed();
    bool atSpeed();
    void stopLauncher();
    unsigned int getFrisbeeCount();
    void resetFrisbeeCount();
    // Feeder
    void setFeederForward();
    void setFeederBackward();
    void setFeederStop();
    Feeder::direction_t getFeederDirection();
    void setRawFeederPower(double);
    // Global shooter stuff
    void update();
    void shoot(int a = 4,double launchSpeed = DEFAULT_LAUNCH_SPEED);
    void abort();
    bool isShooting();
    //~IR SENSOR STUFF
    bool isShot();
    //~IR SENSOR STUFF
};

#endif
