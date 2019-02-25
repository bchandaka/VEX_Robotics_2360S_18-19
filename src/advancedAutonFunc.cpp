#include "vars.h"

void liftPID(void* params)
{
	//Setup the constants for the P, I, and D aspects of the control loop
	//constants determined through experimentation
	float kP = 0.28;
	float kI = 0.00000007;
	float kD = 0.05;
	int error;
	int prevError;
	int integral;
	int deriv;
	int power;

	while(true)
	{

		//Checks if the the PID control algorithim should be activated or not
		if (isLiftPID == true){
			//Proportional component, calculates the difference between the desired position and the robot's current position
			error = desiredLiftTicks - pot.get_value();
			if (error<0){
				kP = 0.28;
				kI = 0.00000007;
				kD = 0.05;
			}
			else if (error>0){
				kP = 0.09;
				kI = 0.00000005;
				kD = 0.15;
			}
			if (	desiredLiftTicks < 2100 &&
						pot.get_value() < 2100){
				kP = 0.06;
				kI = 0.00000005;
				kD = 0.18;
			}
			integral += error;
			deriv = error-prevError;
			if (integral > 100){
				integral = 0;
			}
			prevError = error;
			//multiply each component by each its repective constant and send it to the motors
			power = error*kP + integral*kI + deriv * kD;
			//send power to the motors
			runLift(power);
		}
		delay(20);
	}
}
