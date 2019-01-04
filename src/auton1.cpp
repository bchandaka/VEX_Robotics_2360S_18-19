#include "../vars.h"

void auton1(){
  printf("auton1\n");
  runIntake(-127);
  driveStraight(44.0);
  printf("moving backward\n");
  runFlywheel(127);
  driveStraight(-35.0);
  runIntake(0);
  //face the flags
  turnAngle(-90);
  driveStraight(10.0);
  printf("Shoot the top flag\n");
  runIndexer(127);
  delay(700);
  runIndexer(0);
  runIntake(-127);
  driveStraight(18.0);
  runIntake(0);
  printf("Shoot the Middle Flag\n");
  runIndexer(127);
  delay(700);
  runIndexer(0);
  runFlywheel(0);
  driveStraight(10.0);
  turnAngle(-10);
  printf("Ram the low Flag\n");
  driveStraight(7.0);
  printf("autonDone\n");

}
