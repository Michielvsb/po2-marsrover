#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H
class PushButton{
  public:
    void setup(int pin);
    bool getValue();
  private:
    int pin;
};
#endif
