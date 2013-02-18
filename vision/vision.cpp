#include "vision.h"
#include <vector>
#include "../target.h"
#include <Vision/AxisCamera.h>
#include <Timer.h>
#include <nivision.h>

vision::vision(){
    
}

int vision::vision_entry() {
	AxisCamera* camera=&(AxisCamera::GetInstance("10.6.12.11"));
	while(true) {
		Timer timer;
		timer.Start();
		std::printf("==== BEGIN VISION ITERATION ====\n");
		ColorImage* image=camera->GetImage();
		BinaryImage* binImage=image->ThresholdHSL(100,120,200,255,5,140);
		BinaryImage* convexImage=binImage->ConvexHull(false);
		ParticleFilterCriteria2 criteria[]={{IMAQ_MT_AREA,500,65535,false,false}};
		BinaryImage* filteredImage=binImage->ParticleFilter(criteria,1);
		int numParticles=filteredImage->GetNumberParticles();
		std::printf("Number of particles: %d\n",numParticles);
		for(int i=0;i<numParticles;i++) {
			ParticleAnalysisReport report=filteredImage->GetParticleAnalysisReport(i);
			std::printf("Area for particle %d: %f\n",i,report.particleArea);
		}
		delete image;
		delete binImage;
		delete convexImage;
		delete filteredImage;
		double timeElapsed=timer.Get();
		std::printf("---- TIME TAKEN: %f ----\n",timeElapsed);
	}
}

vision::~vision(){
    
}

double vision::getGroundDist(double angle, double target_height) {
    double length = 9.06;
    double base = 18.64;
    double added_height = (angle > 0)?length+(length*sin(angle)):length-(length*sin(angle));
    double camera_height = base + added_height; 
    return (target_height - camera_height) / tan(angle);
}


