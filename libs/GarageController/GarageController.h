#ifndef GARAGE_CONTROLLER_H
#define GARAGE_CONTROLLER_H

#include "Arduino.h"
#include <Servo.h>
class GarageController {
	private: 
		int _servoPin, _servoSpeed, _servoMaxAngle, _ledPin, ultrasonicPin;
    Servo _servo;

	public:
		GarageController(int servoPin, int servoSpeed, int servoMaxAngle, int ledPin);
		bool isCarNear();
		void openGarage();
		void closeGarage();
		void turnOnLed();
		void turnOffLed();
    void attach();
    void init();
};

#endif