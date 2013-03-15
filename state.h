#ifndef STATE_H_INCLUDED
#define STATE_H_INCLUDED

#include <vector>
typedef int robot_state;
typedef void* obj;
typedef void (*functs)(obj);
class State {
//Todo Update Functionality elsewhere
public:
    State(robot_state initial); // constructor
    void set_state (robot_state new_state);
    robot_state get_state ();
    void addState(int,functs,obj);
    ~State(); // destructor
    void runState();
private:
    std::vector<functs> functions;
    std::vector<obj> objects;
    std::vector<int> states;
    robot_state state;
};

#endif // STATE_H_INCLUDED
