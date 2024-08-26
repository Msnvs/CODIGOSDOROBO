#include <Servo.h>

const int Pinosensor = A0; 
const int Pinocentral = 9;
const int PortaoAbre = 120;
const int POrtaoFecha = 30;
const int LedVermelho = 4; 
const int LedVerde = 5; 

Servo Portao; 

void setup() {
  Portao.attach(Pinocentral); 
  pinMode(Pinosensor, INPUT); 
  pinMode(LedVermelho, OUTPUT); 
  pinMode(LedVerde, OUTPUT); 
}

void loop() {
  int ArivarCensor = analogRead(Pinosensor); 

  if (ArivarCensor < 500) { 
    Abrir();
  } else { 
    Fechar(); 
  }

  piscarLeds();

  delay(50); 
}

void Abrir() {
  Portao.write(PortaoAbre);
}

void Fechar() {
  Portao.write(POrtaoFecha);
}

void piscarLeds() {
  digitalWrite(LedVermelho, HIGH); 
  digitalWrite(LedVerde, LOW); 
  delay(50); 
  digitalWrite(LedVermelho, LOW); 
  digitalWrite(LedVerde, HIGH); 
  delay(50); 
}
