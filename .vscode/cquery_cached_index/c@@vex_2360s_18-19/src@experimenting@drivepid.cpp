/*
int desiredLeftDriveTicks = driveLeft1.get_position();
int desiredRightDriveTicks = driveRight1.get_position();
bool isDrivePID = true;

void driveTurnPID(double inches){
	int start = millis();
	while(fabs(desiredLeftDriveTicks- driveLeft1.get_position()) > 12 || fabs(desiredRightDriveTicks- driveRight1.get_position()) > 12){
		delay(15);
		if(millis()-start > 5000){
			break;
		}
	}
	desiredLeftDriveTicks = (inches/(4* M_PI))*900 + driveLeft1.get_position();
	desiredRightDriveTicks = (inches/(4* M_PI))*900 + driveRight1.get_position();
}

void driveStraightPID(double inches) // distance in inches
{
	//Setup the constants for the P, I, and D aspects of the control loop
		//constants determined through experimentation
		const float leftkP = 0.2;
		const float leftkI = 0;
		const float leftkD = 0;
		const float rightkP = 0.2;
		const float rightkI = 0;
		const float rightkD = 0;
		int leftError;
		int rightError;
		int leftPrevError = 0 ;
		int rightPrevError = 0;
		int leftIntegral = 0;
		int rightIntegral = 0;
		int leftDeriv;
		int rightDeriv;
		int left_power;
		int right_power;
		isDrivePID = true;
		desiredLeftDriveTicks = (inches/(4* M_PI))*900 + driveLeft1.get_position();
		desiredRightDriveTicks = (inches/(4* M_PI))*900 + driveRight1.get_position();
		while((fabs(desiredLeftDriveTicks- driveLeft1.get_position()) > 12 || fabs(desiredRightDriveTicks- driveRight1.get_position()) > 12))
		{
			if(isDrivePID){
			//driveMutex.take(5000);
			//Proportional component, calculates the difference between the desired position and the robot's current position
			leftError = desiredLeftDriveTicks - driveLeft1.get_position();
			rightError = desiredRightDriveTicks - driveRight1.get_position();
			//Integral component, sums up the errors to account for smaller values of error that cannot be rectified
			leftIntegral += leftError;
			rightIntegral += rightError;
			//Derivative component, predicts future error by taking the difference of the current and previous error, prevents overshoot
			leftDeriv = leftError-leftPrevError;
			rightDeriv = rightError - rightPrevError;
			//resets the integral component if it becomes too high
			if (rightIntegral > 400){
				rightIntegral = 0;
			}
			if (leftIntegral > 400){
				leftIntegral = 0;
			}

			leftPrevError = leftError;
			rightPrevError = rightError;
			//multiply each component by each its repective constant and send it to the motors
			left_power = leftError*leftkP + leftIntegral*leftkI + leftDeriv* leftkD;
			right_power = rightError*rightkP + rightIntegral*rightkI + rightDeriv* rightkD;
			//send power to the motors
			runDriveLeft(left_power);
			runDriveRight(right_power);

			debugMotor(0, driveLeft1, "driveLeft1", 0);
			debugMotor(1, driveLeft2, "driveLeft2", 1);
			debugMotor(2, driveRight1, "driveRight1", 2);
			debugMotor(3, driveRight2, "driveRight2", 3);
			pros::lcd::print(4, "desiredLeft: %d", desiredLeftDriveTicks);
			}
			delay(20);
		}
		runDriveLeft(0);
		runDriveRight(0);
}*/
