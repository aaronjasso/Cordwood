/****************************** Cordwood Puzzle  ******************************\
|  Cordwood.h - Library for manipulating lights on the Cordwood Puzzle         |
|  http://www.boldport.club/                                                   |
|  Created by Aaron Jasso October 20, 2016                                     |
|  Released into the public domain | http://github.com/aaronjasso/Cordwood     |
\******************************************************************************/

#pragma once
#include "Arduino.h"

// define class Cordwood
class Cordwood {
  public:
    Cordwood(byte pinLT, byte pinLM, byte pinLB, byte pinRB, byte pinRM, byte pinRT);
    
    void chase(int speed);
    void wheel(int speed);
	void bounce(int speed);
	void allOff();
	void allOn();
	void update();

  private:
	unsigned long _prevTime;
	int _pinLT;
	int _pinLM;
	int _pinLB;
	int _pinRT;
	int _pinRM;
	int _pinRB;
	int _LTState;
	int _LMState;
	int _LBState;
	int _RTState;
	int _RMState;
	int _RBState;
	int _bounceStep;
	
};

//#endif