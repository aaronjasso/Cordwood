/****************************** Cordwood Puzzle  ******************************\
|  Cordwood.cpp - Library for manipulating lights on the Cordwood Puzzle       |
|  http://www.boldport.club/                                                   |
|  Created by Aaron Jasso October 20, 2016                                     |
|  Released into the public domain | http://github.com/aaronjasso/Cordwood     |
\******************************************************************************/

#include "Cordwood.h"

//Cordwood::Cordwood(int pinLT, int pinLM, int pinLB, int pinRB, int pinRM, int pinRT);
Cordwood::Cordwood(byte pinLT, byte pinLM, byte pinLB, byte pinRB, byte pinRM, byte pinRT)  //initiate the object
{
	//set all pins to output and write tham low
	pinMode(pinLT,OUTPUT);
	pinMode(pinLM,OUTPUT);
	pinMode(pinLB,OUTPUT);
	pinMode(pinRT,OUTPUT);
	pinMode(pinRM,OUTPUT);
	pinMode(pinRB,OUTPUT);
	
	digitalWrite(pinLT,LOW);
	digitalWrite(pinLM,LOW);
	digitalWrite(pinLB,LOW);
	digitalWrite(pinRT,LOW);
	digitalWrite(pinRM,LOW);
	digitalWrite(pinRB,LOW);
	
	//make pin numbers available for member functions
	_pinLT = pinLT;
	_pinLM = pinLM;
	_pinLB = pinLB;
	_pinRT = pinRT;
	_pinRM = pinRM;
	_pinRB = pinRB;
	
  
	//Record states of pins
	_LTState = LOW;
	_LMState = LOW;
	_LBState = LOW;
	_RTState = LOW;
	_RMState = LOW;
	_RBState = LOW;
  
  _prevTime = millis();
}

void Cordwood::chase(int speed)
{
	if(millis() > _prevTime + (6 - speed)*100){
		if((_LTState == LOW
				&& _LMState == LOW
				&& _LBState == LOW
				&& _RTState == LOW
				&& _RMState == LOW
				&& _RBState == LOW)
			|| (_LTState == LOW
				&& _LMState == LOW
				&& _LBState == LOW
				&& _RTState == LOW
				&& _RMState == LOW
				&& _RBState == HIGH)){
			_RBState = LOW;
			_LBState = HIGH;
		}
		else if(_LBState == HIGH){
			_LBState = LOW;
			_LMState = HIGH;
		}
		else if(_LMState == HIGH){
			_LMState = LOW;
			_LTState = HIGH;
		}
		else if(_LTState == HIGH){
			_LTState = LOW;
			_RTState = HIGH;
		}
		else if(_RTState == HIGH){
			_RTState = LOW;
			_RMState = HIGH;
		}
		else if(_RMState == HIGH){
			_RMState = LOW;
			_RBState = HIGH;
		}
		
		//set pin states
		update();
		
		_prevTime = millis();
  }
}

void Cordwood::update()	//update all pin states
{
	digitalWrite(_pinLT,_LTState);
	digitalWrite(_pinLM,_LMState);
	digitalWrite(_pinLB,_LBState);
	digitalWrite(_pinRT,_RTState);
	digitalWrite(_pinRM,_RMState);
	digitalWrite(_pinRB,_RBState);
}

void Cordwood::allOff()	//turn all LEDs off
{
	_LTState = LOW;
	_LMState = LOW;
	_LBState = LOW;
	_RTState = LOW;
	_RMState = LOW;
	_RBState = LOW;
	
	update();
}

void Cordwood::wheel(int speed)
{
	if(millis() > _prevTime + (6 - speed)*100){
		if((_LTState == LOW
				&& _LMState == LOW
				&& _LBState == LOW
				&& _RTState == LOW
				&& _RMState == LOW
				&& _RBState == LOW)
			|| (_LTState == HIGH
				&& _LMState == LOW
				&& _LBState == LOW
				&& _RTState == LOW
				&& _RMState == LOW
				&& _RBState == HIGH)){
			_LTState = LOW;
			_RBState = LOW;
			_LBState = HIGH;
			_RTState = HIGH;
		}
		else if(_LBState == HIGH
				&& _RTState == HIGH){
			_LBState = LOW;
			_RTState = LOW;
			_LMState = HIGH;
			_RMState = HIGH;
		}
		else if(_LMState == HIGH
				&& _RMState == HIGH){
			_LMState = LOW;
			_RMState = LOW;
			_LTState = HIGH;
			_RBState = HIGH;
		}
		
		//set pin states
		update();
		
		_prevTime = millis();
  }
}

void Cordwood::bounce(int speed)
{
	if(_bounceStep == NULL){
		_bounceStep = 1;
	}
	/*else if (_bounceStep == 1){
		_bounceStep = 2;
	}
	else if (_bounceStep == 2){
		_bounceStep = 3;
	}
	else if (_bounceStep == 3){
		_bounceStep = 1;
	}*/
	
	//transition middle to top
	if(_bounceStep == 1 && millis() > _prevTime + (6 - speed)*100){
		_LMState = LOW;
		_RMState = LOW;
		_LTState = HIGH;
		_RTState = HIGH;
		_bounceStep = 2;
		_prevTime = millis();
		update();
	}
	//transition top to middle
	else if(_bounceStep == 2 && millis() > _prevTime + (7 - speed)*100){
		_LTState = LOW;
		_RTState = LOW;
		_LMState = HIGH;
		_RMState = HIGH;
		_bounceStep = 3;
		_prevTime = millis();
		update();
	}
	//transition middle to bottom
	else if(_bounceStep == 3 && millis() > _prevTime + (6 - speed)*100){
		_LMState = LOW;
		_RMState = LOW;
		_LBState = HIGH;
		_RBState = HIGH;
		_bounceStep = 4;
		_prevTime = millis();
		update();
	}
	//transition bottom to middle
	else if(_bounceStep == 4 && millis() > _prevTime + (5 - speed)*100){
		_LBState = LOW;
		_RBState = LOW;
		_LMState = HIGH;
		_RMState = HIGH;
		_bounceStep = 1;
		_prevTime = millis();
		update();
	}
}