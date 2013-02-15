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

double NetworkCom::Autonomous_Position () {
    if(Autonomous==NULL) {
        return 1.0;
    }
    return Autonomous -> GetNumber ("Position");
}

double NetworkCom::Autonomous_Target () {
    if (Autonomous==NULL) {
        return 1.0;
    }
    return Autonomous -> GetNumber ("Target");
}

//if null end function
void NetworkCom::target_available (bool target){
    if(Tracking != NULL){
        if (target != Tracking->GetBoolean("Available")) {
            Tracking->PutBoolean ("Available", target);
        }
    }
}
void NetworkCom::target_x (double new_target){
    if(Tracking != NULL){
        if (new_target != Tracking->GetNumber("X")) {
            Tracking->PutNumber("X", new_target);
        }
    }
}
void NetworkCom::target_y (double new_target){
    if(Tracking != NULL){
        if (new_target != Tracking->GetNumber("Y")) {
            Tracking->PutNumber("Y", new_target);
        }
    }
}
void NetworkCom::target_width (double new_target){
    if(Tracking != NULL){
        if (new_target != Tracking->GetNumber("Width")) {
            Tracking->PutNumber("Width", new_target);
        }
    }
}
void NetworkCom::target_height (double new_target){
    if(Tracking != NULL){
        if (new_target != Tracking->GetNumber("Height")) {
            Tracking->PutNumber("Height", new_target);
        }
    }
}
void NetworkCom::launcher_target_speed (double new_speed){
    if(Tracking != NULL){
        if (new_speed != Gunner->GetNumber("LauncherTarget")) {
            Gunner->PutNumber("LauncherTarget", new_speed);
        }
    }
}
void NetworkCom::launcher_current_speed (double cur_speed){
    if(Tracking !=NULL){
        if (cur_speed != Gunner->GetNumber("LauncherCurrent")) {
            Gunner->PutNumber("LauncherCurrent", cur_speed);
        }
    }
}
void NetworkCom::lift_angle (float new_angle){
    if(Tracking !=NULL){
        if (new_angle != Gunner->GetNumber("LiftAngle")) {
            Gunner->PutNumber("LiftAngle", new_angle);
        }
    }
}
