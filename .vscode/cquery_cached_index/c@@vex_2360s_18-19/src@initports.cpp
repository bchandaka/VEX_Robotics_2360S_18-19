#include "../vars.h"
//---------------------Initialize Ports-------------------

Motor driveLeft1 (1,  E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_COUNTS);
Motor driveLeft2 (2, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_COUNTS);
Motor driveRight1 (10, E_MOTOR_GEARSET_18, true,E_MOTOR_ENCODER_COUNTS);
Motor driveRight2 (9, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_COUNTS);

Motor flywheel (7, E_MOTOR_GEARSET_06, false, E_MOTOR_ENCODER_COUNTS);
Motor indexer (6, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_COUNTS);
Motor intake (5, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_COUNTS);

Motor descorer (4, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_COUNTS);

pros::ADIGyro gyro (2);
