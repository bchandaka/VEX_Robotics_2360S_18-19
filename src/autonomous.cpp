/*
#include "main.h"
#include "okapi/api.hpp"

#include "../vars.h"

using namespace okapi;

 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.

 //Robot Dimension constants
 //pros::Motor claw (5, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
const int DRIVE_LEFT_MOTOR_PORT = 1;
const int DRIVE_RIGHT_MOTOR_PORT = -10;
const auto WHEEL_DIAMETER = 4.0_in;
const auto BASE_WIDTH = 10.5_in;

auto driveController = ChassisControllerFactory::create(
DRIVE_LEFT_MOTOR_PORT,DRIVE_RIGHT_MOTOR_PORT,
AbstractMotor::gearset::red,
{WHEEL_DIAMETER, BASE_WIDTH}
);

void autonomous() {

    int mult = autonBlue ? -1 : 1;
    if (!autonRunning)
        return;

    if (autonVer == 1) {
        driveController.moveDistance(43_in);
    }
    else {
        driveController.moveDistance(43_in);

        driveController.moveDistance(-57_in);


      //  driveController.turnAngle(mult * 180);


        if (autonBlue) {
            //driveLeft.move_relative(-20, 200);
            driveLeft1.move(-127);
        } else {
            driveRight1.move(-127);
        }

        pros::delay(2000);

        driveLeft1.move(127);
        driveRight1.move(127);

        pros::delay(4000);

        driveLeft.move(0);
        driveRight.move(0);

        pros::Motor flywheelLeft (14, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);
        pros::Motor flywheelRight (15, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_DEGREES);
        pros::Motor intake (6, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);

        driveController.moveDistance(-80_in); // Move 35 motor inches forward

        flywheelLeft.moveVelocity(600);
        flywheelRight.moveVelocity(600);

        intake.moveVelocity(150);

        pros::delay(1500);

        flywheelLeft.moveVelocity(0);
        flywheelRight.moveVelocity(0);
        intake.moveVelocity(0);

        driveController.moveDistance(-10_in); // Move 35 motor inches forward

    }

}
*/
