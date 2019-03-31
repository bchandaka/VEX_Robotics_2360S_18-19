#include "api.h"
#include <vector>
enum sensorType {
  integrated, quadrature, potentiometer
};
class smartMotor{
  private:
    int port;
    int reversed;
    int slewRate;
    int reqVel;
    int curVel;
    smartMotor* slaveMtrPointer;
    pros::Motor* motorPointer;
    sensorType encoder;
    pros::ADIEncoder * quadPointer;
    pros::ADIPotentiometer * potPointer;
    double kP;
    double kI;
    double kD;
  public:
    //Hold all smart motor objects
    static int sign(int x);
    static void MotorSlewRateTask(void* params);
    //-----Constructors-----
    smartMotor( int port,
                pros::motor_gearset_e_t gearset,
                bool reversed,
                sensorType sensor=integrated,
                int sensorPort=0);


    //-----Getters-----
    int getPort();
    int getReqVel();
    int getCurVel();
    int getSlew();
    bool getReversed();
    pros::Motor getMtr();
    double getPosition();
    //-----Setters-----
    void run(int vel);
    void setCurVel(int vel);
    void setSlew(int slew);
    void reset();
    void addSlave(smartMotor* slaveMtr);
    //PID
    void setPIDConst(double newkP, double newkI, double newkD);
    double calcPID(double error, double integral, double derivative);

    void debug(int lcdLine);
};
