#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include <RobotDrive.h>
#include <GenericHID.h>
#include <SpeedController.h>
#include "auto_encoders.h"
#include "shifter.h"
#include "ports.h"

struct drivetrain_info {
    hw_info left_front;
    hw_info left_rear;
    hw_info right_front;
    hw_info right_rear;
};

// DRIVING = driving forward or backward
// TURNING = swiveling around the center

class DriveTrain {
public:
    static void update_helper(void*);
    DriveTrain(drivetrain_info,encoders_info,hw_info,hw_info);
    ~DriveTrain();
    // manual
    void TankDrive(float,float);
    void ArcadeDrive(GenericHID&);
    // automatic
    void turn(double); //Degrees
    void drive(double);
    void abort();
    double getDrivingDistance();
    double getTurningAngle(); //Target
    bool isManual();
    bool isTurning();
    bool isDriving();
    bool isFinished();
    // shifting
    void shiftHigh();
    void shiftLow();
    shifter::GEAR getGear();
private:
    static const float DRIVE_SPEED = 0.7f;
    static const float TURN_SPEED = 0.7f;
    static const double DIST_TOLERANCE = 3.0f;
    static const double CIRCUMFERENCE = 249.455117704;
    enum operation_t {
        DRIVING,
        TURNING,
        MANUAL
    };
    typedef void (*drive_func)();
    RobotDrive* robotDrive;
    SpeedController* left_front;
    SpeedController* left_rear;
    SpeedController* right_front;
    SpeedController* right_rear;
    auto_encoders encoders;
    shifter shift;
    drive_func currentOperation;
    operation_t operation;
    double left_dist;
    double right_dist;
    double angle;
    bool finished;

    void update();

};

#endif // DRIVETRAIN_H
