#include "state.h"

robotState::robotState() {
    // do initializations
    state = DRIVE;
    number_of_disks = 0;
}

robotState::~robotState() {
    // do cleanup
}

void robotState::turn_on_led (int led_no)
{
    // turn on led
}

void robotState::increment_disk_count (void)
{
    number_of_disks++;
}

int robotState::get_disk_count (void)
{
    return number_of_disks;
}

void robotState::delete_all_disks (void)
{
    number_of_disks = 0;
}


