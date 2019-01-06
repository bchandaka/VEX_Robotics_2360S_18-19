#include "../vars.h"
//-----------------Auton Drive FUnctions----------------

void driveStraight(double dist) // distance in inches
{
	gyro.reset();
	int gyroError = 0-gyro.get_value();
	double gyroKp = 0.1;
	int speed = 0;
	int baseSpeed = 0;
	double currentPos = (driveLeft1.get_position() + driveRight1.get_position())/2.0;
	double desiredDriveTicks = (dist/(4* M_PI))*900 + currentPos;
	while (fabs(desiredDriveTicks - currentPos) > 12) {
		debugMotor(0, driveLeft1, "driveLeft1", 0);
		debugMotor(1, driveLeft2, "driveLeft2", 1);
		debugMotor(2, driveRight1, "driveRight1", 2);
		debugMotor(3, driveRight2, "driveRight2", 3);
		speed = 80* atan(0.0015 * (desiredDriveTicks - currentPos)); //Decreases power gradually when the current position approaches the desired position
		baseSpeed = 10*((speed > 0) - (speed < 0));
		runDriveLeft(speed + baseSpeed); //- (gyroError *gyroKp));
		runDriveRight(speed + baseSpeed); //+ (gyroError*gyroKp));
		currentPos = (driveLeft1.get_position() + driveRight1.get_position())/2.0;
		gyroError = 0-gyro.get_value();
		delay(20);
	}
	runDriveLeft(0);
	runDriveRight(0);
}

void turnAngle(float angle){
  gyro.reset();
	bool rightTurn = angle > 0;

	float previous = gyro.get_value() / 10.0;
	float current = gyro.get_value() / 10.0;
	float sum = 0;
	float angleDifference = angle;

	const int speed = 85;
	int baseLeftSpeed = 15;
	int baseRightSpeed = 15;
	float leftSpeed = autonBlue ? (rightTurn ? -speed : speed):(rightTurn ? speed : -speed);
	float rightSpeed = -leftSpeed;

	const float K = 0.018;

	while( fabs(sum) < fabs(angle)-1 ) {
    lcd::print(5, "Gyro Value: %f", gyro.get_value());

		previous = current;
		current = gyro.get_value() / 10.0;
		sum += current - previous;
		baseRightSpeed = 15*((rightSpeed > 0) - (rightSpeed < 0));
		baseLeftSpeed = 15*((leftSpeed > 0) - (leftSpeed < 0));
		angleDifference = fabs(angle) - fabs(sum);
		//std::clamp((int)(rightSpeed * atan(K * fabs(angleDifference))), 20,speed)
		runDriveLeft( leftSpeed * atan(K * fabs(angleDifference)) + baseLeftSpeed);
		runDriveRight( rightSpeed * atan(K * fabs(angleDifference)) + baseRightSpeed);
		delay(20);
	}
	runDriveLeft(0);
	runDriveRight(0);
}
