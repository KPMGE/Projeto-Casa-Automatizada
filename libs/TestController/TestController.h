#ifndef TEST
#define TEST

#include "Arduino.h"
#include <Servo.h>

class TestController {
	private: 
		int _servoPin, _servoSpeed, _servoMaxAngle, _ledPin;
    Servo _servo;

	public:
		TestController(int servoPin, int servoSpeed, int servoMaxAngle, int ledPin) {
      pinMode(servoPin, OUTPUT);
      pinMode(ledPin, OUTPUT);

      _servoPin = servoPin;
      _servoMaxAngle = servoMaxAngle;
      _ledPin = ledPin;
      _servoSpeed = servoSpeed;
    }

		bool isCarNear() {
      return true;
    }

		void openGarage() {
      for (int i = 1; i < _servoMaxAngle; i++) {
        _servo.write(i);
        delay(_servoSpeed);
      }
    }

		void closeGarage() {
      for (int i = _servoMaxAngle; i >= 0; i--) {
        _servo.write(i);
        delay(_servoSpeed);
      }
    }

		void turnOnLed() {
      digitalWrite(_ledPin, HIGH);
    }

		void turnOffLed() {
      digitalWrite(_ledPin, LOW);
    }

    void attach() {
      _servo.attach(_servoPin);
    }
    void init() {
      _servo.write(0);
    }
};

#endif
