#include "vars.h"
#include <algorithm>
void ballTracker(void* params){
	indexer.setIsPID(true);
	indexer.setSlew(127);
	intake.setSlew(127);
	bool secondBall = false;
	bool bottomBall = false;
	while(true){
		if (master.get_digital(E_CONTROLLER_DIGITAL_L1)){
			indexer.run(127);
		}
		else if (master.get_digital(E_CONTROLLER_DIGITAL_L2)){
			indexer.run(-127);
			/*
			indexer.run(127);
			bool firstFalse = false;
			int start = millis();
			while(true){
				if(topLimit.get_value() == 0){
					firstFalse = true;
				}
				printf("%d\n",firstFalse);

				if(firstFalse && topLimit.get_value()){
					printf("break \n");
					break;

				}
				if(millis() - start > 1000){
					printf("Time break \n");

					break;
				}
				delay(20);
			}
			indexer.run(0);
			*/
		}
		/*
		else if (master.get_digital(E_CONTROLLER_DIGITAL_L1) &&
							topLimit.get_value()){
			indexer.run(127);
			bool firstFalse = 0;
			bool secondTrue = 0;
			int start = millis();
			while(!(firstFalse && secondTrue)){
				if(topLimit.get_value() == 0){
					firstFalse = 1;
				}
				if(firstFalse && topLimit.get_value()){
					secondTrue = 1;
					printf("%d",secondTrue);
				}
				if(millis() - start > 5000){
					break;
				}
				delay(20);
			}
			indexer.run(0);
		}
		*/
		else if (topLimit.get_value()){
			indexer.run(0);
			secondBall = true;
		}
		else if (bottomLimit.get_value()){
			//intake.run(-127);
			//delay(100);
			//intake.run(0);
			indexer.run(80);
		}
		else{
			indexer.run(0);
		}
		delay(20);
	}
}

void flyWheelVelPID(void* params){
	//Setup the constants for the P, I, and D aspects of the control loop
	//constants determined through experimentation
	flywheel.setPIDConst(	0.00025,
												0.0,
												0.0);
	double tbh = 0;
	double velocity;
	int error;
	int prevError;
	bool firstCross = true;
	double target = flywheel.getTarget();
	double lastTarget = flywheel.getTarget();
	double power;
	while(true){
		if(flywheel.isPID()){
			target = flywheel.getTarget();
			//approximate speed at which new target can be achieved
			if(target != lastTarget){
				tbh = (target/600) * 127;
				firstCross = true;
				power = tbh;
			}
			lastTarget = target;
			velocity = (flywheel.getMtr()).get_actual_velocity();
			error = target - velocity;                // calculate the error;
			power += flywheel.getkP() * error;  // Integrate error
			if (power>127){
				power = 127;
			}
			if(power<0){
				power = 0;
			}
			if(std::signbit(error) != std::signbit(prevError)){
				//Set estimate power at first overshoot/undershoot
				if(firstCross){
					power = tbh;
					firstCross = false;
				}

				else{
					power = 0.5 * (power + tbh);
				}
				tbh = power; // new approximate
			}
			prevError = error;
			//send power to the motors
			flywheel.run(power);
		}
		lcd::print(7, "TBH: %f, power: %f", tbh, power);
		lcd::print(5, "Flywheel Vel %f", velocity);
		flywheel.debug(6);
		delay(30);
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
		if (lift.isPID()){
			//Proportional component, calculates the difference between the desired position and the robot's current position
			error = lift.getTarget() - lift.getPosition();
			if (error>0){
				lift.setPIDConst(	0.28,
													0.00000007,
													0.05);
			}
			else if (error<0){
				lift.setPIDConst(	0.09,
													0.00000005,
													0.15);
			}
			if (	lift.getTarget() > 1300 &&
						lift.getPosition() > 1300){
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
			lift.run(-power);
			/*
			if(lift.getPosition() > 800 && lift.getPosition() <4000){
			}
			else{
				lift.run(0);
			}
			*/
		}
		delay(20);
	}
}
