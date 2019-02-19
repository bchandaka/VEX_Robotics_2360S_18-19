#include "vars.h"

void getBall(){
  runIntake(-120);
  runFlywheel(110);
  driveStraight(43.0);
  printf("%d\n", motorReq[6]);
  printf("moving backward!\n");
  driveStraight(-32.0);
}
void getFarBall(){
  runIntake(-120);
  runFlywheel(127);
  driveStraight(43.0);
  printf("%d\n", motorReq[6]);
  printf("moving backward!\n");
  driveStraight(-32.0);
}
void shootMiddleFlags(){
  runIntake(0);
  turnAngle(-62.5);
  driveStraight(20);
  delay(300);
  printf("Shoot the top flag!\n");
  runIndexer(110);
  delay(200);
  runIndexer(0); //Starting here
  runIntake(-120);
  delay(200);
  printf("Move back to shoot middle flag!\n");
  driveStraight(-10);
  runIntake(0);
  printf("Shoot the middle flag!\n");
  runIndexer(120);
  delay(400);
  runIndexer(0);
  runFlywheel(0);
}

void placeSecondCap(){
  turnAngle(-72.5);
  driveStraight(-45.0);
  desiredLiftTicks = 2600;
  delay(500);
  driveStraight(22);
  turnAngle(-135);
  driveStraight(12);
  desiredLiftTicks = 760;
}

void shootHighFlags(){
  //face the flags
  runIntake(0);
  turnAngle(-89);
  driveStraight(7);
  delay(100);
  printf("Shoot the top flag!\n");
  runIndexer(127);
  delay(150);
  runIndexer(0);
  printf("Move closer to shoot middle flag!\n");
  runIntake(-120);
  driveStraight(19);
  runIntake(0);
  printf("Shoot the middle flag!\n");
  runIndexer(120);
  delay(400);
  runIndexer(0);
  runFlywheel(0);
  runIntake(-120);
}
void shootLowFlag(){
  printf("Ram the bottom flag!\n");
  turnAngle(-5);
  driveStraight(17);
  printf("back out of flag and come back!\n");
  driveStraight(-17);
  turnAngle(5);
  runIntake(70);
}

void flipSecondCap(){
  turnAngle(90);
  driveStraight(26);
}
void shootMiddleLowFlag(){
  driveStraight(-5);
  turnAngle(-50);
  runIntake(0);
  driveStraight(25);
  driveStraight(-40);
  turnAngle(-40);
}
void nearPlatform(){
  printf("face platform!\n");
  turnAngle(90);
  runIntake(0);
  printf("get on the red platform!\n");
  driveStraight(40);
}
void farPlatform(){
  printf("coming back to platform!\n");
  driveStraight(-52);
  printf("face platform!\n");
  turnAngle(90);
  printf("get on the yellow platform!\n");
  driveStraight(45);
}
