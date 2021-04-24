/*

Link do projeto no Tinkercad:

https://www.tinkercad.com/things/8rBDHDXxgxN



Em casos de dispositivos com endereco de 7 bits, o oitavo bit vai indicar leitura/escrita em um mesmo endereco de 7 bits.
Para dispositivos com endereco de 8 bits ha 2 enderecos (leitura e escrita) de 8 bits especificados pelo fabricante no datasheet.
Para obter o endereco comum de 7 bits entre ambos de 8 bits basta realizar um shift-right do bit da primeira posicao.

*/




// ------------------------- MASTER -------------------------


#include <Wire.h>


#define pinBtn 3
const int16_t I2C_master = 0x42; // enderecos hexadecimais
const int16_t I2C_slave = 0x08;
int state = 1;

void changeButtonState()
{
	state = !state;
}

void setup()
{
	Wire.begin(); // iniciar conexao i2c (endereco do master opicional)
	pinMode(pinBtn, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(pinBtn), changeButtonState, RISING);
}

void loop()
{
	Wire.beginTransmission(I2C_slave); // transmitir para o dispositivo 0x08

	Wire.write("Estado: "); // enviar 8 bytes
	Wire.write(state); // enviar 1 byte
	state = 0;

	Wire.endTransmission(); // parar transmissao

	delay(500);
}




// ------------------------- SLAVE -------------------------


#include <Wire.h>


#define pinLED 4
const int16_t I2C_master = 0x42;
const int16_t I2C_slave = 0x08;

void setup()
{
	Serial.begin(115200);
	Wire.begin(I2C_slave); // iniciar conexao i2c (endereco do slave necessario)
	Wire.onReceive(receiveEvent); // registrar evento
}

void loop()
{
	delay(500);
}

void receiveEvent(int howMany) // callback
{
	while (1 < Wire.available()) // percorrer todos, exceto o ultimo
	{
		char c = Wire.read(); // receber byte como um caractere
		Serial.print(c);
	}
	int x = Wire.read(); // receber byte como um inteiro
	Serial.println(x);

	if (x)
	{
		digitalWrite(pinLED, HIGH);
		delay(2000);
		digitalWrite(pinLED, LOW);
	}
}

