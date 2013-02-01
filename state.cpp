#include "state.h"

State::State(robot_state initial):state(initial) {
}

State::~State() {
    // do cleanup
}

void State::set_state (robot_state new_state)
{
    state = new_state;
}

robot_state State::get_state ()
{
    return state;
}
