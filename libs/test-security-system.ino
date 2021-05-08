// Testing implementation of security system
#include <SecuritySystem.h>

// LDR pin
#define LDR_PIN A0
// max value for ldr detection
#define MAX_VALUE_LDR 1000

// buzzer pin
#define BUZZER_PIN 9 

// instance of security system
SecuritySystem security(LDR_PIN, BUZZER_PIN, MAX_VALUE_LDR);

void setup() {

}

void loop() {
  if (security.wasLaserInterrupted()) {
    security.triggerAlarm();
  }
}

