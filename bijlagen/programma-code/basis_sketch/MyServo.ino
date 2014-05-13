#include "MyServo.h"

void MyServo::setup(int pin){
  pinMode(pin, OUTPUT);
  servo.attach(pin);
}
void MyServo::wait(){
  //TODO: delay a certain amount of milliseconds until the servo is at the right angle
  delay(1000);
}


void MyServo::setAngle(int angle){
  this->angle = angle;
  this->servo.write(this->angle);
}

