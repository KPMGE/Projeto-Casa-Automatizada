
// inclusao da biblioteca para o sensor HC-SR04
#include <Ultrasonic.h>


// definicao de constantes e variaveis
#define TRIGGER_PIN 10 // pino do disparador sonico (PWM)
#define ECHO_PIN 9 // pino do receptor de echo (PWM)
long distancia = 0;
Ultrasonic ultrasonicSensor(TRIGGER_PIN, ECHO_PIN); // objeto 'ultrasonicSensor', instancia da classe 'Ultrasonic'


// funcao 'setup' roda uma vez quando a placa e ligada ou resetada
void setup()
{
	Serial.begin(9600); // inicializacao da comunicacao Serial a uma taxa de 9600 bauds
}

// funcao que se repete infinitamente quando a placa e ligada
void loop()
{
	distancia = ultrasonicSensor.Ranging(CM);// ultrasonicSensor.Ranging() retorna a distancia em centímetros (CM) ou polegadas (INC)
	Serial.print("Distancia: ");
	Serial.print(distancia); // imprime o valor da variavel distancia
	Serial.println("cm");
	delay(500);
}

