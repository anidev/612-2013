#ifndef STATE_H_INCLUDED
#define STATE_H_INCLUDED

typedef int robot_state;

class State {

public:
    State(robot_state initial);   // constructor

    void State::change_state (robot_state new_state);
    robot_state State::get_state ();

    ~State();  // destructor
private:
    // methods that will be called only by class methods
    robot_state state;
    int number_of_disks;
};

#endif // STATE_H_INCLUDED
