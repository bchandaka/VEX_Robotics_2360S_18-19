#include "main.h"
#include <math.h>
#include "../vars.h"


const bool AUTON_TEST  = true;

//Debugging function, prints to lcd
void debugMotor(int lcdLine, pros:: Motor motor, std::string motorName, int motorIndex){
  lcd::print(lcdLine,"%s Pwr: %d, Pos:%f", motorName, motorVolt[motorIndex], motor.get_position());
}


void opcontrol() {
  descorer.set_brake_mode(E_MOTOR_BRAKE_HOLD);

  printf("start%d \n", 1);
  //Start Tasks
	Task slewRateTask (MotorSlewRateTask, (void*)"PROS", TASK_PRIORITY_DEFAULT,
               TASK_STACK_DEPTH_DEFAULT, "slewRate");
	Task tankDriveTask (tankDrive, (void*)"PROS", TASK_PRIORITY_DEFAULT,
						                TASK_STACK_DEPTH_DEFAULT, "tankDrive");
  //register left lcd button to reset gyro
  while (true) { //Controls that will run during driver control
    flywheelControl();
    intakeControl();
    indexerControl();
    descorerControl();
    tankSpeedControl();
    /*
		debugMotor(0, driveLeft1, "driveLeft1", 0);
		debugMotor(1, driveLeft2, "driveLeft2", 1);
		debugMotor(2, driveRight1, "driveRight1", 2);
		debugMotor(3, driveRight2, "driveRight2", 3);
		debugMotor(4, flywheel, "flywheel", 4);
		debugMotor(5, indexer, "indexer",5);
		debugMotor(6, intake, "intake", 6);
		debugMotor(7, descorer, "descorer", 7);
		lcd::print(7, "Gyro Value: %f", gyro.get_value());
    */
    lcd::print(7, "Gyro Value: %f", gyro.get_value());

    //Testing auton

    if (AUTON_TEST && master.get_digital_new_press(E_CONTROLLER_DIGITAL_Y)) {
      tankDriveTask.suspend();
      slewRateTask.suspend();
      autonomous();
      tankDriveTask.resume();
      slewRateTask.resume();
    }


    // Wait and give up the time we don't need to other tasks.
    // Additionally, joystick values, motor telemetry, etc. all updates every 10 ms.
    delay(20);
  }
}
