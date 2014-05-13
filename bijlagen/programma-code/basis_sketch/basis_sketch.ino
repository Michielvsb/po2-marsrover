#include <Servo.h>
const unsigned int DCP[] = {13, 2, 3, 4, 5, 6, 7, 8, 9};
const unsigned int ACP[] = {13, A0, A1, A2, A3, A4, A5};
#include "LedOutput.h"
#include "Motor.h"
#include "MyServo.h"
#include "DrivingManager.h"
#include "PushButton.h"
#include "MusicPlayer.h"

#define FRONT 90
#define LEFT 0
#define RIGHT 180

DrivingManager manager;
PushButton start_button;
LedOutput end_led;
MusicPlayer music_player;

#define RADAR_SERVO DCP[6]
#define RADAR_SENSOR ACP[1]
#define STEERING_SERVO DCP[5]
#define ELECTRO_MOTOR DCP[3]
#define RELAY DCP[4]
#define PUSHBUTTON ACP[2]
#define LED DCP[7]

/*
DIGITAL PINS (BLACK TO BROWN)
2 1
4 3
6 5
8 7
*/

void setup(){
  Serial.begin(9600);
  for(int i = 1; i <= 6; ++i){
    pinMode(ACP[i], INPUT);
  }
  manager.setup(RADAR_SERVO, RADAR_SENSOR, STEERING_SERVO, ELECTRO_MOTOR, RELAY);
  start_button.setup(PUSHBUTTON);
  end_led.setup(LED);
  //music_player.setup(DCP[8]);
  manager.start();
}


void loop(){
  /*if(start_button.getValue()){
    manager.start();
  }*/
  manager.loop();
  if(manager.isReady()){
    end_led.set_signal_led(true);
  }
}
