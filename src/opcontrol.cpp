#include "main.h"
#include <math.h>
#include "vars.h"



//Debugging function, prints to lcd
void debugMotor(int lcdLine, pros:: Motor motor, std::string motorName, int motorIndex){
  lcd::print(lcdLine,"%s Pwr: %d, Pos:%f", motorName, motorVolt[motorIndex], motor.get_position());
}

void opcontrol() {
  lift.set_brake_mode(E_MOTOR_BRAKE_HOLD);
  printf("start%d \n", 1);
  //Start Tasks
	Task slewRateTask (MotorSlewRateTask, (void*)"PROS", TASK_PRIORITY_DEFAULT,
                            TASK_STACK_DEPTH_DEFAULT, "slewRate");
  Task liftPIDTask (liftPID, (void*)"PROS", TASK_PRIORITY_DEFAULT,
						                TASK_STACK_DEPTH_DEFAULT, "liftTask");
  //register left lcd button to reset gyro
  while (true) { //Controls that will run during driver control

    flywheelControl();
    intakeControl();
    indexerControl();
    liftControl();
    tankSpeedControl();
    tankDrive();
    lcd::print(7, "Gyro Value: %f", gyro.get_value());
    lcd::print(6 , "Lift Pos: %d", pot.get_value());

    //Testing auton

    if (AUTON_TEST && master.get_digital_new_press(E_CONTROLLER_DIGITAL_Y)) {
      slewRateTask.suspend();
      liftPIDTask.suspend();
      autonomous();
      slewRateTask.resume();
      liftPIDTask.resume();
    }


    // Wait and give up the time we don't need to other tasks.
    // Additionally, joystick values, motor telemetry, etc. all updates every 10 ms.
    delay(20);
  }
}
