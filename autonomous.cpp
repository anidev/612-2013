#include "autonomous.h"
#include "main.h"

void doAutonomous(void* o) {
    //TODO Add Autonomous Here(It runs once)
}

void disableAuto(void* o) {
    ((robot_class*)o) -> Autonomous.Stop();
}
