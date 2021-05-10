#ifndef GARAGE_H  
#define GARAGE_H  

#include "Arduino.h"
#include <VarSpeedServo.h>

class GarageControllerMillis {
  private:
    int _servoPin, _servoSpeed, _servoMaxAngle, _ledPin, _mindDistance;
    VarSpeedServo _servo;

  public:
		GarageControllerMillis(int servoPin, int servoSpeed, int servoMaxAngle, int ledPin, int mindDistance);
		bool isCarNear(int distance);
		void openGarage();
		void closeGarage();
		void turnOnLed();
		void turnOffLed();
		void attachServo();
		void initServo();
};

#endif
