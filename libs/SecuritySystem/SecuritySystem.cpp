// implementation of class security system 

#include "Arduino.h"
#include "SecuritySystem.h"

#define AMOUNT_NOTES 7 
#define DELAY_BUZZER 1000 
const int notes[] = { 524, 588, 660, 699, 785, 881, 989 }; // notes for buzzer

SecuritySystem::SecuritySystem(int ldrPin, int buzzerPin, int maxValueLdr) {
  pinMode(buzzerPin, OUTPUT);

  _ldrPin = ldrPin;
  _buzzerPin = buzz;
  _maxValueLdr = maxValueLdr;
}

bool SecuritySystem::wasLaserInterrupted() {
  const int valueLDR = analogRead(_ldrPin);

  if (valueLDR < _maxValueLdr) {
    return true;
  }
  return false;
}

void SecuritySystem::triggerAlarm() {
  for (int i = 0; i < AMOUNT_NOTES; i++) {
    tone(BUZZER_PIN, notes[i], DELAY_BUZZER);
    delay(DELAY_BUZZER);
  }
  delay(DELAY_BUZZER);
}
