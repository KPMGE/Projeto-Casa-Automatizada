#include <VarSpeedServo.h>
#include <GarageControllerMillis.h>
#include <NewPing.h>


// distance sensor constants
#define TRIGGER_PIN   9
#define ECHO_PIN      10
#define MAX_DISTANCE 30

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

unsigned int pingSpeed = 50;
unsigned long pingTimer;

// garage led
#define LED_PIN 13

// constants for servo
#define SERVO_PIN 6
#define SERVO_SPEED 40
#define SERVO_MAX_ANGLE 60

// minimum distance for car detection
#define MINIMUM_DISTANCE_CAR 10
#define BUTTON_GARAGE_PIN 3

GarageControllerMillis controller(SERVO_PIN, SERVO_SPEED, SERVO_MAX_ANGLE, LED_PIN, MINIMUM_DISTANCE_CAR);

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

  if (millis() >= pingTimer) {
    pingTimer += pingSpeed;
    sonar.ping_timer(updateDistance);
  }

  if (controller.isCarNear(distanceCar) || buttonPressed) {
    controller.turnOnLed();
    controller.openGarage();

    delay(3000);

    controller.closeGarage();
    controller.turnOffLed();
    distanceCar = 1000;

    buttonPressed = false;
  }
<<<<<<< HEAD

  if (controller.isCarNear(distanceCar)) {
    controller.turnOnLed();
    controller.openGarage();

    delay(3000);

    controller.closeGarage();
    controller.turnOffLed();

    distanceCar = 1000;
  }
=======
>>>>>>> 1ae98f42ac471d9fa6b57aa094fc1c6527bc97e0
}

void updateDistance() {
  if (sonar.check_timer()) {
    distanceCar = sonar.ping_result / US_ROUNDTRIP_CM;
  }
}

void changeState() {
  buttonPressed = !buttonPressed;
}
