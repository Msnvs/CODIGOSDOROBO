#include <HCSR04.h>

HCSR04 hc(5,6);

void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  int distancia = hc.dist();
  int (distacia,0,30,0,255);

  digitalWrite(3, LOW);
  analogWrite(9, velocidade);
  Serial.println( hc.dist() );
}
