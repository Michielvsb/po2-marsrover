#include "LedOutput.h"
void LedOutput::setup(int pin){
  this->led_pin = pin;
  pinMode(led_pin, OUTPUT);
  this->set_signal_led(false);
}
void LedOutput::set_signal_led(bool value){
  this->led_on = value;
  if(this->led_on){
    digitalWrite(this->led_pin, HIGH);
  }else{
    digitalWrite(this->led_pin, LOW);
  }
}
 
