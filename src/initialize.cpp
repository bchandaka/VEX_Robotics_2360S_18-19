#include "main.h"
#include "../vars.h"

bool autonRunning = true;
bool autonBlue = false;
int autonVer = 1;

void displayStatus() {
    std::string line1 = autonRunning ? "ON" : "OFF";
    std::string line2 = autonBlue ? "BLUE" : "RED";
    //std::string line3 = to_string(autonVer);

    pros::lcd::set_text(0, "Auton (left btn): " + line1);
    pros::lcd::set_text(1, "Side  (mid btn):   " + line2);
    //pros::lcd::set_text(2, "v1 or v2 (right btn): " + line3);

    pros::lcd::set_text(5, "Press the buttons hard, like you do to me!");

}

void on_btnL() {
    autonRunning = !autonRunning;
    displayStatus();
}

void on_btnM() {
    autonBlue = !autonBlue;
    displayStatus();
}

void on_btnR() {
    autonVer = 3 - autonVer;
    displayStatus();
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
    pros::lcd::initialize();
    displayStatus();

    pros::lcd::register_btn0_cb(on_btnL);
    pros::lcd::register_btn1_cb(on_btnM);
    //pros::lcd::register_btn2_cb(on_btnR);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

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
