#include "okapi/api.hpp"
#include "main.h"
using namespace okapi;

//-----Initialize Motor Ports-----
const int DRIVE_LEFT_MOTOR_PORT = 1;
const int DRIVE_RIGHT_MOTOR_PORT = -10;
const int LEFT_FLYWHEEL_PORT = 14;
const int RIGHT_FLYWHEEL_PORT = 15;
Motor flywheelLeft = Motor(LEFT_FLYWHEEL_PORT,false,AbstractMotor::gearset::blue);
Motor flywheelRight = Motor(RIGHT_FLYWHEEL_PORT, true,AbstractMotor::gearset::blue);
Motor liftLeft = Motor(2,true,AbstractMotor::gearset::green);
Motor liftRight = Motor(9, false,AbstractMotor::gearset::green);
Motor intake = Motor(-6);
Motor claw = Motor(5);
IntegratedEncoder liftEncoder = IntegratedEncoder(2);
IntegratedEncoder flywheelEncoder = IntegratedEncoder(14);
IntegratedEncoder clawEncoder = IntegratedEncoder(5);
//PID constants, currently unused





//-----Initialize Controller-----
Controller masterController;
// Button to run auton in user control
ControllerButton runAutoButton(ControllerDigital::Y);
//Button R Controls the Lift
ControllerButton btnR1(ControllerDigital::R1);
ControllerButton btnR2(ControllerDigital::R2);
//Button L Controls the Intake
ControllerButton btnL1(ControllerDigital::L1);
ControllerButton btnL2(ControllerDigital::L2);
//Buttons Up/Down Control the claw
ControllerButton btnUp(ControllerDigital::up);
ControllerButton btnDown(ControllerDigital::down);
//Buttons X,A,B Control the flywheel
ControllerButton btnX(ControllerDigital::X);//max speed
ControllerButton btnA(ControllerDigital::A);
ControllerButton btnB(ControllerDigital::B);//off speed

//Robot Dimension constants
const auto WHEEL_DIAMETER = 4.0_in;
const auto BASE_WIDTH = 10.5_in;
//-----Async Cotrollers-----
// Tankdrive controller
auto driveController = ChassisControllerFactory::create(
  DRIVE_LEFT_MOTOR_PORT,DRIVE_RIGHT_MOTOR_PORT,
  AbstractMotor::gearset::red,
  {WHEEL_DIAMETER, BASE_WIDTH}
);

//Asynchronous controllers allow multiple movements to occur simultaneosly
//Integrated controllers use built-in motor position/speed control
auto liftController = AsyncControllerFactory::posIntegrated(
	{liftLeft, liftRight});

auto flywheelController = AsyncControllerFactory::velIntegrated(
	{flywheelLeft, flywheelRight});
auto clawController = AsyncControllerFactory::posIntegrated(claw, 100);


//-----Mapping controller input to motor outputs-----


//Lift preset heights
const int NUM_HEIGHTS = 3;
const int height1 = 0;
const int height2 = 500;
const int height3 = 1000;

const int heights[NUM_HEIGHTS] = {height1, height2, height3};
//Comments in lift Control are manual controls
void liftControl(int heightNum) {
		if (btnR1.changedToPressed() && heightNum < NUM_HEIGHTS - 1) {
		// If the goal height is not at maximum and the up button is pressed, increase the setpoint
			heightNum++;
			liftController.setTarget(heights[heightNum]);
		}
		else if (btnR2.changedToPressed() && heightNum >= 0) {
			heightNum--;
			liftController.setTarget(heights[heightNum]);
		}
    /*
    if (btnR1.isPressed()){
      liftLeft.move(127);
      liftRight.move(127);
    }
    else if (btnR2.isPressed()){
      liftLeft.move(-127);
      liftRight.move(-127);
    }

    */
		pros::delay(10);
}
//Comments in flywheel control are manual controls
void flywheelControl(){
	if (btnX.isPressed()){
		flywheelController.setTarget(600);
	}
	else if (btnA.isPressed()){
		flywheelController.setTarget(300);
	}
	else if (btnB.isPressed()){
		flywheelController.setTarget(0);
	}
  /*
  if (btnX.isPressed()){
    flywheelLeft.moveVelocity(600);
    flywheelRight.moveVelocity(600);
  }
  else if (btnA.isPressed()){
    flywheelLeft.moveVelocity(300);
    flywheelRight.moveVelocity(300);
  }
  else if (btnB.isPressed()){
    flywheelLeft.moveVelocity(0);
    flywheelRight.moveVelocity(0);
  }
  */
	pros::delay(10);
}

void intakeControl(){
	if (btnL1.isPressed()){
		intake.moveVelocity(150);
	}
	else if (btnL2.isPressed()){
		intake.moveVelocity(-150);
	}
	else{
		intake.moveVelocity(0);
	}
  pros::delay(10);
}

void clawControl(){
	if (btnUp.isPressed()){
		clawController.setTarget(100);
	}
	else if (btnDown.isPressed()){
		clawController.setTarget(0);
	}
  pros::delay(10);
}
void tempAuton(){
  /*
	driveController.moveDistance(35_in); // Move 35 motor inches forward
  driveController.turnAngle(90_deg);
  driveController.moveDistance(35_in);
	liftController.setTarget(heights[1]); // Move Lift 50 degrees upward
	driveController.waitUntilSettled();
  */
}
void opcontrol() {
  liftLeft.tarePosition();
  liftRight.tarePosition();
  claw.tarePosition();
  int heightNum = 0;
  while (true) {
    // Tank drive with left and right sticks
    driveController.tank(
							masterController.getAnalog(ControllerAnalog::leftY),
              masterController.getAnalog(ControllerAnalog::rightY));
		liftControl(heightNum);
		flywheelControl();
		intakeControl();
    pros::lcd::print(3, "Lift Pos: %d", liftEncoder.get());
    pros::lcd::print(4, "Flywheel Encoder Speed: %d", flywheelEncoder.get());
    pros::lcd::print(5, "Flywheel Speed: %d", flywheelLeft.getActualVelocity());
    pros::lcd::print(6, "Claw Pos: %d", clawEncoder.get());
    // Run the test autonomous routine if we press the button
    if (runAutoButton.changedToPressed()) {
      tempAuton();
    }
    // Wait and give up the time we don't need to other tasks.
    // Additionally, joystick values, motor telemetry, etc. all updates every 10 ms.
    pros::Task::delay(10);
  }
}
