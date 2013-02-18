#include <cstdio>
#include <Relay.h>
#include <networktables/NetworkTable.h>
#include "vision.h"
#include "main.h"

NetworkTable* robot_class::mainTable=NULL;

robot_class::robot_class():/*launcher(2,1),feeder(2,2),joy(1),joy2(2)/*,encoder(2,1,2,2)*//*,ledgreen(2,1),ledred(2,3),visionTask("Vision Task",&vision_entry),*/launcherSensor(1,14)/*,gunnerTable(NULL)*/ {
/*	robot_class::mainTable=NetworkTable::GetTable("612");
	if(robot_class::mainTable==NULL) {
		std::printf("Failed to get 612 network table.\n");
	}
//	encoder.Start();*/
	launcherSensor.Start();
/*	usinggreen=true;
	usingred=false;
	usingboth=true;
	pressed6=false;
	pressed7=false;*/
}

robot_class::~robot_class() {
}

void robot_class::RobotInit() {
}

void robot_class::DisabledInit() {
/*	visionTask.Stop();
	if(robot_class::mainTable!=NULL) {
		robot_class::mainTable->PutBoolean("Tracking/Available",false);
	}
	launcher.Set(0.0f);
	feeder.Set(0.0f);
	ledgreen.Set(Relay::kOff);
	ledred.SetRaw(0);
	usinggreen=true;
	usingboth=false;*/
}

void robot_class::TeleopInit() {
//	visionTask.Start();
}

void robot_class::TeleopPeriodic() {
	static int counter=0;
//	float launcherAxis=(joy.GetZ()*-1+1)/2.0f;
//	float launcherAxis=joy.GetY();
//	float feederAxis=joy2.GetY();
	if(counter%20==0) {
//		std::printf("Infrared: %f\n",infrared.GetVoltage());
//		std::printf("feeder: %f\n",feederAxis);
//		std::printf("PWM: %f\n",launcherAxis);
		std::printf("Hall Effect: %d\n",launcherSensor.Get());
//		std::printf("Hall Effect Freq: %f\n",1.0/launcherSensor.GetPeriod());
	}
	counter++;
/*	if(robot_class::mainTable!=NULL) {
		if(gunnerTable==NULL) {
			gunnerTable=robot_class::mainTable->GetSubTable("Gunner");
			if(gunnerTable==NULL) {
				std::printf("Failed to get 612/Gunner network table\n");
			}
		}
		if(gunnerTable!=NULL) {
			gunnerTable->PutNumber("LauncherTarget",launcherAxis);
			gunnerTable->PutNumber("LauncherCurrent",1.0/launcherSensor.GetPeriod());
		}
	}
	if(joy.GetRawButton(1)) {
		launcher.Set(launcherAxis);
	} else {
		launcher.Set(0.0f);
	}
	feeder.Set(feederAxis);
	float ledbright=(joy2.GetZ()*-1+1)/2.0f;
/*	if(usingred) {
		ledred.Set(1.0f);
	} else {
		ledred.Set(0.0f);
	}*//*
	if(usinggreen) {
		ledgreen.Set(Relay::kForward);
		ledred.SetRaw(0);
	} else {
		ledgreen.Set(Relay::kOff);
		ledred.Set(1.0f);
	}
	if(joy.GetRawButton(6)&&!pressed6) {
		pressed6=true;
		usinggreen=!usinggreen;
//		usingred=!usingred;
	}
/*	if(joy.GetRawButton(7)&&!pressed7) {
		pressed7=true;
		usinggreen=usingboth;
		usingred=usingboth;
		usingboth=!usingboth;
	}*//*
	if(!joy.GetRawButton(6)&&pressed6) {
		pressed6=false;
	}
/*	if(!joy.GetRawButton(7)&&pressed7) {
		pressed7=false;
	}*/
}

START_ROBOT_CLASS(robot_class)
