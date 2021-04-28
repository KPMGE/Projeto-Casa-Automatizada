// test implementation for security system

// constants for LDR
#define LDR_PIN A0

// constants for buzzer
#define BUZZER_PIN 9 
#define AMOUNT_NOTES 7 
#define DELAY_BUZZER 1000 
const int notes[] = { 524, 588, 660, 699, 785, 881, 989 }; // notes for buzzer

void setup() {
	pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  if (wasLaserInterrupted()) {
    triggerAlarm();
  }
}

void wasLaserInterrupted() {
  const int valueLDR = analogRead(LDR_PIN);

  if (valueLDR < 1000) {
    return true;
  }
  return false;
}

void triggerAlarm() {
  for (int i = 0; i < AMOUNT_NOTES; i++) {
    tone(BUZZER_PIN, notes[i], DELAY_BUZZER);
    delay(DELAY_BUZZER);
  }
  delay(DELAY_BUZZER);
}