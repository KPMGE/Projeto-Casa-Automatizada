
// inclusao da biblioteca para o sensor DHT-11
#include <DHT.h>


// definicao de constantes e variaveis
#define DHT_PIN A1 // pino do sensor DHT
#define DHT_TYPE 11 // modelo do sensor DHT
float humity = 0, temperature = 0;
DHT dhtSensor(DHT_PIN, DHT_TYPE); // objeto 'dhtSensor', instancia da classe 'DHT'


// funcao 'setup' roda uma vez quando a placa e ligada ou resetada
 void setup()
{
	Serial.begin(9600); // inicializacao da comunicacao Serial a uma taxa de 9600 bauds
	dhtSensor.begin(); // inicializacao do sensor
}

// funcao que se repete infinitamente quando a placa e ligada
void loop()
{
	// a leitura da temperatura e umidade pode levar 250ms, o atraso do sensor pode chegar a 2 segundos
	humity = dhtSensor.readHumidity();
	temperature = dhtSensor.readTemperature();

	if (isnan(temperature) || isnan(humity)) // testa se retorno e valido, caso contrario algo esta errado
	{
		Serial.println("Erro na leitura dos dados!");
		delay(500);
	}
	else
	{
		Serial.print("Umidade: ");
		Serial.print(humity);
		Serial.print(" - - - - - - - -");
		Serial.print("Temperatura: ");
		Serial.print(temperature);
		Serial.println(" *C");
		delay(100);
	}
}

