#ifndef STATE_H_INCLUDED
#define STATE_H_INCLUDED

enum robot_state {DRIVE, CLIMB, LIFT};

class RobotState {

public:
    RobotState();   // constructor

    void RobotState::change_state (robot_state new_state);
    robot_state RobotState::get_state ();

    ~RobotState();  // destructor
private:
    // methods that will be called only by class methods
    robot_state state;
    int number_of_disks;
};

#endif // STATE_H_INCLUDED
