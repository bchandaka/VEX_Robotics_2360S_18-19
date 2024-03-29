#include "vars.h"

/*
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
*/
void autonomous() {
  //Start Tasks
	Task slewRateTask (smartMotor::MotorSlewRateTask, (void*)"PROS", TASK_PRIORITY_DEFAULT,
                            TASK_STACK_DEPTH_DEFAULT, "slewRate");
  Task liftPIDTask (liftPID, (void*)"PROS", TASK_PRIORITY_DEFAULT,
						                TASK_STACK_DEPTH_DEFAULT, "liftTask");
	lift.setIsPID(true);
	lift.setTarget(300);

  switch(autonVer){
    case 1:
      nearSidePlat();
      break;
    case 2:
      nearSide();
      break;
    case 3:
      farSidePlat();
      break;
    case 4:
      farSide();
      break;
    case 5:
      skillsAuton();
      break;
    case 6:
        if(AUTON_TEST){
          autonTest();
        }
        break;
  }

}
