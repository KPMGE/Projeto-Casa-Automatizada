// garage controller for project - We need to detect a car and so,
// open the garage and, at the same time, turns on a led

// Author: Kevin Carvalhod e Jesus

#include <Servo.h>
#include <Ultrasonic.h>

// constants for servomotor
#define SERVO_PIN 6 
#define START_POSITION 0
#define SERVO_MAX_ANGLE 60
#define SERVO_SPEED 15  
// instance of Servo class
Servo servomotor; 

// contants for ultrassonic sensor
#define TRIGGER_PIN 10 
#define ECHO_PIN 9 
#define MINIMUM_DISTANCE_CAR_CM 10
// instance of Ultrassonic class
Ultrasonic ultrasonicSensor(TRIGGER_PIN, ECHO_PIN);

// contants for led
#define GARAGE_LED_PIN 8

void setup() {
  servomotor.attach(SERVO_PIN);
  servomotor.write(START_POSITION);
}

void loop() {
  if (isCarNear()) {
    turnOnLedGarage();
    openGarageWithServo();

    delay(2000);

    closeGarageWithServo();
    turnOffLedGarage();
  }
}

void isCarNear() {
  const int distance = ultrasonicSensor.Ranging(CM);
  return (distance < MINIMUM_DISTANCE_CAR_CM);
}

void openGarageWithServo() {
  for (int position = 0; position < SERVO_MAX_ANGLE; position++) {
    servomotor.write(position);
    delay(SERVO_SPEED);
  }
}

void closeGarageWithServo() {
  for (int position = SERVO_MAX_ANGLE; position >= 0; position--) {
    servomotor.write(position);
    delay(SERVO_SPEED);
  }
}

void turnOnLedGarage() {
  digitalWrite(GARAGE_LED_PIN, HIGH);
}

void turnOffLedGarage() {
  digitalWrite(GARAGE_LED_PIN, LOW);
}
