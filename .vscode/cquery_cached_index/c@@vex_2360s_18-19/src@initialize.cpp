#include "vars.h"

//---------------Initialize Ports---------------

//-----Sensors-----
pros::ADIGyro gyro (2);
pros::Vision vis (11);
pros::ADIPotentiometer pot (3);

//-----Motors-----
smartMotor leftDrive (1,  E_MOTOR_GEARSET_18, false);
smartMotor leftDrive2 (2, E_MOTOR_GEARSET_18, true);
smartMotor rightDrive (10, E_MOTOR_GEARSET_18, true);
smartMotor rightDrive2 (9, E_MOTOR_GEARSET_18, false);

smartMotor flywheel (7, E_MOTOR_GEARSET_06, false);
smartMotor indexer (6, E_MOTOR_GEARSET_18, false);
smartMotor intake (5, E_MOTOR_GEARSET_18, true);

smartMotor lift (4, E_MOTOR_GEARSET_36, false,
                  potentiometer, 3);

//Manually instantiate allMotors with smartMotor Objects
smartMotor* allMotors[8] = {&leftDrive, &leftDrive2, &rightDrive, &rightDrive2,
                            &flywheel, &indexer, &intake, &lift};

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
bool AUTON_TEST = false;
int desiredFlywheelVel = 0;
bool isFlyPID = false;
void initialize() {
    pros::lcd::initialize();
    displayStatus();
    leftDrive.addSlave(&leftDrive2);
    rightDrive.addSlave(&rightDrive2);
    pros::lcd::register_btn0_cb(on_btnL);
    pros::lcd::register_btn1_cb(on_btnM);
    pros::lcd::register_btn2_cb(on_btnR);

}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
  displayStatus();


}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}
