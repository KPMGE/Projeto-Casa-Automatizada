#define LDR A0
int valor = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop()
{
  valor = analogRead(LDR);
  Serial.print("Valor do LDR: ");
  Serial.println(valor);
  
  if (valor <= 560)
  {
    digitalWrite(4, HIGH);  
    digitalWrite(8, HIGH);
    digitalWrite(12, HIGH);  
  }
  else
  {
    digitalWrite(4, LOW);  
    digitalWrite(8, LOW);
    digitalWrite(12, LOW);
  } 
}