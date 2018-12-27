#include "main.h"
#include <algorithm>
using namespace pros;

#include "../vars.h"


const bool AUTON_TEST = true;

//---------------------Initialize Ports-------------------
pros::ADIGyro gyro (2);
Motor driveLeft1 (1, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_COUNTS);
Motor driveLeft2 (2, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_COUNTS);
Motor driveRight1 (10, E_MOTOR_GEARSET_18, true,E_MOTOR_ENCODER_COUNTS);
Motor driveRight2 (9, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_COUNTS);

Motor flywheel (14, E_MOTOR_GEARSET_06, false, E_MOTOR_ENCODER_COUNTS);
Motor indexer (2, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_COUNTS);
Motor intake (6, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_COUNTS);

Motor descorer (5, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_COUNTS);

//---------------------Slew Rate Task--------------------
#define MOTOR_NUM               8
#define MOTOR_MAX_VALUE         127
#define MOTOR_MIN_VALUE         (-127)
#define MOTOR_DEFAULT_SLEW_RATE 15      // Default will cause 375mS from full fwd to rev
#define MOTOR_FAST_SLEW_RATE    30	    // Reachs target faster
#define MOTOR_TASK_DELAY        15      // task 1/frequency in mS (about 66Hz)
#define MOTOR_DEADBAND          10

//Array to hold motor objects
Motor motorObj[ MOTOR_NUM ] = {driveLeft1, driveLeft2, driveRight1, driveRight2, flywheel, indexer, intake, descorer};
// Array to hold requested speed for the motors
int motorReq[ MOTOR_NUM ];

// Array to hold "slew rate" for the motors
int motorSlew[ MOTOR_NUM ];
// Array to hold current motor speed
int motorVolt[ MOTOR_NUM ];

int sign(int x) {
    return (x > 0) - (x < 0);
}
void MotorSlewRateTask(void* params){
    int motorIndex;
    // Initialize stuff
		for(motorIndex=0;motorIndex<MOTOR_NUM;motorIndex++){
			motorReq[motorIndex] = 0;
			motorSlew[motorIndex] = MOTOR_DEFAULT_SLEW_RATE;
			motorVolt[motorIndex] = 0;
		}
		motorSlew[6] = MOTOR_FAST_SLEW_RATE;

    // run task until stopped
    while( true ){
        // run loop for every motor
        for(motorIndex=0; motorIndex<MOTOR_NUM; motorIndex++){
            // So we don't keep accessing the internal storage
            Motor motorTmp =  motorObj[ motorIndex ];
						if(motorIndex==6){
							printf("motorVolts: %d", motorVolt[6]);
						}
            // Current motor value
            int currentTmp = motorVolt[motorIndex];
            // Update motor value
						if(currentTmp != motorReq[motorIndex]){
							motorVolt[motorIndex] += sign(motorReq[motorIndex]-currentTmp) *
													std::clamp(motorSlew[motorIndex], 0, abs(currentTmp-motorReq[motorIndex]));
            }
						motorVolt[motorIndex] = std::clamp(currentTmp, MOTOR_MIN_VALUE, MOTOR_MAX_VALUE);

						// finally send it!
						motorTmp.move(motorVolt[motorIndex]);
        }
        // Wait approx the speed of motor update
        delay( MOTOR_TASK_DELAY );
    }
}


//------------------Motor Functions------------------
void runDriveLeft(int volts){
  motorReq[0] = -volts;
  motorReq[1] = volts;
}

void runDriveRight(int volts){
  motorReq[2] = volts;
  motorReq[3] = -volts;
}

void runFlywheel(int volts){
  motorReq[4] = volts;
}
void runIndexer(int volts){
  motorReq[5] = volts;
}
void runIntake(int volts){
  motorReq[6] = volts;
}
void runDescorer(int volts){
  motorReq[7] = volts;
}

//-----I---------Initialize Controller---------------
Controller master (E_CONTROLLER_MASTER);
Controller partner (E_CONTROLLER_PARTNER);

//------------Map COntroller Input to Motors---------
int flywheelCtl;
int indexerCtl;
int intakeCtl;

void flywheelControl(){
	flywheelCtl = (master.get_digital(E_CONTROLLER_DIGITAL_X)) +
								(master.get_digital(E_CONTROLLER_DIGITAL_A) << 1) +
								(master.get_digital(E_CONTROLLER_DIGITAL_B) << 2);
	switch(flywheelCtl){
		case 1: //BtnX
			runFlywheel(127);
			break;
		case 2: //BtnA
			runFlywheel(90);
			break;
		case 4: //BtnB
			runFlywheel(0);
			break;
	}
}

void intakeControl(){
	intakeCtl = (master.get_digital(E_CONTROLLER_DIGITAL_L1)) +
								(master.get_digital(E_CONTROLLER_DIGITAL_L2) << 1);

	switch(intakeCtl){
		case 1: //BtnL1
			runIntake(-127);
			break;
		case 2: //BtnL2
			runIntake(127);
			break;
		default:
			runIntake(0);
	}
}

void indexerControl(){
	indexerCtl = (master.get_digital(E_CONTROLLER_DIGITAL_R1)) +
								(master.get_digital(E_CONTROLLER_DIGITAL_R2) << 1);
	switch(indexerCtl){
		case 1: //BtnR1
			runIndexer(100);
			break;
		case 2: //BtnR2
			runIndexer(-100);
			break;

		default:
			runIndexer(0);
	}
}

//-----------------Tank Drive Task--------------
#define JOY_THRESHOLD	15
#define kP_tank       1
void drive(void* params){
	int    ctl_l;
	int    ctl_r;
	int    drive_l;
	int    drive_r;
	while(true){
		// Get tank drive vertical joystick control
		ctl_l = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y)/kP_tank;
		ctl_r = master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y)/kP_tank;
		// Ignore joystick near center to prevent motors from running when the joystick doesn't properly center to zero
		drive_l = (abs(ctl_l) <= JOY_THRESHOLD) ? 0:ctl_l;
		drive_r = (abs(ctl_r) <= JOY_THRESHOLD) ? 0:ctl_r;
    //Send it!
		runDriveLeft(drive_l);
		runDriveRight(drive_r);

		delay(MOTOR_TASK_DELAY);
	}
}
//Debugging function, prints to lcd
void debugMotor(int lcdLine, pros:: Motor motor, std::string motorName, int motorIndex){
  lcd::print(lcdLine,"%s Power: %d, volt:%f", motorVolt[motorIndex], motor.get_voltage());
}
//-----------------Auton Drive FUnctions----------------
void gyroReset(){
	gyro.reset();
}

void turnDegrees(float angle){
  gyroReset();
	bool rightTurn = angle > 0;

	float previous = gyro.get_value() / 10.0;
	float current = gyro.get_value() / 10.0;
	float sum = 0;
	float angleDifference = angle;

	const float speed = 100;
	float leftSpeed = rightTurn ? speed : -speed;
	float rightSpeed = -leftSpeed;

	const float K = 0.017;

	while( fabs(sum) < fabs(angle)-1 ) {
    lcd::print(5, "Gyro Value: %f", gyro.get_value());

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

void opcontrol() {
  //Start Tasks
	pros::Task slewRateTask (MotorSlewRateTask, (void*)"PROS", TASK_PRIORITY_DEFAULT,
               TASK_STACK_DEPTH_DEFAULT, "slewRate");
	pros::Task tankDriveTask (drive, (void*)"PROS", TASK_PRIORITY_DEFAULT,
						                TASK_STACK_DEPTH_DEFAULT, "tankDrive");
  //register left lcd button to reset gyro
	pros::lcd::register_btn0_cb(gyroReset);
  while (true) {
    flywheelControl();
    intakeControl();
    indexerControl();
		debugMotor(0, driveLeft1, "driveLeft1", 0);
		debugMotor(1, driveLeft2, "driveLeft2", 1);
		debugMotor(2, driveRight1, "driveRight1", 2);
		debugMotor(3, driveRight2, "driveRight2", 3);
		debugMotor(4, flywheel, "flywheel", 4);
		debugMotor(5, indexer, "indexer",5);
		debugMotor(6, intake, "intake", 6);
		debugMotor(7, descorer, "descorer", 7);
		//lcd::print(5, "Gyro Value: %f", gyro.get_value());

    //Testing auton
    if (AUTON_TEST && master.get_digital_new_press(E_CONTROLLER_DIGITAL_DOWN)) {
        turnDegrees(90);
        delay(1000);
        turnDegrees(-90);
    }

    // Wait and give up the time we don't need to other tasks.
    // Additionally, joystick values, motor telemetry, etc. all updates every 10 ms.
    delay(10);
  }
}
