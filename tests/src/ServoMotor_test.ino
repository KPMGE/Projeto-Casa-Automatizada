
// inclusao da biblioteca para o servomotor DGServo 9g rotacao nao-continua
#include <Servo.h>


// definicao de constantes e variaveis
#define SERVO_PIN 6 // pino do servomotor (PWM)
int servo_angle = 60; // angulo de rotacao
int servo_speed =  15; // velocidade de rotacao do servomotor (delay no movimento)
int servo_pos = 0; // posicao do servomotor
Servo servomotor; // objeto 'servomotor', instancia da classe 'Servo'


// funcao 'setup' roda uma vez quando a placa e ligada ou resetada
void setup()
{
	servomotor.attach(SERVO_PIN); // adcionando servomotor
	servomotor.write(0); // iniciar na posicao 0
}

// funcao que se repete infinitamente quando a placa e ligada
void loop()
{
	// fazer movimento
	for(servo_pos = 0; servo_pos < servo_angle; servo_pos++)
	{
		servomotor.write(servo_pos);
		delay(servo_speed);
	}
	delay(600); // apos 0,6 segundos...
	// desfazer movimento
	for(servo_pos = servo_angle; servo_pos >= 0; servo_pos--)
	{
		servomotor.write(servo_pos);
		delay(servo_speed);
	}
}

