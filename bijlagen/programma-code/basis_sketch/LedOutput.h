#ifndef LEDOUTPUT_H
#define LEDOUTPUT_H
class LedOutput{
  public:
    void setup(int pin);
    void loop();
    void set_signal_led(bool value);
  private:
    int led_pin;
    bool led_on;
};
#endif
