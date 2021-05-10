#include "WeatherSystem.h"

WeatherSystem::WeatherSystem(int dhtPin, int dhtInterrupt, int ledPin) {
  _dhtPin = dhtPin;
  _dhtInterrupt = dhtInterrupt;
	_ledPin = ledPin;
  Serial.begin(9600);
}

void WeatherSystem::dht11_wrapper() {
  dhtSensor.isrCallback();
}

void WeatherSystem::loopDHT() {
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

		float valor = 0.00;

		valor = dhtSensor.getCelsius();
		if (! isnan(valor)) {      
			_temperatureC = valor;
		}

		valor = dhtSensor.getHumidity();
		if (! isnan(valor)) {      
			_humidity = valor;
		}  

		delay_leitura = millis();     
	}
}

void WeatherSystem::turnOnLed() {
	digitalWrite(_ledPin, HIGH);
}

void WeatherSystem::turnOffLed() {
	digitalWrite(_ledPin, LOW);
}

float WeatherSystem::getTemperature() {
  loopDHT();
  return _temperatureC;
}

float WeatherSystem::getHumidity() {
  loopDHT();
  return _humidity;
}
