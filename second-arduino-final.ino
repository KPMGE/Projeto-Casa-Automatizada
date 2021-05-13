#include <idDHT11.h> 
#include <SaveEnergySystem.h>
#include <SecuritySystem.h>

// constants for security system
#define LDR_PIN_SECURITY A0
#define MAX_VALUE_LDR 1000
#define BUZZER_PIN 5

// instance of security system
SecuritySystem security(BUZZER_PIN, MAX_VALUE_LDR);


// constants for save energy system
#define LDR_PIN_ENERGY A1
#define MAX_LIGHT_LEVEL 200
#define AMOUNT_LEDS 4
// house leds 
int ledsPin[] = { 8, 9, 10, 11 };
// instance of class
SaveEnergySystem lights(MAX_LIGHT_LEVEL, ledsPin, AMOUNT_LEDS);


// constants for DHT sensor
#define DHT_PIN 2 
#define DHT_INTERRUPT 11 

// interruption controller
void dht11_wrapper();    
// update sensor values
void loopDHT();         

// instance of class
idDHT11 dhtSensor(DHT_PIN, DHT_INTERRUPT, dht11_wrapper); 
float temperatureC, umidity;

// value for security system
int valueSecurityLdr  = 1000;
// value for save energy system
int valueSaveEnergySystem = 0;

void setup() {
	Serial.begin(9600); 
}

void loop() {
	// monitoring lights
	valueSaveEnergySystem = analogRead(LDR_PIN_ENERGY);
	Serial.println(valueSaveEnergySystem);
  lights.lightsAutomaticManager(valueSaveEnergySystem);

	// checking security system
	valueSecurityLdr = analogRead(LDR_PIN_SECURITY);

  if (security.wasLaserInterrupted(valueSecurityLdr)) {
    security.triggerAlarm();
		valueSecurityLdr = 1000;
  }


  // update data
	//loopDHT(); 
	// display data
	//Serial.print("Temperatura em Celcius: ");
	//Serial.println(temperatureC);
	//Serial.print("Umidade Relativa: ");
	//Serial.println(umidity);
}

// interruption callback
void dht11_wrapper() {
	dhtSensor.isrCallback();
}

void loopDHT() {
	static int tempo_leitura = 1000; // 1 segundo
	static unsigned long delay_leitura = millis() + tempo_leitura + 1;
	static bool request = false;

	if ((millis() - delay_leitura) > tempo_leitura) { 
		if (! request) {
			 dhtSensor.acquire(); 
			 request = true;
		}
	}

	if (request && ! dhtSensor.acquiring()) {
		request = false;

		int result = dhtSensor.getStatus();

		switch (result) {
			case IDDHTLIB_OK: 
				Serial.println("Leitura OK"); 
				break;
			case IDDHTLIB_ERROR_CHECKSUM: 
				Serial.println("Erro\n\r\tErro Checksum"); 
				break;
			case IDDHTLIB_ERROR_ISR_TIMEOUT: 
				Serial.println("Erro\n\r\tISR Time out"); 
				break;
			case IDDHTLIB_ERROR_RESPONSE_TIMEOUT: 
				Serial.println("Erro\n\r\tResponse time out"); 
				break;
			case IDDHTLIB_ERROR_DATA_TIMEOUT: 
				Serial.println("Erro\n\r\tData time out erro"); 
				break;
			case IDDHTLIB_ERROR_ACQUIRING: 
				Serial.println("Erro\n\r\tAcquiring"); 
				break;
			case IDDHTLIB_ERROR_DELTA: 
				Serial.println("Erro\n\r\tDelta time to small"); 
				break;
			case IDDHTLIB_ERROR_NOTSTARTED: 
				Serial.println("Erro\n\r\tNao iniciado"); 
				break;
			default: 
				Serial.println("Erro Desconhecido"); 
				break;
		}

		float value = 0.00;

		value = dhtSensor.getCelsius();
		if (! isnan(value)) {      
			temperatureC = value;
		}

		value = dhtSensor.getHumidity();
		if (! isnan(value)) {      
			umidity = value;
		}  

		delay_leitura = millis();     
	}
}

