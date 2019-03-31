#include "main.h"
#include <math.h>
#include "vars.h"


void opcontrol() {
  //Start Tasks
	Task slewRateTask (smartMotor::MotorSlewRateTask, (void*)"PROS", TASK_PRIORITY_DEFAULT,
                            TASK_STACK_DEPTH_DEFAULT, "slewRate");
  Task liftPIDTask (liftPID, (void*)"PROS", TASK_PRIORITY_DEFAULT,
						                TASK_STACK_DEPTH_DEFAULT, "liftTask");
	desiredLiftTicks = lift.getPosition();
	isFlyPID = true;
	Task flyWheelVelPIDTask (flyWheelVelPID, (void*)"PROS", TASK_PRIORITY_DEFAULT,
														TASK_STACK_DEPTH_DEFAULT, "flyWheelVelControl");
  //register left lcd button to reset gyro
  while (true) { //Controls that will run during driver control
    flywheelControl();
    intakeControl();
    indexerControl();
    liftControl();
    tankSpeedControl();
    tankDrive();
		/*
		leftDrive.debug(0);
		rightDrive.debug(1);
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
