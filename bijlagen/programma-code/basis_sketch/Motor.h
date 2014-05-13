#ifndef MOTOR_H
#define MOTOR_H
class Motor{
  public:
    void setup(int pin, int relay_pin);
    void setMotorSpeed(double motor_speed);
  private:
    int motor_pin;
    int relay_pin;
    double motor_speed;
};
#endif
