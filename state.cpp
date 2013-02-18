#include "state.h"  

State::State(robot_state initial):state(initial) {
}

State::~State() {
}

void State::set_state (robot_state new_state)
{
    state = new_state;
}

robot_state State::get_state ()
{
    return state;
}

void State::addState(int state,functs fun,obj o)
{
    functions.push_back(fun);
    objects.push_back(o);
    states.push_back(state);
}
void State::runState() {
    for(int i = 0;i < states.size();i++)
    {
        if(states.at(i) == state)
        {
            (functions.at(i))(objects.at(i));
        }
    }
}
