#include "../vars.h"
#include <algorithm>
//---------------------Slew Rate Task--------------------
#define MOTOR_NUM               8
#define MOTOR_MAX_VALUE         127
#define MOTOR_MIN_VALUE         (-127)
#define MOTOR_DEFAULT_SLEW_RATE 15      // Default will cause 375mS from full fwd to rev
#define MOTOR_FAST_SLEW_RATE    30	    // Reachs target faster
#define MOTOR_TASK_DELAY        20      // task 1/frequency in mS (about 66Hz)
#define MOTOR_DEADBAND          10

//Array to hold motor objects
Motor motorObj[ MOTOR_NUM ] = {driveLeft1, driveLeft2, driveRight1, driveRight2, flywheel, indexer, intake, descorer};
// Array to hold requested speed for the motors
int motorReq[ MOTOR_NUM ] = {0,0,0,0,0,0,0,0};

// Array to hold "slew rate" for the motors
int motorSlew[ MOTOR_NUM ] = {15, 15, 15, 15, 15, 15, 15, 15};
// Array to hold current motor speed
int motorVolt[ MOTOR_NUM ] = {0,0,0,0,0,0,0,0};

int sign(int x) {
    return (x > 0) - (x < 0);
}
void MotorSlewRateTask(void* params){
    int motorIndex;
		motorSlew[6] = MOTOR_FAST_SLEW_RATE;
    motorSlew[4] = MOTOR_FAST_SLEW_RATE;
    // run task until stopped
    while( true ){
        // run loop for every motor
        for(motorIndex=0; motorIndex<MOTOR_NUM; motorIndex++){
            // So we don't keep accessing the internal storage
            Motor motorTmp =  motorObj[ motorIndex ];
            // Current motor value
            int currentTmp = motorVolt[motorIndex];
            // Update motor value
						if(currentTmp != motorReq[motorIndex]){
							currentTmp += sign(motorReq[motorIndex]-currentTmp) *
													std::clamp(motorSlew[motorIndex], 0, abs(currentTmp-motorReq[motorIndex]));
            }
						motorVolt[motorIndex] = std::clamp(currentTmp, MOTOR_MIN_VALUE, MOTOR_MAX_VALUE);

						// finally send it!
						motorTmp.move(motorVolt[motorIndex]);
        }
        // Wait approx the speed of motor update
        delay( MOTOR_TASK_DELAY );
    }
}
