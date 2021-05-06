#ifndef GARAGE_CONTROLLER_H
#define GARAGE_CONTROLLER_H

#include "Arduino.h"

class GarageController {
	private: 
		int _servoPin, _servoSpeed, _servoMaxAngle, _ledPin, ultrasonicPin;

	public:
		GarageController(int servoPin, int servoSpeed, int servoMaxAngle, int ledPin);
		bool isCarNear();
		void openGarage();
		void closeGarage();
		void turnOnLed();
		void turnOffLed();
};

#endif
