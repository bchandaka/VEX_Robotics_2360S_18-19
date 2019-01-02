#ifndef SMARTMOTOR_H
#define SMARTMOTOR_H
/*
int MOTOR_NUM;
int MOTOR_MAX_VALUE;
int MOTOR_MIN_VALUE;  	    // Reachs target faster
int MOTOR_TASK_DELAY;              // task 1/frequency in mS (about 66Hz)
int MOTOR_DEADBAND;
int sign();
void MotorSlewRateTask(void* params);
class smartMotor{
  private:
    int port;
    int slewRate;
    int reqVel;
    int currVel;
    Motor *mtrPointer;
  public:
    smartMotor();
    smartMotor(int port, motor_gearset_e_t gearset, bool reversed, motor_encoder_units_e_t encoderUnits);
    void init(int port, motor_gearset_e_t gearset, bool reversed, motor_encoder_units_e_t encoderUnits);
    void run(int vel);
    void setCurrVel(int vel);
    void setSlew(int slew);
    int getPort();
    int getVel();
    Motor getMtr();
};
*/
#endif
