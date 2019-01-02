/*
const float TICKS = 900; //for default motors
const float WHEEL_DIAMETER = 4.; //in inches
//this number is sort of just an estimation based off of watching the robot turn and should be improved

//fix this calculation given that only the two back wheels are driven
const float CIRCUMFERENCE = M_PI * 21; //pi * approx. size of robot from diagnol corners

float x = 0.;
float y = 0.;
float z = 0.;
float inch = 0.;

void driveInches(float distance) {

	//direction multipliers
	const int DIRECTION_MULTIPLIER = distance > 0 ? 1 : -1;

	//acceleration constants
	const int MAX_ACCELERATION = 20;

	//minimum and maximum speeds
	const int MAX_SPEED = 127;
	const int MIN_SPEED = 32;

	//distance thresholds for peiceweise function
	const float MIN_THRESHOLD = 1.;
	const float MAX_THRESHOLD = 6.;

	//undershoot constant in case the robot tends to drift a consistant amount past its target
	//const float UNDERSHOOT = 0.

	//distance -= UNDERSHOOT;

	//reset encoders
	driveLeft1.tare_position();
	driveRight1.tare_position();

	//position data
	float ticks = (fabs(driveLeft1.get_position()) + fabs(driveRight1.get_position())) / 2.0;
	float inches = ticks / TICKS * WHEEL_DIAMETER * M_PI;

	//speed variables
	int targetSpeed = 0;
	int currentSpeed = 0;

	while( inches < fabs(distance) ) {

		//update position data
		float ticks = (fabs(driveLeft1.get_position()) + fabs(driveRight1.get_position())) / 2.0;
		float inches = ticks / TICKS * WHEEL_DIAMETER * M_PI;

		//adjust target speed
		if(fabs(distance) - inches >= MAX_THRESHOLD) {
			targetSpeed = MAX_SPEED * DIRECTION_MULTIPLIER;
		} else if(fabs(distance) - inches > MIN_THRESHOLD) {
			//nasty line of code - implements the sloped part of the peicewise function
			targetSpeed = (int) ((MIN_SPEED + (MAX_SPEED-MIN_SPEED) * (fabs(distance) - inches - MIN_THRESHOLD) / (MAX_THRESHOLD - MIN_THRESHOLD)) * DIRECTION_MULTIPLIER);
		} else {
			targetSpeed = MIN_SPEED * DIRECTION_MULTIPLIER;
		}

		//acceleration calculation
		if(targetSpeed > currentSpeed) {

			if(targetSpeed <= currentSpeed + MAX_ACCELERATION) {
				currentSpeed = targetSpeed;
			} else {
				currentSpeed += MAX_ACCELERATION;
			}

		} else if(targetSpeed < currentSpeed) {

			if(targetSpeed >= currentSpeed - MAX_ACCELERATION) {
				currentSpeed = targetSpeed;
			} else {
				currentSpeed -= MAX_ACCELERATION;
			}

		}

		//override acceleration code
		//currentSpeed = targetSpeed;

		//update motor speeds
		runDriveLeft(currentSpeed);
		runDriveRight(currentSpeed);

		//globals for debugging
		//x = targetSpeed;
		//y = currentSpeed;
		//inch = inches;

		delay(20);

	}

	//stop the robot
	runDriveLeft(0);
	runDriveRight(0);

}


//
void turnDegrees(float angle) {

	//direction multiplier
	const int DIRECTION_MULTIPLIER = angle > 0 ? 1 : -1;

	//acceleration constant
	const int MAX_ACCELERATION = 20;

	const int MAX_SPEED = 64;
	const int MIN_SPEED = 32;

	//angle thresholds for peiceweise function
	const float MIN_THRESHOLD = 10.;
	const float MAX_THRESHOLD = 45.;

	//reset encoders
	driveLeft1.tare_position();
	driveRight1.tare_position();

	//position data
	float ticks = (fabs(driveLeft1.get_position()) + fabs(driveRight1.get_position())) / 2.0;
	float degrees = ticks / TICKS * (WHEEL_DIAMETER * M_PI) / CIRCUMFERENCE * 360.;
	//z = degrees;

	//speed variables
	int targetSpeed = 0;
	int currentSpeed = 0;

	//(fabs(nMotorEncoder[leftDrive]) + fabs(nMotorEncoder[rightDrive])) / 2. <= fabs(angle) / 360. * CIRCUMFERENCE / (WHEEL_DIAMETER * PI) * TICKS
	while( degrees < fabs(angle) ) {

		//update position data
		float ticks = (fabs(driveLeft1.get_position()) + fabs(driveRight1.get_position())) / 2.0;
		degrees = ticks / TICKS * (WHEEL_DIAMETER * M_PI) / CIRCUMFERENCE * 360.;
		//z = degrees;

		//targetSpeed = angle > 0 ? SPEED : -SPEED;

		//adjust target speed
		if(fabs(angle) - degrees >= MAX_THRESHOLD) {
			targetSpeed = MAX_SPEED * DIRECTION_MULTIPLIER;
		} else if(fabs(angle) - degrees > MIN_THRESHOLD) {
			//nasty line of code - implements the sloped part of the peicewise function
			targetSpeed = (int) ((MIN_SPEED + (MAX_SPEED-MIN_SPEED) * (fabs(angle) - degrees - MIN_THRESHOLD) / (MAX_THRESHOLD - MIN_THRESHOLD)) * DIRECTION_MULTIPLIER);
		} else {
			targetSpeed = MIN_SPEED * DIRECTION_MULTIPLIER;
		}

		//acceleration calculation
		if(targetSpeed > currentSpeed) {

			if(targetSpeed <= currentSpeed + MAX_ACCELERATION) {
				currentSpeed = targetSpeed;
			} else {
				currentSpeed += MAX_ACCELERATION;
			}

		} else if(targetSpeed < currentSpeed) {

			if(targetSpeed >= currentSpeed - MAX_ACCELERATION) {
				currentSpeed = targetSpeed;
			} else {
				currentSpeed -= MAX_ACCELERATION;
			}

		}

		runDriveLeft(currentSpeed);
		runDriveRight(-currentSpeed);

		delay(20);

	}

	runDriveLeft(0);
	runDriveRight(0);

}*/
