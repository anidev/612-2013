#include <networktables/NetworkTable.h>
#include "state.h"
#include "612.h"
#include "updateRegistry.h"

NetworkTable* main_table;
State global_state(DRIVE);
bool driverOperation=false;
