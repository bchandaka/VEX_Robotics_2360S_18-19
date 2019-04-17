#include "vars.h"

void getBall(){
  intake.run(-120);
  driveStraightPID(43.0);
  printf("moving backward!\n");
  flywheel.run(127);
  driveStraightPID(-32.25);
  intake.run(0);
}

void shootHighFlags(){
  //face the flags
  indexer.run(127);
  delay(20);
  indexer.run(0);
  turnAngle(-89);
  driveStraightPID(14);
  intake.run(-120);
  printf("Shoot the top flag!\n");
  indexer.run(127);
  delay(200);
  intake.run(0);
  delay(300);
  indexer.run(0);
  intake.run(-120);
  printf("Move closer to shoot middle flag!\n");
  driveStraightPID(17.5);
  printf("Shoot the middle flag!\n");
  indexer.run(120);
  delay(500);
  indexer.run(0);
}
void shootLowFlag(){
    printf("Ram the bottom flag!\n");
    turnAngle(-14);
    driveStraightPID(14);
    printf("back out of flag and come back!\n");
    indexer.run(120);
    driveStraightPID(-14);
    turnAngle(14);
    intake.run(70);
    indexer.run(0);
}

void flipSecondCap(){
  driveStraightPID(-7);
  turnAngle(90);
  driveStraightPID(13);
  driveStraightPID(7);
}
void shootMiddleLowFlag(){
    driveStraightPID(-5);
    intake.run(0);
    turnAngle(-45);
    indexer.run(120);
    delay(500);
    indexer.run(0);
    flywheel.run(0);
}
void nearPlatform(){
  printf("face platform!\n");
  intake.run(-120);
  driveStraight(-47);
  turnAngle(90);

  printf("get on the red platform!\n");
  driveStraight(57);
}
//-----Far Side Auton Segments-----
void getFarBall(){
  intake.run(-120);
  driveStraightPID(24.0);
  driveStraightPID(23.0);
  printf("moving backward!\n");
  driveStraight(-6);
  indexer.run(127);
  delay(100);
  indexer.run(0);
  turnAngle(-89);
  intake.run(-120);
}
void farPlatform(){
  printf("get on the platform!\n");
  driveStraightPID(-8);
  driveStraightPID(54);
}
void shootHighMiddleFlag(){
  intake.run(0);
  printf("Shoot the top flag!\n");
  indexer.run(127);
  delay(400);
  intake.run(-120);
  delay(150);
  indexer.run(0); //Starting here
  turnAngle(-5);
  flywheel.run(0);
}

void placeSecondCap(){
    driveStraightPID(-18.5);
    lift.setTarget(1300);
    delay(100);
    delay(100);
    delay(100);
    delay(100);
    delay(100);
    delay(100);
    driveStraightPID(10);
    turnAngle(-30);
    turnAngle(-30);
    delay(50);
    turnAngle(-30);
    driveStraightPID(45);
    lift.setTarget(3400);
    delay(100);
    delay(100);
    delay(100);
    delay(100);
    delay(100);
    delay(100);
    delay(100);
    delay(100);
    delay(100);
    delay(100);
    //driveStraight(15);
    /*
    turnAngle(-130);
    driveStraight(17);
    lift.setTarget(760);
    driveStraight(5);
    delay(200);
    driveStraight(-14);
    lift.setTarget(4000);
    turnAngle(-120);
    driveStraight(17);
    */
}

void shootMiddleFlags(){
  intake.run(0);
  turnAngle(-54);
  delay(300);
  printf("Shoot the top flag!\n");
  indexer.run(110);
  delay(200);
  indexer.run(0); //Starting here
  intake.run(-120);
  delay(200);
  printf("Move back to shoot middle flag!\n");
  driveStraight(-6);

  intake.run(0);
  printf("Shoot the middle flag!\n");
  indexer.run(120);
  delay(500);
  indexer.run(0);
  flywheel.run(0);
  driveStraight(6);
}
