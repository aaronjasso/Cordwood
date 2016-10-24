//This sketch demonstrates the chase function of the Cordwood library
//http://github.com/aaronjasso/Cordwood

#include <Cordwood.h>

//Create instance of the Cordwood class called 'cw'
//The arguments are the pin numbers for the LEDs in the following order:
//LeftTop, LeftMiddle, LeftBottom, RightBottom, RightMiddle, RightTop

//If you hold the assembled Cordwood puzzle such that the board with the
//6-pin header is furthest from you and the header is pointing down, they
//should be in order from left to right.

Cordwood cw(4, 5, 7, 8, 12, 10);

void setup() {
  // put your setup code here, to run once:
  //debug
  Serial.begin(9600);
  //end debug
}

void loop() {
  // put your main code here, to run repeatedly:

//chase takes one argument: and integer 1 - 5 (inclusive) to define the
//speed of the animation

cw.chase(3);

//Two other animations are available: wheel and bounce. Like chase, they each
//take a single argument that sets the speed of the animation. Wheel accepts
//1 - 5, bounce accpets 1 - 4. Comment out chase and uncomment one of the follwing
//lines to use the animation.
//cw.wheel(3);
//cw.bounce(4);

}
