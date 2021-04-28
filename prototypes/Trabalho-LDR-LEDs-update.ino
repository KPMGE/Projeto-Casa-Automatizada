const int LDR = A0;
int valor = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop()
{
  valor = analogRead(LDR);
  Serial.print("Valor do LDR: ");
  Serial.print(valor);
  Serial.print("\n");
  
  if (valor <= 940)
  {
  	digitalWrite(8, HIGH);  
    digitalWrite(9, HIGH);  
    digitalWrite(10, HIGH);  
    digitalWrite(11, HIGH);  
  }
  else
  {
  	digitalWrite(8, LOW);  
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);  
    digitalWrite(11, LOW);  
  } 
}