#include "NetworkCom.h"
#include "Launcher.h"
#include "Lift.h"

NetworkCom::NetworkCom() {
	Main=NetworkTable::GetTable("612");
	if(Main!=NULL) {
		Tracking = Main->GetSubTable("Tracking");
		Gunner = Main->GetSubTable("Gunner");
		Autonomous = Main->GetSubTable("Autonomous");
	}
}

NetworkCom::~NetworkCom() {
}

void NetworkCom::target_available (bool target){
	Tracking->PutBoolean ("Available", target);
}
void NetworkCom::target_x (double new_target){
	Tracking->PutNumber("Target_x", new_target);
}
void NetworkCom::target_y (double new_target){
	Tracking->PutNumber("Target_y", new_target);
}
void NetworkCom::target_width (double new_target){
	Tracking->PutNumber("Target_width", new_target);
}
void NetworkCom::target_height (double new_target){
	Tracking->PutNumber("Target_height", new_target);
}
void NetworkCom::launcher_target_speed (double new_speed){
	Gunner->PutNumber("Launcher_target_speed", new_speed);
}
void NetworkCom::launcher_current_speed (double cur_speed){
	Gunner->PutNumber("Launcher_current_speed", cur_speed);
}
void NetworkCom::lift_angle (float new_angle){
	Gunner->PutNumber("Lift_angle", new_angle);
}
