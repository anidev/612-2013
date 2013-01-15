#include "feeder.h"

Feeder::Feeder() {
    
} 

~Feeder::Feeder() { //check this line later

}

void Feeder::feeder_up() {
    set_direction(1);
}

void Feeder::feeder_down() {
    set_direction(-1);
}

void Feeder::feeder_stop() {
    set_direction(0);
}

void Feeder::set_direction(int dir) {
    //todo
}
