#include "main.h"
#include "smartMotor.h"
//Declares all variables/functions used in the entire project so all variables/functions can be accessed from any file

//Ports
extern smartMotor leftDrive;
extern smartMotor leftDrive2;
extern smartMotor rightDrive;
extern smartMotor rightDrive2;
extern smartMotor flywheel;
extern smartMotor indexer;
extern smartMotor intake;
extern smartMotor lift;
extern ADIGyro gyro;
extern Vision vis;

extern smartMotor* allMotors[8];

//Driver Control Related Vars
extern Controller master;
extern Controller partner;
extern int flywheelCtl;
extern int indexerCtl;
extern int intakeCtl;
extern void flywheelControl();
extern void indexerControl();
extern void intakeControl();
extern void liftControl();

extern int JOY_THRESHOLD;
extern double tankKp;
extern void tankDrive();
extern void tankSpeedControl();

//Auton-Related Functions/Variables
extern bool autonRunning;
extern bool autonBlue;
extern int autonVer;
extern bool AUTON_TEST;
extern void displayStatus();
extern void on_btnL();
extern void on_btnM();
extern void on_btnR();

extern void nearSidePlat();
extern void nearSide();
extern void farSide();
extern void farSidePlat();
extern void skillsAuton();
extern void autonTest();
extern void getBall();
extern void shootHighFlags();
extern void shootLowFlag();
extern void nearPlatform();
extern void farPlatform();
extern void flipSecondCap();
extern void shootMiddleLowFlag();
extern void shootMiddleFlags();
extern void placeSecondCap();
extern void getFarBall();
extern void shootHighMiddleFlag();

extern void driveStraight(double dist);
extern void turnAngle(float angle);

extern bool isLiftPID;
extern int desiredLiftTicks;
extern void liftPID(void* params);
extern bool test;
extern bool isFlyPID;
extern int desiredFlywheelVel;
extern void flyWheelVelPID(void* params);

extern void drivePID(void* params);
extern void driveStraightPID(double rightInches, double leftInches);
extern void curveTurn(double radius, double degrees);


extern void visTest();
