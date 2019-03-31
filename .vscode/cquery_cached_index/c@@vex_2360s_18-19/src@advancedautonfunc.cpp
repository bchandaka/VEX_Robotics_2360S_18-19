#include "vars.h"
void flyWheelVelPID(void* params){
	//Setup the constants for the P, I, and D aspects of the control loop
	//constants determined through experimentation
	flywheel.setPIDConst(	0.28,
										0.00000007,
										0.05);
	int lastPos;
	int curPos;
	double velocity;
	int error;
	int prevError;
	int integral;
	int deriv;
	int power;

	while(true){
		if(isFlyPID == true){
			/*
			lastPos = flywheel.getPosition();
			delay(20);
			curPos = flywheel.getPosition();
			velocity  = (((curPos-lastPos)/900)*5)/0.000333333333333;//in rpm
			*/
			velocity = (flywheel.getMtr()).get_actual_velocity();
			lcd::print(0, "Flywheel Vel %f", velocity);
			error = desiredFlywheelVel - velocity;
			integral += error;
			deriv = error-prevError;
			if (integral > 100){
				integral = 0;
			}
			prevError = error;
			//multiply each component by each its repective constant and send it to the motors
			power = flywheel.calcPID(error, integral,deriv);
			//send power to the motors
			flywheel.run(power);
		}
	}
}
void liftPID(void* params)
{
	//Setup the constants for the P, I, and D aspects of the control loop
	//constants determined through experimentation
	lift.setPIDConst(	0.28,
										0.00000007,
										0.05);
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
			error = desiredLiftTicks - lift.getPosition();
			if (error<0){
				lift.setPIDConst(	0.28,
													0.00000007,
													0.05);
			}
			else if (error>0){
				lift.setPIDConst(	0.09,
													0.00000005,
													0.15);
			}
			if (	desiredLiftTicks < 2100 &&
						lift.getPosition() < 2100){
				lift.setPIDConst(	0.06,
													0.00000005,
													0.18);
			}
			integral += error;
			deriv = error-prevError;
			if (integral > 100){
				integral = 0;
			}
			prevError = error;
			//multiply each component by each its repective constant and send it to the motors
			power = lift.calcPID(error, integral,deriv);
			//send power to the motors
			lift.run(power);
		}
		delay(20);
	}
}
