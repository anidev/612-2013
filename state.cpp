#include "state.h"

RobotState::RobotState() {
    // do initializations
    state = DRIVE;
}

RobotState::~RobotState() {
    // do cleanup
}

void RobotState::change_state (robot_state new_state)
{
    state = new_state;
}

robot_state RobotState::get_state ()
{
    return state;
}
