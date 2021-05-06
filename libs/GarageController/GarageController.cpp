// implementation for garage controller

#include <Servo.h>
#include "Arduino.h"
#include "GarageController.h"

#define START_POSITION 0

// instance of servomotor
Servo servo;

// constructor
GarageController::GarageController(int servoPin, int servoSpeed, int servoMaxAngle, int ledPin) {
	pinMode(servoPin, OUTPUT);
	pinMode(ledPin, OUTPUT);
	servo.attach(servoPin);
	servo.write(START_POSITION);

	_servoPin = servoPin;
	_servoSpeed = servoSpeed;
	_servoMaxAngle = servoMaxAngle;
	_ledPin = ledPin;
}

void GarageController::openGarage() {
	for (int pos = 1; pos <= _servoMaxAngle; pos++) {
		servo.write(pos);
		delay(_servoSpeed);
	}
}

void GarageController::closeGarage() {
	for (int pos = _servoMaxAngle; pos >= _servoMaxAngle; pos--) {
		servo.write(pos);
		delay(_servoSpeed);
	}
}

void GarageController::turnOnLed() {
	digitalWrite(_ledPin, HIGH);
}

void GarageController::turnOnLed() {
	digitalWrite(_ledPin, LOW);
}

bool GarageController::isCarNear() {
	return 0; // we need to implemet this yet
}
