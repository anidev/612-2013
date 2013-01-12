#include "feeder.h"

bool feeder::is_frisbee_loaded(bool sensor_feed) { 
	//is the frisbee loaded? We'll probably use a sensor for this. Note: make sure to learn documentation for sensoris
	return sensor_feed;
}
void feeder::load_frisbee(double button_index){
	//this would power certain motors in order to load a frisbee. We will probably use something like "roller_motor"
	//the parameter is the index of the button used to shift the loader either back or forth
	//if button x is used, the motor will be set to a negative amount, positive if button y.
	/*
	if (button_index == the_forward_button_index) { //note: not a real variable, just a placeholder
		conveyor_belt_motor.set_power(1); //note: nothing here is real, they are all placeholders
	} else if (button_index == the_backward_button_index) {
		conveyor_belt_motor.set_power(-1);
	}
	*/
} 
