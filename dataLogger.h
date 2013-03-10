#ifndef DATA_LOGGER_H
#define DATA_LOGGER_H

#include <String>
#include <vector>
#include <fstream>
#include <Vision/ColorImage.h>
#include "Timer.h"
#include "SpeedController.h"
#include "PIDController.h"
#include "target.h"
#include "File.h"

class DataLogger {
public:
    DataLogger();
    ~DataLogger();
    //Logging functions
    void LogShot();
    /*void LogVisionData(vector<Target*>);
    void LogRealityEngineData();
    void LogAutoShot();
    void LogDriveStart(); //Same as record
    void LogDriveStop(); //stops and stores recording
    void SensorDataDump();*/
    void LogCameraImage(string s = "CameraLog");
    /*void LogWheelSpeed();
    void ControllerOutputDump();
    void StartControllerTracking();
    void StopControllerTracking();*/
    void DumpDouble(double,string);
    void DumpInt(int,string);
    void DumpFloat(float,string);
    void DumpBool(bool,string);
    void TrackDouble(double*,string);
    void StopTrackingDouble(double*);
    void updateDoubleTracking();
    void TrackInt(int*,string);
    void StopTrackingInt(int*);
    void updateIntTracking();
    void TrackMotorOutput(SpeedController*,string);
    void StopTrackingMotorOutput(SpeedController*);
    void updateMotorOutputTracking();
    //void TrackFloat(float*,string);
    //void StopTrackingFloat(float*);
    //void updateFloatTracking();
    void TrackBool(bool*,string);
    void StopTrackingBool(bool*);
    void updateBoolTracking();
    /*
    void LogLiftAngleAdjustment();
    void LogRPSofLauncher();
    void LogTeleopStartTime();
    void LogTeleopStopTime();
    void StartAutonomousLogging();
    void StopAutonomousLogging();
    void LogAutonomousStartTime();
    void LogAutonomousEndTime();
    void LogPowerLvl();
    void saveNote(string,string);*/
private:
    Timer systemTimer;
    Timer iterativeTimer;
    //Might
    static const float UPDATE_RATE_TIME = 0.05; //Seconds
    void update();
    static void update_helper(void*);
    //Continous Tracking Variables
        //Floats
    std::vector<float*> fVals;
    std::vector<float> previousFVals;
    std::vector<File*> fValFiles;
        //Ints
    std::vector<int*> iVals;
    std::vector<int> previousIVals;
    std::vector<File*> iValFiles;
        //Bools
    std::vector<bool*> bVals;
    std::vector<bool> previousBVals;
    std::vector<File*> bValFiles; //Todo Optimize space by printing 1 for true and 0 for false
        //Doubles
    std::vector<double*> dVals;
    std::vector<double> previousDVals;
    std::vector<File*> dValFiles;
        //Motors
    std::vector<SpeedController*> mVals;
    std::vector<float> previousMVals;
    std::vector<File*> mValFiles;
};
#endif //DATA_LOGGER_H
