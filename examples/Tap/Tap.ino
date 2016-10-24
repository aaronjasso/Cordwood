//This sketch combines three of the Boldport Club projects to drive the Cordwood
//http://github.com/aaronjasso/Cordwood

#include <Cordwood.h>

//define Tap output (high) pins
#define TAP_PIN_A 1
#define TAP_PIN_B 2
#define TAP_PIN_C 3

//create Cordwood instance
Cordwood cw(4, 5, 7, 8, 12, 10);

void setup() {
  // put your setup code here, to run once:
pinMode(TAP_PIN_A,INPUT);
pinMode(TAP_PIN_B,INPUT);
pinMode(TAP_PIN_c,INPUT);
pinMode(TAP_RESET,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

if(digitalRead(TAP_PIN_A)){
  cw.chase(3);
}
else if(digitalRead(TAP_PIN_B)){
  cw.wheel(3);
}
else if(digitalRead(TAP_PIN_C)){
  cw.bounce(4);
}
else {
  cw.allOff;
}

}
