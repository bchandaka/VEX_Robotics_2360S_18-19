#include "vars.h"
#include <algorithm>



//-----------------Auton Drive FUnctions----------------
void driveStraightPID(double inches) // distance in inches
{
	//Setup the constants for the P, I, and D aspects of the control loop
		//constants determined through experimentation
		const float leftkP = 0.17;//.182
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
		(leftDrive.getMtr()).tare_position();
		(rightDrive.getMtr()).tare_position();

		double desiredLeftDriveTicks = (inches/(4* M_PI))*900;
		double desiredRightDriveTicks = (inches/(4* M_PI))*900;
		int leftPrevError = desiredLeftDriveTicks - leftDrive.getPosition();
		int rightPrevError = desiredRightDriveTicks - rightDrive.getPosition();

		const double gyroKp = 0.005;
		int gyroError = 0;
		int initialGyro = gyro.get_value();
		int start = millis();
		while((fabs(desiredLeftDriveTicks- leftDrive.getPosition()) > 7 && fabs(desiredRightDriveTicks- rightDrive.getPosition()) > 7))
		{
				delay(15);
				//Proportional component, calculates the difference between the desired position and the robot's current position
				leftError = desiredLeftDriveTicks - (leftDrive.getPosition()+rightDrive.getPosition())/2.0;
				rightError = desiredRightDriveTicks - rightDrive.getPosition();
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
				left_power = std::clamp(int(leftError*leftkP + leftIntegral*leftkI + leftDeriv* leftkD), -114, 114);
				right_power = std::clamp(int(rightError*rightkP + rightIntegral*rightkI + rightDeriv* rightkD), -114,114);
				//send power to the motors
				leftDrive.run(left_power); //- (gyroError *gyroKp));
				rightDrive.run(right_power);//+ (gyroError *gyroKp));
				printf("leftPower: %f\n", left_power);
				printf("rightPower: %f\n", right_power);
				if(millis()-start > 300 && ((leftDrive.getMtr()).get_actual_velocity() == 0 &&  (rightDrive.getMtr()).get_actual_velocity() == 0 )){
					break;
				}
				gyroError = initialGyro-gyro.get_value();
		}
		leftDrive.run(0);
		rightDrive.run(0);
}
void curveTurn(double radius, double degrees){
	double rightInches = 2 * (degrees/360) * M_PI * (radius -7);
	double leftInches = 2 * (degrees/360) * M_PI * (radius +7);
	printf("rightInches %f", rightInches);

}
void driveStraight(double dist) // distance in inches
{
	double currentPos = (leftDrive.getPosition() + rightDrive.getPosition())/2.0;
	int desiredDriveTicks = (dist/(4* M_PI))*900 + currentPos;
	int speed = 80* atan(0.0015 * (desiredDriveTicks - currentPos));
	const int baseSpeed = 20*((speed > 0) - (speed < 0));

	const double gyroKp = 0.005;
	int gyroError = 0-gyro.get_value();
	int start = millis();
	while (fabs(desiredDriveTicks - currentPos) > 9) {

		speed = 80* atan(0.0015 * (desiredDriveTicks - currentPos)); //Decreases power gradually when the current position approaches the desired position
		leftDrive.run(speed + baseSpeed);// - (gyroError *gyroKp));
		rightDrive.run(speed + baseSpeed);// + (gyroError*gyroKp));

		delay(20);
		lcd::print(4, "desiredTicks: %d", desiredDriveTicks);
		lcd::print(5, "gyroError: %d", gyroError);

		currentPos = (leftDrive.getPosition() + rightDrive.getPosition())/2.0;
		gyroError = 0-gyro.get_value();
		if(millis()-start > 600 && ((leftDrive.getMtr()).get_actual_velocity() == 0 &&  (rightDrive.getMtr()).get_actual_velocity() == 0 )){
			break;
		}
	}
	leftDrive.run(0);
	rightDrive.run(0);
}
void faceAngle(double target){
	float newAngle = (target - gyro.get_value()/10.0);
	if (newAngle > 180){
		newAngle = 180-newAngle;
	}
	else if (newAngle < -180){
		newAngle = -180-newAngle;
	}
	turnAngle(newAngle);
}
void turnAngle(float angle){
	bool rightTurn = angle > 0;

	float previous = gyro.get_value() / 10.0;
	float current = gyro.get_value() / 10.0;
	float sum = 0;
	float angleDifference = angle;

	const int speed = 80;

	float leftSpeed = autonBlue ? (rightTurn ? -speed : speed):(rightTurn ? speed : -speed);
	float rightSpeed = -leftSpeed;
	const int baseRightSpeed = 20*((rightSpeed > 0) - (rightSpeed < 0));
	const int baseLeftSpeed = 20*((leftSpeed > 0) - (leftSpeed < 0));

	const float K = 0.0179;
	int start = millis();
	while( fabs(sum) < fabs(angle)-1 ) {
    lcd::print(5, "Gyro Value: %f", gyro.get_value());

		previous = current;
		current = gyro.get_value() / 10.0;
		sum += current - previous;

		angleDifference = fabs(angle) - fabs(sum);
		//std::clamp((int)(rightSpeed * atan(K * fabs(angleDifference))), 20,speed)
		leftDrive.run( leftSpeed * atan(K * fabs(angleDifference)) + baseLeftSpeed);
		rightDrive.run( rightSpeed * atan(K * fabs(angleDifference)) + baseRightSpeed);
		delay(20);
		if(millis()-start > 300 && ((leftDrive.getMtr()).get_actual_velocity() == 0 &&  (rightDrive.getMtr()).get_actual_velocity() == 0 )){
			break;
		}
	}
	leftDrive.run(0);
	rightDrive.run(0);
}
