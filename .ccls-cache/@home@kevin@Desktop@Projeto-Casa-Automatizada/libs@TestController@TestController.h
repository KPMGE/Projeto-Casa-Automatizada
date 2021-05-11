#ifndef TEST
#define TEST

#include "Arduino.h"
#include <Servo.h>
#include <Ultrasonic.h>

class TestController {
	private: 
		int _servoPin, _servoSpeed, _servoMaxAngle, _ledPin, _triggerPin, _echoPin, _minimumDistance;
    Servo _servo;
    Ultrasonic _ultrasonicSensor;

	public:
		TestController(int servoPin, int servoSpeed, int servoMaxAngle, int ledPin, int triggerPin, int echoPin, int minimumDistance ) {
      pinMode(servoPin, OUTPUT);
      pinMode(ledPin, OUTPUT);
      _servo.attach(servoPin);

      _servoPin = servoPin;
      _servoMaxAngle = servoMaxAngle;
      _ledPin = ledPin;
      _servoSpeed = servoSpeed;
      _triggerPin = triggerPin;
      _echoPin = echoPin;
      _minimumDistance = minimumDistance;
    }

		bool isCarNear(int distance) {
      // int distance = _ultrasonicSensor.Ranging(CM);
      return (distance < _minimumDistance);
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
};

#endif
