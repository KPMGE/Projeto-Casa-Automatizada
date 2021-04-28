
// garage controller for project - We need to detect a car and so,
// open the garage and, at the same time, turns on a led
// Now, using NewPing library

// Author: Kevin Carvalho de Jesus

#include <Servo.h>
#include <NewPing.h>

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
#define MAXIMUM_READING_DISTANCE_CM 30 
#define MINIMUM_DISTANCE_CAR_CM 10
// instance of Ultrassonic class
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAXIMUM_READING_DISTANCE_CM); 

// How frequently are we going to send out a ping (in milliseconds)
unsigned int pingSpeed = 50; 
// Holds the next ping time.
unsigned long pingTimer;     


// contants for led
#define GARAGE_LED_PIN 8

void setup() {
  servomotor.attach(SERVO_PIN);
  servomotor.write(START_POSITION);
  pingTimer = millis();
}

void loop() {
  // implementation for garageController
  if (millis() >= pingTimer) {   
    pingTimer += pingSpeed;      
    sonar.ping_timer(isCarNear); 
  }

  // we can do anything here, never mind!

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

void isCarNear() {
  if (sonar.check_timer()) { 
    const int distance = sonar.ping_result / US_ROUNDTRIP_CM;
    garageController(distance);
  }
}

void garageController(int distance) {
  if (distance < MINIMUM_DISTANCE_CAR_CM) {
    turnOnLedGarage();
    openGarageWithServo();

    delay(2000);

    closeGarageWithServo();
    turnOffLedGarage();

    delay(2000);
  }
}