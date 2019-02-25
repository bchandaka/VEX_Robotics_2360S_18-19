#include "vars.h"
#include <algorithm>



//-----------------Auton Drive FUnctions----------------
void driveStraightPID(double rightInches, double leftInches) // distance in inches
{
	//Setup the constants for the P, I, and D aspects of the control loop
		//constants determined through experimentation
		const float leftkP = 0.182;//.182
		const float leftkI = 0.01;
		const float leftkD = 0.22;//.2
		const float rightkP = 0.169;//.17
		const float rightkI = 0.01;
		const float rightkD = 0.24;//.2
		int leftError;
		int rightError;

		int leftIntegral = 0;
		int rightIntegral = 0;
		int leftDeriv;
		int rightDeriv;
		double left_power;
		double right_power;
		driveLeft1.tare_position();
		driveRight1.tare_position();

		double desiredLeftDriveTicks = (rightInches/(4* M_PI))*900;
		double desiredRightDriveTicks = (leftInches/(4* M_PI))*900;
		int leftPrevError = desiredLeftDriveTicks - driveLeft1.get_position();
		int rightPrevError = desiredRightDriveTicks - driveRight1.get_position();
		while((fabs(desiredLeftDriveTicks- driveLeft1.get_position()) > 9 || fabs(desiredRightDriveTicks- driveRight1.get_position()) > 9))
		{
				delay(15);
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
				if (abs(rightIntegral) > 600){
					rightIntegral = 0;
				}
				if (abs(leftIntegral) > 600){
					leftIntegral = 0;
				}

				leftPrevError = leftError;
				rightPrevError = rightError;
				//multiply each component by each its repective constant and send it to the motors
				//left_power = leftError*leftkP + leftIntegral*leftkI + leftDeriv* leftkD; //std::clamp(int(leftError*leftkP + leftIntegral*leftkI + leftDeriv* leftkD), -127, 127);
				//right_power = rightError*rightkP + rightIntegral*rightkI + rightDeriv* rightkD;//std::clamp(int(rightError*rightkP + rightIntegral*rightkI + rightDeriv* rightkD), -127,127);
				left_power = std::clamp(int(leftError*leftkP + leftIntegral*leftkI + leftDeriv* leftkD), -121, 121);
				right_power = std::clamp(int(rightError*rightkP + rightIntegral*rightkI + rightDeriv* rightkD), -118,118);
				//send power to the motors
				runDriveLeft(left_power);
				runDriveRight(right_power);
				printf("leftPower: %f\n", left_power);
				printf("rightPower: %f\n", right_power);

				debugMotor(0, driveLeft1, "driveLeft1", 0);
				debugMotor(1, driveLeft2, "driveLeft2", 1);
				debugMotor(2, driveRight1, "driveRight1", 2);
				debugMotor(3, driveRight2, "driveRight2", 3);
				pros::lcd::print(4, "desiredLeft: %f", desiredLeftDriveTicks);
				pros::lcd::print(5, "desiredRight: %f", desiredRightDriveTicks);
				/*if(driveLeft1.get_actual_velocity() == 0 || driveRight1.get_actual_velocity() == 0){
					break;
				}
				*/

		}
		runDriveLeft(0);
		runDriveRight(0);
}
void curveTurn(double radius, double degrees){
	double rightInches = 2 * (degrees/360) * M_PI * (radius -7);
	double leftInches = 2 * (degrees/360) * M_PI * (radius +7);
	printf("rightInches %f", rightInches);
	driveStraightPID(rightInches,  leftInches);

}
void driveStraight(double dist) // distance in inches
{
	double currentPos = (driveLeft1.get_position() + driveRight1.get_position())/2.0;
	int desiredDriveTicks = (dist/(4* M_PI))*900 + currentPos;
	int speed = 80* atan(0.0015 * (desiredDriveTicks - currentPos));
	const int baseSpeed = 20*((speed > 0) - (speed < 0));

	const double gyroKp = 0.005;
	int gyroError = 0-gyro.get_value();
	int start = millis();
	while (fabs(desiredDriveTicks - currentPos) > 9) {
		debugMotor(0, driveLeft1, "driveLeft1", 0);
		debugMotor(1, driveLeft2, "driveLeft2", 1);
		debugMotor(2, driveRight1, "driveRight1", 2);
		debugMotor(3, driveRight2, "driveRight2", 3);

		speed = 80* atan(0.0015 * (desiredDriveTicks - currentPos)); //Decreases power gradually when the current position approaches the desired position
		runDriveLeft(speed + baseSpeed);// - (gyroError *gyroKp));
		runDriveRight(speed + baseSpeed);// + (gyroError*gyroKp));

		delay(20);
		lcd::print(4, "desiredTicks: %d", desiredDriveTicks);
		lcd::print(5, "gyroError: %d", gyroError);

		currentPos = (driveLeft1.get_position() + driveRight1.get_position())/2.0;
		gyroError = 0-gyro.get_value();
		if(millis()-start > 600 && (driveLeft1.get_actual_velocity() == 0 &&  driveRight1.get_actual_velocity() == 0 )){
			break;
		}
	}
	runDriveLeft(0);
	runDriveRight(0);
}

void turnAngle(float angle){
	bool rightTurn = angle > 0;

	float previous = gyro.get_value() / 10.0;
	float current = gyro.get_value() / 10.0;
	float sum = 0;
	float angleDifference = angle;

	const int speed = 85;

	float leftSpeed = autonBlue ? (rightTurn ? -speed : speed):(rightTurn ? speed : -speed);
	float rightSpeed = -leftSpeed;
	const int baseRightSpeed = 17*((rightSpeed > 0) - (rightSpeed < 0));
	const int baseLeftSpeed = 17*((leftSpeed > 0) - (leftSpeed < 0));

	const float K = 0.0179;
	int start = millis();
	while( fabs(sum) < fabs(angle)-1 ) {
    lcd::print(5, "Gyro Value: %f", gyro.get_value());

		previous = current;
		current = gyro.get_value() / 10.0;
		sum += current - previous;

		angleDifference = fabs(angle) - fabs(sum);
		//std::clamp((int)(rightSpeed * atan(K * fabs(angleDifference))), 20,speed)
		runDriveLeft( leftSpeed * atan(K * fabs(angleDifference)) + baseLeftSpeed);
		runDriveRight( rightSpeed * atan(K * fabs(angleDifference)) + baseRightSpeed);
		delay(20);
		if(millis()-start > 600 && (driveLeft1.get_actual_velocity() == 0 &&  driveRight1.get_actual_velocity() == 0 )){
			break;
		}
	}
	runDriveLeft(0);
	runDriveRight(0);
}
