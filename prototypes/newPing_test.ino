#include <NewPing.h>

#define TRIGGER_PIN   12
#define ECHO_PIN      11
#define MAX_DISTANCE 200

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

unsigned int pingSpeed = 50;
unsigned long pingTimer;   

void setup() {
  Serial.begin(9600);
  pingTimer = millis(); 
}

void loop() {
  if (millis() >= pingTimer) {
    pingTimer += pingSpeed;   
    sonar.ping_timer(echoCheck);
  }
}

void echoCheck() {
  if (sonar.check_timer()) {
    Serial.print("Ping: ");
    Serial.print(sonar.ping_result / US_ROUNDTRIP_CM);
    Serial.println("cm");
  }
}