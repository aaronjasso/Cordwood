//This sketch combines three of the Boldport Club projects to drive the Cordwood
//http://github.com/aaronjasso/Cordwood

#include <Cordwood.h>

//define Tap output (high, Q[bar]) pins
#define TAP_PIN_A 2
#define TAP_PIN_B 3
#define TAP_PIN_C 11
byte tapSet = 0;

//create Cordwood instance
Cordwood cw(4, 5, 7, 8, 12, 10);

void setup() {
  // put your setup code here, to run once:
pinMode(TAP_PIN_A,INPUT);
pinMode(TAP_PIN_B,INPUT);
pinMode(TAP_PIN_C,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

if(digitalRead(TAP_PIN_A)){
  if(tapSet != 1){
    cw.allOff();
    tapSet = 1;
  }
  cw.chase(4);
}
else if(digitalRead(TAP_PIN_B)){
  if(tapSet != 2){
    cw.allOff();
    tapSet = 2;
  }
  cw.wheel(4);
}
else if(digitalRead(TAP_PIN_C)){
  if(tapSet != 3){
    cw.allOff();
    tapSet = 3;
  }
  cw.bounce(5);
}
else {
  tapSet = 0;
  cw.allOff();
}

}
