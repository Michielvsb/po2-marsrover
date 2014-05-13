#ifndef DISTANCESENSOR_H
#define DISTANCESENSOR_H
#define FAR 999999
#define CLOSE 0
class DistanceSensor{
  public:
    DistanceSensor();
    void setup(int pin);
    double getDistance();
    void debug();
  private:
    int pin;
    double getDistanceByVoltage(double V);
    double getVoltage();
};
#endif
