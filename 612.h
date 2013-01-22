#ifndef _612_H
#define _612_H

#include <networktables/NetworkTable.h>
#include "state.h"

extern NetworkTable* main_table;
extern State global_state;

enum teleop_state {
    DRIVE,SHOOT,CLIMB
};

#endif // _612_H
