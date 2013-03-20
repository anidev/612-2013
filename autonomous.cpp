#include "autonomous.h"
#include "ports.h"
#include "state.h"
#include "drivetrain.h"
#include "lift.h"
#include "shooter.h"
#include "AutoShooter.h"
#include "launcher.h"
#include "autonomous_presets.h"

int Routine = 4;
//static bool set = false;
bool isDown = false;
bool angleReached = false;

float target_angle = 0;

int state = 1;

float Launcher_Speed = 0.4;

void do_autonomous(){
    if (Routine == 1) {
        static bool set = false;
        static bool inPos = false;
        if(set == false)
        {
            shooter.setSpeed(60.0);
            angleAdjuster.set_angle(5.15);
            set = true;
        }
        else if(angleAdjuster.at_angle())
        {
            if(shooter.atSpeed())
                shooter.setFeederForward();
            else
                shooter.setFeederStop();
            inPos = true;
            angleAdjuster.lift_stop();
        }
        else
        {
            shooter.setFeederStop();
        }
    }
    
    
    else if (Routine == 2) {
        static bool set = false;
        if(set == false)
        {
            shooter.setSpeed(60.0);
            angleAdjuster.lift_down();
            set = true;
            state = 2;
        }
        else if (state == 2) {
            //encoder.reset();
            state = 3;
        }
        else if (state == 3) {
            angleAdjuster.lift_up(/*encoder value*/);
            state = 4;
        }
        if ((state == 4) && (shooter.atSpeed()))
            shooter.setFeederForward();
    }
            
            
    else if (Routine == 3) {
        static bool set = false;
        if(set == false)
        {
            shooter.setSpeed(60.0);
            angleAdjuster.lift_down();
            set = true;
        }
        if(shooter.atSpeed()){
            shooter.setFeederForward();
        }      
    }
    else if (Routine == 4) {
        static bool set = false;
        if(set == false)
    {
        angleAdjuster.lift_up();
        shooter.setSpeed(60.0);
        set = true;
    }
        if(!(((CANJaguar*)(angleAdjuster.liftMotor)) -> GetForwardLimitOK()) || ! (((CANJaguar*)(angleAdjuster.liftMotor)) -> GetReverseLimitOK()))
        {
            angleReached = true;
        }
        if(shooter.atSpeed() && angleReached)
        {
            shooter.setFeederForward();
        }
        else
        {
            shooter.setFeederStop();
        }
}
}
