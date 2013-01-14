#ifndef STATE_H_INCLUDED
#define STATE_H_INCLUDED

enum ROBOT_STATE {DRIVE, CLIMB, LIFT};

class RobotState {

public:
    RobotState();   // constructor

    void RobotState::change_state (robot_state new_state);
    robot_state RobotState::get_state ();

    ~RobotState();  // destructor
private:
    // methods that will be called only by class methods
    ROBOT_STATE state;
    int number_of_disks;
};

#endif // STATE_H_INCLUDED
