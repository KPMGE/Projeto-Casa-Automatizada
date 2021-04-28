#include <VarSpeedServo.h>

#define pinServo 8
#define pinPotenciometro A0

VarSpeedServo servo1;


void setup() {
  servo1.attach(pinServo);
  Serial.begin(9600);
}

void loop() {
  int lido = analogRead(pinPotenciometro);
  byte angulo = map(lido, 0, 1023, 0, 179);

  //servo1.write(angulo);
  servo1.slowmove(angulo, 40);

  Serial.print("A0:");
  Serial.print(lido);
  Serial.print(" angulo:");
  Serial.println(angulo);
  
}