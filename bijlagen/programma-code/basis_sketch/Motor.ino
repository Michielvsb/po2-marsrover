#include "Motor.h"

void Motor::setup(int pin, int relay_pin){
  this->motor_pin = pin;
  this->relay_pin = relay_pin;
  this->motor_speed = 0;
  pinMode(this->motor_pin, OUTPUT);
  pinMode(this->relay_pin, OUTPUT);
}

void Motor::setMotorSpeed(double motor_speed){
  motor_speed = min(max(motor_speed, -1.0), 1.0);
  this->motor_speed = motor_speed;
  if(this->motor_speed < 0){
    digitalWrite(this->relay_pin, HIGH);
  }else{
    digitalWrite(this->relay_pin, LOW);
  }
  Serial.println((int)(this->motor_speed*255));
  analogWrite(this->motor_pin, (int)(abs(this->motor_speed)*255.0));
}
