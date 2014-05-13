#ifndef MYSERVO_H
#define MYSERVO_H

class MyServo{
  public:
    void setup(int pin);
    void setAngle(int angle);
    void wait();
  private:
    Servo servo;
    int angle;
    int convertAngleToMicroseconds(int angle);
};
#endif
