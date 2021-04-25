
/*
	Interrupcoes

      	          int.0	  int.1	  int.2	  int.3	  int.4	  int.5
 Uno          	    2	    3
 Mega2560	        2	    3	   21	   20	   19	   18
 Leonardo	        3	    2	   0	   1

*/



// inclusao da biblioteca para o sensor DHT-11
/* #include <DHT.h>   essa usa a funcao delay(), o que pode ser um problema para um Arduino multitarefa */
#include <idDHT11.h> // essa usa a funcao millis() com interrupcao, que nao interrompe as tarefas do Arduino


// definicao de constantes, variaveis e funcoes
#define DHT_PIN 2 // pino do sensor DHT (Interrupt)
#define DHT_INTERRUPT 11 // numero da interrupcao respectiva a porta definida anteriormente

void dht11_wrapper();     // funcão de controle da interrupçao
void loopDHT();           // funcão que atualiza a leitura do sensor

idDHT11 dhtSensor(DHT_PIN, DHT_INTERRUPT, dht11_wrapper); // objeto 'dhtSensor', instancia da classe 'idDHT11'
float temperaturaC, temperaturaF, temperaturaK, umidade, dewPoint, dewPointSlow;


// funcao 'setup' roda uma vez quando a placa e ligada ou resetada
 void setup()
{
	Serial.begin(9600); // inicializacao da comunicacao Serial a uma taxa de 9600 bauds
}

// funcao que se repete infinitamente quando a placa e ligada
void loop()
{
	loopDHT(); // atualizar dados...

	Serial.print("Temperatura em Celcius: ");
	Serial.println(temperaturaC);
	Serial.print("Umidade Relativa: ");
	Serial.println(umidade);
	Serial.print("Ponto de Orvalho: ");
	Serial.println(dewPoint);

	Serial.println();
}


// callback para interrupcoes
void dht11_wrapper()
{
	dhtSensor.isrCallback();
}

void loopDHT()
{
	static int tempo_leitura = 1000; // 1 segundo
	static unsigned long delay_leitura = millis() + tempo_leitura + 1;
	static bool request = false;

	if ((millis() - delay_leitura) > tempo_leitura)
	{ 
		if (! request)
		{
			 dhtSensor.acquire(); 
			 request = true;
		}
	}

	if (request && ! dhtSensor.acquiring())
	{
		request = false;

		int result = dhtSensor.getStatus();

		switch (result)
		{
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
		if (! isnan(valor))
		{      
			temperaturaC = valor;
		}

		valor = dhtSensor.getHumidity();
		if (! isnan(valor))
		{      
			umidade = valor;
		}  

		valor = dhtSensor.getFahrenheit();
		if (! isnan(valor))
		{      
			temperaturaF = valor;
		}  

		valor = dhtSensor.getKelvin();
		if (! isnan(valor))
		{      
			temperaturaK = valor;
		}  

		valor = dhtSensor.getDewPoint();
		if (! isnan(valor))
		{      
			dewPoint = valor;
		}  

		valor = dhtSensor.getDewPointSlow();
		if (! isnan(valor))
		{      
			dewPointSlow = valor;
		} 

		delay_leitura = millis();     
	}
}

