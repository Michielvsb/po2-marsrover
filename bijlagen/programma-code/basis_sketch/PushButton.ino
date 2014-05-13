void PushButton::setup(int pin){
  this->pin = pin;
  pinMode(this->pin, INPUT);
}

bool PushButton::getValue(){
  return analogRead(this->pin) < 500;
}
