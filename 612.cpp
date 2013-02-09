#include <networktables/NetworkTable.h>
#include "state.h"
#include "612.h"
#include "updateRegistry.h"

NetworkTable* main_table;
State global_state(DRIVE);
float fabs(float f) {
    if(f < 0) return (f*-1.0);
    return f;
}
