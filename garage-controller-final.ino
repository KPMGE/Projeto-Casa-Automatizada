// Code for garage controller used in the first arduino

#include <VarSpeedServo.h>
#include <GarageControllerMillis.h>
#include <NewPing.h>

// distance sensor constants
#define TRIGGER_PIN   9
#define ECHO_PIN      10
#define MAX_DISTANCE 30

// garage led
#define LED_PIN 13
#define SERVO_PIN 6
#define BUTTON_GARAGE_PIN 3
#define SERVO_SPEED 40
#define SERVO_MAX_ANGLE 180
#define MINIMUM_DISTANCE_CAR 10

// instances of all used classes 
GarageControllerMillis controller(SERVO_PIN, SERVO_SPEED, SERVO_MAX_ANGLE, LED_PIN, MINIMUM_DISTANCE_CAR);
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

// controll program variables
unsigned int pingSpeed = 50;
unsigned long pingTimer;
int distanceCar = 1000;
volatile bool buttonPressed = false;

void setup() {
  pinMode(BUTTON_GARAGE_PIN, INPUT_PULLUP);
  pinMode(4, OUTPUT);
  digitalWrite(4, HIGH);
  attachInterrupt(digitalPinToInterrupt(BUTTON_GARAGE_PIN), changeState, HIGH);
  controller.attachServo();
  controller.initServo();
  pingTimer = millis();
}

void loop() {
  // updating distanceCar with millis
  if (millis() >= pingTimer) {
    pingTimer += pingSpeed;
    sonar.ping_timer(updateDistance);
  }
  // if car is near or if the button was pressed, then open the garage
  if (controller.isCarNear(distanceCar) || buttonPressed) {
    controller.turnOnLed();
    controller.openGarage();

    delay(3000);

    controller.closeGarage();
    controller.turnOffLed();

    // reset variables
    distanceCar = 1000;
    buttonPressed = false;
  }
}

void updateDistance() {
  if (sonar.check_timer()) {
    distanceCar = sonar.ping_result / US_ROUNDTRIP_CM;
  }
}

void changeState() {
  buttonPressed = !buttonPressed;
}
