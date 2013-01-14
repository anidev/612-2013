#ifndef LAUNCHER_H
#define LAUNCHER_H
#include <cstdio>

class Launcher {
private:
    const int COUNT_THRESHOLD = 70; //rpm
    const int ON_SPEED = 100;//rpm
    const float AT_SPEED_TOLERANCE = 2; //rpm
    unsigned int count = 0;
    float getSpeed();

public:
    launcher();
    ~launcher();
    void start();
    void stop();
    void update();
    bool atSpeed();
    unsigned int getFrisbeeCount();
    void resetFrisbeeCount();
};

#endif // LAUNCHER_H
