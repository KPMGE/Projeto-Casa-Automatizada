#include <VarSpeedServo.h>
#include <GarageControllerMillis.h>
#include <NewPing.h>


// distance sensor constants
#define TRIGGER_PIN   10
#define ECHO_PIN      9
#define MAX_DISTANCE 40

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

unsigned int pingSpeed = 50;
unsigned long pingTimer;

// garage led
#define LED_PIN 10

// constants for servo
#define SERVO_PIN 8
#define SERVO_SPEED 40
#define SERVO_MAX_ANGLE 6

// minimum distance for car detection
#define MINIMUM_DISTANCE_CAR 10
#define BUTTON_GARAGE_PIN 2

GarageControllerMillis controller(SERVO_PIN, SERVO_SPEED, SERVO_MAX_ANGLE, LED_PIN, MINIMUM_DISTANCE_CAR);

int distanceCar = 1000;
volatile bool buttonPressed = false; 

void setup() {
  pinMode(BUTTON_GARAGE_PIN, INPUT_PULLUP);
  attachInterrupt(0, changeState, RISING);
  controller.attachServo();
  pingTimer = millis();
}

void loop() {

  if (millis() >= pingTimer) {   
    pingTimer += pingSpeed;      
    sonar.ping_timer(updateDistance); 
  }

  if (buttonPressed) {
    controller.turnOnLed();
    controller.openGarage();

    delay(3000);

    controller.closeGarage();
    controller.turnOffLed();

    buttonPressed = false;
  }

  if (controller.isCarNear(distanceCar)) {
    controller.turnOnLed();
    controller.openGarage();

    delay(3000);

    controller.closeGarage();
    controller.turnOffLed();
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
