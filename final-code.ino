// Final code for project

// importing arduino libs
#include <NewPing.h>

// importing created libs
#include <GarageControllerMillis.h>
#include <SecuritySystem.h>
#include <SaveEnergySystem.h>
#include <WeatherSystem.h>

// --------- Garage Controller constants -----------
#define TRIGGER_PIN 10
#define ECHO_PIN 9
#define LED_GARAGE_PIN 7
#define SERVO_PIN 8
#define MAX_READING_DISTANCE 40
#define SERVO_SPEED 40
#define SERVO_MAX_ANGLE 60
#define MINIMUM_DISTANCE_CAR 10
#define BUTTON_GARAGE_PIN 2


// ----------- Save Energy System Constants -----------
#define LDR_SAVE_ENERGY_PIN A1
#define MAX_LIGHT_LEVEL 800
#define AMOUNT_LEDS 4
const int houseLedsPin[] = { 8, 9, 10, 11 };


// ----------- Save Energy System Constants -----------
#define LDR_SECURITY_PIN A0
#define BUZZER_PIN 5 
#define MAX_VALUE_LDR 1000


// variables for ping
unsigned int pingSpeed = 50;
unsigned long pingTimer;

// current car's distance
int distanceCar = 1000;
// current state of the garage button
volatile bool buttonPressed = false; 

// ------------ Instances of the Classes ---------------
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_READING_DISTANCE);
GarageControllerMillis controller(SERVO_PIN, SERVO_SPEED, SERVO_MAX_ANGLE, LED_GARAGE_PIN, MINIMUM_DISTANCE_CAR);
SecuritySystem security(LDR_SECURITY_PIN, BUZZER_PIN, MAX_VALUE_LDR);
SaveEnergySystem lights(LDR_SAVE_ENERGY_PIN, MAX_LIGHT_LEVEL, houseLedsPin, AMOUNT_LEDS);
WeatherSystem weatherSystem(DHT_PIN, DHT_INTERRUPT);

void setup() {
  pinMode(BUTTON_GARAGE_PIN, INPUT_PULLUP);
  attachInterrupt(0, changeState, RISING);
  controller.attachServo();
  controller.initServo();
  pingTimer = millis();
}

void loop() {
  // updating distance car with millis
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

  // if car is near, open the garage
  if (controller.isCarNear(distanceCar)) {
    controller.turnOnLed();
    controller.openGarage();
    delay(4000);
    controller.closeGarage();
    controller.turnOffLed();
  }

  // checking lights
  lights.lightsAutomaticManager();

  // displaying temperature and humidity on serial
  Serial.print("TemperatureC: ");
  Serial.println(weatherSystem.getTemperature());
  Serial.println("Humidity: ");
  Serial.println(weatherSystem.getHumidity());
}

void updateDistance() {
  if (sonar.check_timer()) {
    distanceCar = sonar.ping_result / US_ROUNDTRIP_CM;
  }
}

void changeState() {
  buttonPressed = !buttonPressed;
}
