#include "DrivingManager.h"
DrivingManager::DrivingManager(){
  this->active = false;
  this->ready = false;
  this->steer_angle=30;
  this->turn_angle=70;
  this->turn_duration=300;
  this->steer_duration=100;
  this->final_distance=5.0;
}
void DrivingManager::start(){
  this->active = true;
  this->ready = false;
}
void DrivingManager::stop(){
  this->active = false;
  this->ready = true;
}
bool DrivingManager::isReady(){
  return this->ready;
}
void DrivingManager::setup(int radar_servo_pin, int radar_sensor_pin, int steering_servo_pin, int motor_pin, int relay_pin){
  this->radar_servo.setup(radar_servo_pin);
  this->radar_sensor.setup(radar_sensor_pin);
  this->steering_servo.setup(steering_servo_pin);
  this->motor.setup(motor_pin, relay_pin);
  
  this->radar_servo.setAngle(FRONT);
  this->radar_servo.setAngle(FRONT);
  this->motor.setMotorSpeed(0);
}
bool DrivingManager::isActive(){
  return this->active;
}
double DrivingManager::measureDistance(int angle){
  this->radar_servo.setAngle(180-angle);
  this->motor.setMotorSpeed(0.0);
  this->radar_servo.wait();
  return this->radar_sensor.getDistance();
}
void DrivingManager::handleFrontDistance(double distance){
   if(distance > 20){
      this->motor.setMotorSpeed(1.0);
   }else if(distance < 10){
     this->stop();
      this->motor.setMotorSpeed(0.0);
   }else{
     this->motor.setMotorSpeed(1.0);
   }
}
void DrivingManager::turn(int turn_direction, int angle, int duration){
  //Serial.println("turning");
  int wheel_angle = FRONT;
  if(turn_direction == LEFT){
    wheel_angle -= angle;
  }else if(turn_direction == RIGHT){
    wheel_angle += angle;
  }
  this->steering_servo.setAngle(wheel_angle);
  delay(200);
  this->motor.setMotorSpeed(0.8);
  delay(duration);
  this->steering_servo.setAngle(FRONT);
}
void DrivingManager::handleSideDistance(double left_distance, double right_distance){
  if(left_distance > 30){
    this->turn(LEFT, this->turn_angle, this->turn_duration);
  }else if(right_distance > 30){
    this->turn(RIGHT, this->turn_angle, this->turn_duration);
  }else{
    //correct driving angle
    if(abs(left_distance-right_distance) >= 4.0){
      if(left_distance > right_distance){
        this->turn(RIGHT, this->steer_angle, this->steer_duration);
      }else{
        this->turn(LEFT, this->steer_angle, this->steer_duration);
      }
    }
  }
}
void DrivingManager::loop(){
  //this->radar_servo.setAngle(FRONT);
  //this->steering_servo.setAngle(FRONT);
  // return;
  this->radarDemo();
  return;
  //this->steering_servo.setAngle(FRONT);
  //this->radar_servo.setAngle(FRONT);
  //return;
  //this->sensorDemo();
  //return;
  //this->radarServoDemo();
  //return;
  //this->steeringServoDemo();
  //return;
  
  
  
  //this->motorDemo();
  //return;
  
  //echte code
  
  if(!this->isActive())
    return;
    
  //backup
  double front_distance_2 = this->radar_sensor.getDistance();
  Serial.println(front_distance_2);
  if(front_distance_2 < 20){
    this->motor.setMotorSpeed(0.0);
    this->stop();
    return;
  }
  this->steering_servo.setAngle(FRONT);
  this->motor.setMotorSpeed(0.8);
  delay(400);
  this->motor.setMotorSpeed(0.0);
  delay(500);
  return;
  //end of backup
  
  
  
  //measure front distance, if too close: stop
  this->motor.setMotorSpeed(0);
   double front_distance = this->measureDistance(FRONT);
  this->handleFrontDistance(front_distance);
  delay(500);
  //measure left distance, if too close: steer right. if nothing left: turn
//   double left_distance = this->measureDistance(LEFT);
  double front_distance2 = this->measureDistance(FRONT);
  //measure right distance, if too close: steer left. If nothing right: turn
  double right_distance = this->measureDistance(RIGHT);
   delay(100);
   this->radar_servo.setAngle(FRONT);
  this->handleSideDistance(left_distance, right_distance);
  if(front_distance <= this->final_distance && left_distance <= 30 && right_distance <= 30 && front_distance2 <= this->final_distance){
    this->motor.setMotorSpeed(0);
    this->stop();
    return;
  }
  delay(500);
}

void DrivingManager::steeringServoDemo(){
  this->steering_servo.setAngle(30);
  delay(1000);
  this->steering_servo.setAngle(90);
  delay(1000);
  this->steering_servo.setAngle(150);
  delay(1000);
  this->steering_servo.setAngle(FRONT);
  delay(1000);
}
void DrivingManager::radarServoDemo(){
  int interval = 200;
  this->radar_servo.setAngle(LEFT);
  delay(interval);
  this->radar_servo.setAngle(FRONT);
  delay(interval);
  this->radar_servo.setAngle(RIGHT);
  delay(interval);
  this->radar_servo.setAngle(FRONT);
  delay(interval);
}

void DrivingManager::motorDemo(){
  
  //motor wordt per 3 seconden omgekeerd van richting
  
   this->motor.setMotorSpeed(1.0);
  delay(3000);
  this->motor.setMotorSpeed(0.0);
  delay(3000);
  this->motor.setMotorSpeed(-1.0);
  delay(3000);
  this->motor.setMotorSpeed(0.0);
  delay(3000);
}
void DrivingManager::sensorDemo(){
  this->radar_sensor.debug();
}
void DrivingManager::radarDemo(){
  double front_distance, left_distance, right_distance;
  front_distance = this->measureDistance(FRONT);
  left_distance = this->measureDistance(LEFT);
  this->measureDistance(FRONT);
  right_distance = this->measureDistance(RIGHT);
  Serial.print(front_distance);
  Serial.print(" ");
  Serial.print(left_distance);
  Serial.print(" ");
  Serial.println(right_distance);
}
