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
    if (target_available != GetBoolean(target)) {
        target_available = Tracking->PutBoolean ("Available", target);
    }
}
void NetworkCom::target_x (double new_target){
    if (target_x != GetNumber(new_target)) {
        target_x = Tracking->PutNumber("X", new_target);
    }
}
void NetworkCom::target_y (double new_target){
    if (target_y != GetNumber(new_target)) {
        target_y = Tracking->PutNumber("Y", new_target);
    }
}
void NetworkCom::target_width (double new_target){
    if (target_width != GetNumber(new_target)) {
        target_width = Tracking->PutNumber("Width", new_target);
    }
}
void NetworkCom::target_height (double new_target){
    if (target_height != GetNumber(new_target)) {
        target_height = Tracking->PutNumber("Height", new_target);
    }
}
void NetworkCom::launcher_target_speed (double new_speed){
    if (launcher_target_speed != GetNumber(new_speed)) {
        launcher_target_speed = Gunner->PutNumber("LauncherTarget", new_speed);
    }
}
void NetworkCom::launcher_current_speed (double cur_speed){
    if (launcher_current_speed != GetNumber(cur_speed)) {
        launcher_current_speed = Gunner->PutNumber("LauncherCurrent", cur_speed);
    }
}
void NetworkCom::lift_angle (float new_angle){
    if (lift_angle != GetNumber(new_angle)) {
        lift_angle = Gunner->PutNumber("LiftAngle", new_angle);
    }
}
