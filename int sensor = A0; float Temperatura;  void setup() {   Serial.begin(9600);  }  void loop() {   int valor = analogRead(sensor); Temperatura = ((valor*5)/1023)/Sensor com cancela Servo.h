
#include <Servo.h>

const int Pinosensor = A0; 
const int Pinocentral = 9;
const int PortaoAbre = 120;
const int POrtaoFecha = 30;

Servo Portao; 

void setup() {
  Portao.attach(Pinocentral); 
  pinMode(Pinosensor, INPUT); 
}

void loop() {
  int ArivarCensor = analogRead(Pinosensor); 

  if (ArivarCensor < 500) { 
    Abrir();
  } else { 
    Fechar(); 
  }

  delay(50); 
}

void Abrir() {
  Portao.write(PortaoAbre);
}

void Fechar() {
  Portao.write(POrtaoFecha);
}
