#ifndef DRIVINGMANAGER_H
#define DRIVINGMANAGER_H
#include "LedOutput.h"
#include "Motor.h"
#include "MyServo.h"
#include "DistanceSensor.h"

class DrivingManager{
  public:
    DrivingManager();
    void start();
    void stop();
    bool isReady();
    void setup(int radar_servo_pin, int radar_sensor_pin, int steering_servo_pin, int motor_pin, int relay_pin);
    void loop();
  protected:
    MyServo radar_servo;
    MyServo steering_servo;
    Motor motor;
    DistanceSensor radar_sensor;
    bool active;
    bool isActive();
    double measureDistance(int angle);
    void handleFrontDistance(double distance);
    void handleSideDistance(double left_distance, double right_distance);
    void turn(int turn_direction, int angle, int duration);
    int steer_angle;
    int turn_angle;
    int turn_duration;
    int steer_duration;
    double final_distance;
    bool ready;
    void steeringServoDemo();
    void motorDemo();
    void radarServoDemo();
    void sensorDemo();
    void radarDemo();
};
#endif
