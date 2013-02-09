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
	Tracking->PutNumber("X", new_target);
}
void NetworkCom::target_y (double new_target){
	Tracking->PutNumber("Y", new_target);
}
void NetworkCom::target_width (double new_target){
	Tracking->PutNumber("Width", new_target);
}
void NetworkCom::target_height (double new_target){
	Tracking->PutNumber("Height", new_target);
}
void NetworkCom::launcher_target_speed (double new_speed){
	Gunner->PutNumber("LauncherTarget", new_speed);
}
void NetworkCom::launcher_current_speed (double cur_speed){
	Gunner->PutNumber("LauncherCurrent", cur_speed);
}
void NetworkCom::lift_angle (float new_angle){
	Gunner->PutNumber("LiftAngle", new_angle);
}
