#ifndef STATE_H_INCLUDED
#define STATE_H_INCLUDED

typedef int robot_state;

class State {
//Todo Update Functionality
public:
    State(robot_state initial);   // constructor

    void set_state (robot_state new_state);
    robot_state get_state ();

    ~State();  // destructor
private:
    // methods that will be called only by class methods
    robot_state state;
};

#endif // STATE_H_INCLUDED
