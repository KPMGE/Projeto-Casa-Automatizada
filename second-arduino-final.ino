#include <SaveEnergySystem.h>
#include <SecuritySystem.h>

// constants for security system
#define LDR_PIN_SECURITY A1
#define MAX_VALUE_LDR 1000
#define BUZZER_PIN 5

// instance of security system
SecuritySystem security(BUZZER_PIN, MAX_VALUE_LDR);


// constants for save energy system
#define LDR_PIN_ENERGY A0
#define MAX_LIGHT_LEVEL 200
#define AMOUNT_LEDS 4
// house leds 
int ledsPin[] = { 8, 9, 10, 11 };
// instance of class
SaveEnergySystem lights(MAX_LIGHT_LEVEL, ledsPin, AMOUNT_LEDS);


// value for security system
int valueSecurityLdr  = 1000;
// value for save energy system
int valueSaveEnergySystem = 0;

void setup() {
	pinMode(LDR_PIN_ENERGY, INPUT);
	pinMode(LDR_PIN_SECURITY, INPUT);
	Serial.begin(9600); 
}

int safeAnalogRead(int pin) {
	int val = analogRead(pin);
	delay(10);
	val = analogRead(pin);
	delay(10);
	return val;
}

void loop() {
	// monitoring lights
	valueSaveEnergySystem = safeAnalogRead(LDR_PIN_ENERGY);
	Serial.print("luzes: ");
	Serial.println(valueSaveEnergySystem);
  lights.lightsAutomaticManager(valueSaveEnergySystem);

	// checking security system
	valueSecurityLdr = safeAnalogRead(LDR_PIN_SECURITY);
	Serial.println();
	Serial.print("garagem: ")
	Serial.println(valueSecurityLdr);

  if (security.wasLaserInterrupted(valueSecurityLdr)) {
    security.triggerAlarm();
		valueSecurityLdr = 1000;
  }
}
