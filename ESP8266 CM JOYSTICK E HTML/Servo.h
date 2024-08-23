#include <Servo.h>

Servo MotorEsquerdo;  
Servo MotorDireito; 

const int SensorEsquerdo = A0;
const int SensorCentral = A1;
const int SensorDireita = A2;
const int Led1 = 6; 
const int Led2 = 7; 

void setup() {
  pinMode(SensorEsquerdo, INPUT);
  pinMode(SensorCentral, INPUT);
  pinMode(SensorDireita, INPUT);
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  
  digitalWrite(Led1, HIGH);
  digitalWrite(Led2, HIGH);
  
  MotorEsquerdo.attach(9);  
  MotorDireito.attach(10); 
}

void loop() {
  int moveresquerda = analogRead(SensorEsquerdo);
  int movercentral = analogRead(SensorCentral);
  int moverdireita = analogRead(SensorDireita);

  if (movercentral > 700) { 
   frente(); 
  } else if (moveresquerda > 500) { 
    esquerda(); 
  } else if (moverdireita > 500) { 
    direita(); 
  } else { 
    parar(); 
  }
  delay(50);
}

void frente() {
  MotorEsquerdo.write(90);  
  MotorDireito.write(90); 
}

void tras() {
  MotorEsquerdo.write(0);  
  MotorDireito.write(0); 
}

void esquerda() {
  MotorEsquerdo.write(0);  
  MotorDireito.write(90); 
}

void direita() {
  MotorEsquerdo.write(90); 
  MotorDireito.write(0);  
}

void parar() {
  MotorEsquerdo.write(90); 
  MotorDireito.write(90); 
}
