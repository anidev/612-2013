#ifndef STATE_SHOOTING_H
#define STATE_SHOOTING_H

typedef int shooting_state;

class shooting_auto {
// use VisionFeedback directly and plug it straight into GunnerControl
public:
    shooting_auto();
    void shooting_state();
    ~shooting_auto();
}

class shooting_manual{
// display the vision feedback data on the driver station
public:
    shooting_manual();
    void shooting_state();
    ~shooting_manual();
}

#endif // STATE_SHOOTING_H
