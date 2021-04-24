
// definicao de constantes e variaveis
#define BUZZER_PIN 9 // pino do buzzer (PWM)
int notas[] = { 524, 588, 660, 699, 785, 881, 989 }; // vetor de notas


// funcao 'setup' roda uma vez quando a placa e ligada ou resetada
void setup()
{
	pinMode(BUZZER_PIN, OUTPUT); // pino do buzzer definido como output
}

// funcao que se repete infinitamente quando a placa e ligada
void loop()
{
	for (int i = 0; i < 7; i++)
	{
		tone(BUZZER_PIN, notas[i], 1000); // tocar nota 'i' durante 1s
		delay(1000);
	}
	delay(1000);
}

