#ifndef _PROS_SLEWRATE_HPP_
#define _PROS_SLEWRATE_HPP_
#include "api.h"
using namespace pros;
#include "portInitialize.hpp"
#define MOTOR_NUM               8
#define MOTOR_MAX_VALUE         127
#define MOTOR_MIN_VALUE         (-127)
#define MOTOR_DEFAULT_SLEW_RATE 10      // Default will cause 375mS from full fwd to rev
#define MOTOR_FAST_SLEW_RATE    256     // essentially off
#define MOTOR_TASK_DELAY        15      // task 1/frequency in mS (about 66Hz)
#define MOTOR_DEADBAND          10

//Array to hold motor objects
// Array to hold requested speed for the motors
int motorReq[ MOTOR_NUM ];

// Array to hold "slew rate" for the motors, the maximum change every time the task
// runs checking current mootor speed.
int motorSlew[ MOTOR_NUM ];

void MotorSlewRateTask(Motor* motorObj){
    int motorIndex;
    // Initialize stuff
    for(motorIndex=0;motorIndex<MOTOR_NUM;motorIndex++){
      motorReq[motorIndex] = 0;
      motorSlew[motorIndex] = MOTOR_DEFAULT_SLEW_RATE;
    }

    // run task until stopped
    while( true ){
        // run loop for every motor
        for(motorIndex=0; motorIndex<MOTOR_NUM; motorIndex++){
            // So we don't keep accessing the internal storage
            Motor motorTmp = motorObj[ motorIndex ];
            int voltageTmp = (motorTmp.get_voltage() / 12000) * 127;
            // Do we need to change the motor value ?
            if( voltageTmp != motorReq[motorIndex]){
                // increasing motor value
                if( motorReq[motorIndex] > voltageTmp ){
                    voltageTmp += motorSlew[motorIndex];
                    // limit
                    if( voltageTmp > motorReq[motorIndex] )
                        voltageTmp = motorReq[motorIndex];
                }

                // decreasing motor value
                if( motorReq[motorIndex] < voltageTmp ){
                    voltageTmp -= motorSlew[motorIndex];
                    // limit
                    if( voltageTmp < motorReq[motorIndex] )
                        voltageTmp = motorReq[motorIndex];
                }
                // finally set motor
                motorTmp.move(voltageTmp);

            }
        }

        // Wait approx the speed of motor update over the spi bus
        delay( MOTOR_TASK_DELAY );
    }
}
#endif
