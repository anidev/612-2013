#include <Timer.h>
#include <Vision/AxisCamera.h>
#include <Vision/ColorImage.h>
#include <Vision/BinaryImage.h>
#include <networktables/NetworkTable.h>
#include <nivision.h>
#include "main.h"
#include "vision.h"

int vision_entry(...) {
	AxisCamera* camera=&(AxisCamera::GetInstance("10.6.12.11"));
	NetworkTable* trackingTable=NULL;
	while(true) {
//		Timer timer;
//`		timer.Start();
		if(robot_class::mainTable!=NULL) {
			trackingTable=(robot_class::mainTable)->GetSubTable("Tracking");
			if(trackingTable==NULL) {
				std::printf("Failed to get 612/Tracking network table.\n");
			}
		}
		ColorImage* image=camera->GetImage();
		if(image==NULL) {
			std::printf("Failed to acquire camera image.\n");
			continue;
		}
		BinaryImage* binImage=image->ThresholdHSL(100,120,100,255,34,140);
		if(binImage==NULL) {
			std::printf("Failed to threshold color image.\n");
			delete image;
			continue;
		}
		BinaryImage* convexImage=binImage->ConvexHull(false);
		if(convexImage==NULL) {
			std::printf("Failed to execute convex hull.\n");
			delete binImage;
			delete image;
		}
		ParticleFilterCriteria2 criteria[]={{IMAQ_MT_AREA,400,65535,false,false}};
		BinaryImage* filteredImage=binImage->ParticleFilter(criteria,1);
		if(filteredImage==NULL) {
			std::printf("Failed to filter particles.\n");
			delete convexImage;
			delete binImage;
			delete image;
		}
		int numParticles=filteredImage->GetNumberParticles();
		if(numParticles>0) {
			ParticleAnalysisReport report=filteredImage->GetParticleAnalysisReport(0);
			Rect partRect=report.boundingRect;
			if(trackingTable!=NULL) {
				trackingTable->PutBoolean("Available",true);
				trackingTable->PutNumber("X",partRect.left);
				trackingTable->PutNumber("Y",partRect.top);
				trackingTable->PutNumber("Width",partRect.width);
				trackingTable->PutNumber("Height",partRect.height);
			}
			std::printf("Particle 1 X,Y: %d\t,%d\n",report.center_mass_x,report.center_mass_y);
//			std::printf("Particle 1 bbox width: %d\n",report.boundingRect.width);
		} else {
			if(trackingTable!=NULL) {
				trackingTable->PutBoolean("Available",false);
			}
			std::printf("No particles found\n");
		}
		delete image;
		delete binImage;
		delete convexImage;
		delete filteredImage;
//		double timeElapsed=timer.Get();
//		std::printf("---- TIME TAKEN: %f ----\n",timeElapsed);
	}
}
