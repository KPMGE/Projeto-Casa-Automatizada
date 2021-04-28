
#include <Ultrasonic.h> // inclusao da biblioteca para o sensor HC-SR04
#include <Servo.h> // inclusao da biblioteca para o servomotor DGServo 9g rotacao nao-continua


// definicao de constantes e variaveis
#define PIN_BUTTOM 3 // pino do botao (Interrupt)
#define LED_PIN 12 // pino do led
#define SERVO_PIN 6 // pino do servomotor (PWM)
#define TRIGGER_PIN 9 // pino do disparador sonico (PWM)
#define ECHO_PIN 10 // pino do receptor de echo (PWM)
double time = millis(); // tempo atual
long distance = 1024; // distancia lida
int min_dist = 20; // distancia minima para acionar controlador da garagem
int servo_angle = 60; // angulo de rotacao
int servo_speed =  15; // velocidade de rotacao do servomotor (delay no movimento)
int servo_pos = 0; // posicao do servomotor
int pressedBtn = false;
Ultrasonic ultrasonicSensor(TRIGGER_PIN, ECHO_PIN); // objeto 'ultrasonicSensor', instancia da classe 'Ultrasonic'
Servo servomotor; // objeto 'servomotor', instancia da classe 'Servo'


// prototipos de funcoes
void openGarage();
void closeGarage();
int timeCount(double passed);
void pressedButton();


// funcao 'setup' roda uma vez quando a placa e ligada ou resetada
void setup()
{
	pinMode(4, OUTPUT);
	pinMode(PIN_BUTTOM, INPUT_PULLUP); // pino de interrupcao
	digitalWrite(4, HIGH); // pino para passar energia entre botao
	attachInterrupt(digitalPinToInterrupt(PIN_BUTTOM), pressedButton, HIGH); // interrupcao e executada a qualquer momento do programa
	servomotor.attach(SERVO_PIN); // adcionando servomotor
	servomotor.write(0); // iniciar na posicao 0
	Serial.begin(9600); // inicializacao da comunicacao Serial a uma taxa de 9600 bauds
}

// funcao que se repete infinitamente quando a placa e ligada
void loop()
{
	distance = ultrasonicSensor.Ranging(CM);// ultrasonicSensor.Ranging() retorna a distancia em centímetros (CM) ou polegadas (INC)

	if (distance <= min_dist || pressedBtn)
	{
		openGarage();
		time = millis();
		while (! timeCount(1800)) // apos 1,8 segundos...
		{
			Serial.print("");
		}
		closeGarage();
		digitalWrite(LED_PIN, LOW);
		pressedBtn = false;
	}

	Serial.println(distance); // imprime o valor da variavel distance
	time = millis();
}


void openGarage()
{
	digitalWrite(LED_PIN, HIGH);

	for(servo_pos = 0; servo_pos < servo_angle; servo_pos++)
	{
		servomotor.write(servo_pos);
		time = millis();
		while (! timeCount(servo_speed))
		{
			Serial.print("");
		}
	}
}

void closeGarage()
{
	digitalWrite(LED_PIN, LOW);

	for(servo_pos = servo_angle; servo_pos >= 0; servo_pos--)
	{
		servomotor.write(servo_pos);
		time = millis();
		while (! timeCount(servo_speed))
		{
			Serial.print("");
		}
	}
}

int timeCount(double passed)
{
	double deltaTime = millis() - time;

	if (passed - deltaTime <= 0)
		return 1;
	else
		return 0;
}

void pressedButton()
{
	pressedBtn = true;
}
