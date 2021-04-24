
// definicao de constantes e variaveis
#define LDR_PIN A0 // pino do sensor de luminosidade
#define LED_PIN 8 // pino do led
int valor = 0;


// funcao 'setup' roda uma vez quando a placa e ligada ou resetada
void setup()
{
	Serial.begin(9600); // inicializacao da comunicacao Serial a uma taxa de 9600 bauds
	pinMode(LED_PIN, OUTPUT);
}

// funcao que se repete infinitamente quando a placa e ligada
void loop()
{
	valor = analogRead(LDR_PIN);
	Serial.print("Valor do LDR: ");
	Serial.println(valor); // imprime o valor da variavel

	if (valor < 900) // se o valor for menor que 900...
		digitalWrite(LED_PIN, HIGH); // liga led
	else // se nao
		digitalWrite(LED_PIN, LOW); // desliga led
}

