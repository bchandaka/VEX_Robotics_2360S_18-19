#include "main.h"
#include <math.h>
#include "vars.h"


void opcontrol() {
  //Start Tasks
	Task slewRateTask (smartMotor::MotorSlewRateTask, (void*)"PROS", TASK_PRIORITY_DEFAULT,
                            TASK_STACK_DEPTH_DEFAULT, "slewRate");
  Task liftPIDTask (liftPID, (void*)"PROS", TASK_PRIORITY_DEFAULT,
						                TASK_STACK_DEPTH_DEFAULT, "liftTask");
	lift.setIsPID(true);
	lift.setTarget(300);

	//Task ballTrackTask (ballTracker, (void*)"PROS", TASK_PRIORITY_DEFAULT,
														//TASK_STACK_DEPTH_DEFAULT, "liftTask");

	//Task flyWheelVelPIDTask (flyWheelVelPID, (void*)"PROS", TASK_PRIORITY_DEFAULT,
														//TASK_STACK_DEPTH_DEFAULT, "flyWheelVelControl");
	//flywheel.setIsPID(true);
  //register left lcd button to reset gyro

  while (true) { //Controls that will run during driver control
		tankDrive();
		tankSpeedControl();
		flywheelControl();
		indexerControl();
		intakeControl();
		liftControl();
		lcd::print(5, "Gyro: %f", gyro.get_value());
		lcd::print(6, "Lift: %f", lift.getPosition());
		/*
		intake.debug(2);
		indexer.debug(3);
		flywheel.debug(4);
		lift.debug(5);
		*/

    // Wait and give up the time we don't need to other tasks.
    // Additionally, joystick values, motor telemetry, etc. all updates every 10 ms.
    delay(20);
  }
}
