DistanceSensor::DistanceSensor(){
}
void DistanceSensor::setup(int pin){
   this->pin = pin;
   pinMode(this->pin, INPUT);
}
double DistanceSensor::getDistance(){
  double v = this->getVoltage();
  if(v < 0.4)
   return FAR;
  if(v >= 2.6)
   return CLOSE;
  double d = this->getDistanceByVoltage(v);
  return d;
}
double DistanceSensor::getDistanceByVoltage(double V){
  //linearizing based on https://www.sparkfun.com/datasheets/Sensors/Infrared/GP2D120XJ00F_SS.pdf
  return 1.0/(V*(0.25-0.025)/2.7)-0.42;
}
double DistanceSensor::getVoltage(){
  int val = analogRead(this->pin);
  return ((double)val)*0.0049;
}
void DistanceSensor::debug(){
  Serial.println(this->getDistance());
  delay(1000);
}
