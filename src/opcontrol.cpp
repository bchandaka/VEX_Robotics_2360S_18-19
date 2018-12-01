#include "main.h"
using namespace pros;

//-----Initialize Motor Ports-----
pros::Motor driveLeft (1, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor driveRight (10, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor flywheelLeft (14, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor flywheelRight (15, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor liftLeft (2, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor liftRight (9, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
Motor intake (6, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
Motor claw (5, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);

//PID constants, currently unused

const bool AUTON_TEST = true;

//-----Initialize Controller-----
Controller master (E_CONTROLLER_MASTER);
Controller partner (E_CONTROLLER_PARTNER);

void flywheelControl(){
	if (master.get_digital(E_CONTROLLER_DIGITAL_X)){
		flywheelLeft.move_velocity(600);
    flywheelRight.move_velocity(600);
	}
	else if (master.get_digital(E_CONTROLLER_DIGITAL_A)){
		flywheelLeft.move_velocity(300);
    flywheelRight.move_velocity(300);
	}
	else if (master.get_digital(E_CONTROLLER_DIGITAL_B)){
    flywheelLeft.move_velocity(0);
    flywheelRight.move_velocity(0);
	}
}

void intakeControl(){
	if (partner.get_digital(E_CONTROLLER_DIGITAL_L1)){
		intake.move_velocity(-150);
	}
	else if (partner.get_digital(E_CONTROLLER_DIGITAL_L2)){
		intake.move_velocity(150);
	}
	else{
		intake.move_velocity(0);
	}
}

void clawControl(){
	if (partner.get_digital(E_CONTROLLER_DIGITAL_R1)){
		claw.move_velocity(100);
	}
	else if (partner.get_digital(E_CONTROLLER_DIGITAL_R2)){
		claw.move_velocity(-100);
  }
    else{
      claw.move_velocity(0);
    }
}

void liftControl(){
  if (master.get_digital(E_CONTROLLER_DIGITAL_R2)){
    liftLeft.move_velocity(200);
    liftRight.move_velocity(200);
  }
  else if (master.get_digital(E_CONTROLLER_DIGITAL_R1)){
    liftLeft.move_velocity(-200);
    liftRight.move_velocity(-200);
  }
  else{
    liftLeft.move_velocity(0);
    liftRight.move_velocity(0);
  }
}

void drive(){
  driveRight.move(master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y));
  driveLeft.move(master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y));
}

void opcontrol() {

  claw.set_brake_mode(E_MOTOR_BRAKE_HOLD);

  while (true) {
    drive();
    flywheelControl();
    intakeControl();
    clawControl();
    liftControl();
    pros::lcd::print(7, "joystick right y %d",master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y));

    if (AUTON_TEST && master.get_digital_new_press(E_CONTROLLER_DIGITAL_DOWN)) {
        autonomous();
    }

    // Wait and give up the time we don't need to other tasks.
    // Additionally, joystick values, motor telemetry, etc. all updates every 10 ms.
    pros::Task::delay(10);
  }
}
