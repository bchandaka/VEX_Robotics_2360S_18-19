#ifndef _PROS_AUTONDRIVEFUNCTIONS_HPP_
#define _PROS_AUTONDRIVEFUNCTIONS_HPP_
/*#include "motorFunctions.hpp"

#include <math.h>
void drive_straight(float dist) // distance in inches
{
	int desiredDriveTicks = (dist/(4* M_PI))*900 + driveLeft1.get_position();
	while (abs(desiredDriveTicks + driveLeft1.get_position()) > 12) {
		runDriveLeft(80* atan(0.009 * (desiredDriveTicks - driveLeft1.get_position())));
		runDriveRight(80* atan(0.009 * (desiredDriveTicks + driveLeft1.get_position())));
	}
	runDriveLeft(0);
	runDriveRight(0);
}

void turnDegrees(float angle){

	bool rightTurn = angle > 0;

	float previous = gyro.get_value() / 10.0;
	float current = gyro.get_value() / 10.0;
	float sum = 0;
	float angleDifference = angle;

	const float speed = 80;
	float leftSpeed = rightTurn ? speed : -speed;
	float rightSpeed = -leftSpeed;

	const float K = 0.05;

	while( fabs(sum) < fabs(angle-3) ) {

		previous = current;
		current = gyro.get_value() / 10.0;
		sum += current - previous;

		angleDifference = fabs(angle) - fabs(sum);

		runDriveLeft( leftSpeed * atan(K * fabs(angleDifference) ));
		runDriveRight( rightSpeed * atan(K * fabs(angleDifference) ));

	}
	runDriveLeft(0);
	runDriveRight(0);
}
*/
#endif
