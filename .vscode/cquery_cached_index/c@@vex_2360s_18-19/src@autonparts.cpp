#include "vars.h"

void getBall(){
  runIntake(-120);
  runFlywheel(110);
  driveStraight(43.0);
  printf("%d\n", motorReq[6]);
  printf("moving backward!\n");
  driveStraight(-32.0);
}

void shootHighFlags(){
  //face the flags
  runIntake(0);
  turnAngle(-89);
  driveStraight(6);
  delay(100);
  printf("Shoot the top flag!\n");
  runIndexer(127);
  delay(150);
  runIndexer(0);
  printf("Move closer to shoot middle flag!\n");
  runIntake(-120);
  driveStraight(20);
  runIntake(0);
  printf("Shoot the middle flag!\n");
  runIndexer(120);
  delay(400);
  runIndexer(0);
  runFlywheel(0);
}
void shootLowFlag(){
  printf("Ram the bottom flag!\n");
  turnAngle(-15);
  driveStraight(16);
  printf("back out of flag and come back!\n");
  driveStraight(-16);
  turnAngle(15);
  runIntake(80);
}

void flipSecondCap(){
  driveStraight(-5);
  turnAngle(90);
  driveStraight(22);
}
void shootMiddleLowFlag(){
  driveStraight(-3);
  runIntake(0);
  turnAngle(-50);
  runIntake(0);
  driveStraight(26);
  turnAngle(-60);
}
void nearPlatform(){
  printf("face platform!\n");
  runIntake(0);
  driveStraight(6);
  turnAngle(90);

  printf("get on the red platform!\n");
  driveStraight(40);
  driveStraight(20);
}

void getFarBall(){
  runIntake(-120);
  runFlywheel(127);
  driveStraight(43.0);
  printf("%d\n", motorReq[6]);
  printf("moving backward!\n");
  //driveStraight(-32.0);
}
void shootMiddleFlags(){
  runIntake(0);
  turnAngle(-39);
  delay(300);
  printf("Shoot the top flag!\n");
  runIndexer(110);
  delay(200);
  runIndexer(0); //Starting here
  runIntake(-120);
  delay(200);
  printf("Move back to shoot middle flag!\n");
  driveStraight(-6);

  runIntake(0);
  printf("Shoot the middle flag!\n");
  runIndexer(120);
  delay(500);
  runIndexer(0);
  runFlywheel(0);
  driveStraight(6);
}

void placeSecondCap(){

  driveStraight(-15.0);
  runIntake(0);
  runFlywheel(0);
  turnAngle(-135);
  driveStraight(-26);
  desiredLiftTicks = 2600;
  delay(300);
  driveStraight(26);
  turnAngle(-132);
  driveStraight(17);
  desiredLiftTicks = 760;
  delay(600);
  driveStraight(-14);
  desiredLiftTicks = 4000;
  turnAngle(-120);
  driveStraight(14);
}

void farPlatform(){
  printf("get on the platform!\n");

  turnAngle(-60);
  driveStraight(34);

}
