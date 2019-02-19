#include "main.h"

//Declares all variables/functions used in the entire project so all variables/functions can be accessed from any file

//Ports
extern Motor driveLeft1;
extern Motor driveLeft2;
extern Motor driveRight1;
extern Motor driveRight2;
extern Motor flywheel;
extern Motor indexer;
extern Motor intake;
extern Motor lift;

extern ADIGyro gyro;
extern Vision vis;
extern ADIPotentiometer pot;
extern void debugMotor(int lcdLine, pros:: Motor motor, std::string motorName, int motorIndex);

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

extern void driveStraight(double dist);
extern void turnAngle(float angle);

extern bool isLiftPID;
extern int desiredLiftTicks;
extern void liftPID(void* params);


extern void drivePID(void* params);
extern void driveStraightPID(double rightInches, double leftInches);
extern void curveTurn(double radius, double degrees);
//OpControl/motor functions and variables
extern void runDriveLeft(int volts);
extern void runDriveRight(int volts);
extern void runFlywheel(int volts);
extern void runIndexer(int volts);
extern void runIntake(int volts);
extern void runLift(int volts);

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

//Slew
extern int MOTOR_NUM;
extern int MOTOR_MAX_VALUE;
extern int MOTOR_MIN_VALUE;
extern int MOTOR_DEFAULT_SLEW_RATE;
extern int MOTOR_FAST_SLEW_RATE;
extern int MOTOR_TASK_DELAY;
extern int MOTOR_DEADBAND;

extern Motor motorObj[8];
extern int motorReq[8];
extern int motorSlew[8];
extern int motorVolt[8];

extern int sign();
extern void MotorSlewRateTask(void* params);


extern void visTest();
