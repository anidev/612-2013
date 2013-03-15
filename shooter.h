#ifndef SHOOTER_H
#define SHOOTER_H

#include <Timer.h>
#include <AnalogChannel.h>
#include <Counter.h>
#include "feeder.h"
#include "ports.h"
#include "launcher.h"
#include "updateRegistry.h"
#include "612.h"
#include "dataLogger.h"

class Shooter {
protected: Feeder feed;
private:
    friend class DataLogger;
    enum ShooterStates {
        SPINNING_UP,
        FEEDING
    } cur_state;
    unsigned int targetCount;
    unsigned int previousCount;
    Launcher launch;
    bool shooting;
    Timer feedTimer;
    static void shotBtnHelper(void*);
    static void update_helper(void*);
    static const double FEEDER_TIMEOUT = 2.0;
    static const double DEFAULT_LAUNCH_SPEED = 0.9;
#ifndef Suzie
    //~IR SENSOR STUFF
protected: AnalogChannel IRSensor;
private:
    bool enter;
    bool exit;
    static const double DEFAULT_IR_RETURN = 2.0;
#endif
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
    void shoot(unsigned int a = 4,double launchSpeed = DEFAULT_LAUNCH_SPEED);
    void abort();
    bool isShooting();
    //~IR SENSOR STUFF
    bool isShot();
    //~IR SENSOR STUFF
    bool noFrisbees();
    Counter frisCounter;
};

#endif
