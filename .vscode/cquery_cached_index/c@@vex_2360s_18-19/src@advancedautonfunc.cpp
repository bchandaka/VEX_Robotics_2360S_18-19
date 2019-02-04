#include "vars.h"

void liftPID(void* params)
{
	//Setup the constants for the P, I, and D aspects of the control loop
	//constants determined through experimentation
	const float kP = 0.007;

	int error;

	int power;
	while(true)
	{
		//Checks if the the PID control algorithim should be activated or not
		if (isLiftPID == true){
			//Proportional component, calculates the difference between the desired position and the robot's current position
			error = desiredLiftTicks - lift.get_position();
			//multiply each component by each its repective constant and send it to the motors
			power = 80* atan(error*kP);
			//send power to the motors
			runLift(power);

		}
		delay(15);
	}
}
