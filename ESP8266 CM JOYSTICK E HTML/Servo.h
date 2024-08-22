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
  int leftValue = analogRead(SensorEsquerdo);
  int centerValue = analogRead(SensorCentral);
  int rightValue = analogRead(SensorDireita);

  if (centerValue > 700) { 
    forward(); 
  } else if (leftValue > 500) { 
    turnLeft(); 
  } else if (rightValue > 500) { 
    turnRight(); 
  } else { 
    stop(); 
  }
  delay(50);
}

void forward() {
  MotorEsquerdo.write(90);  
  MotorDireito.write(90); 
}

void backward() {
  MotorEsquerdo.write(0);  
  MotorDireito.write(0); 
}

void turnLeft() {
  MotorEsquerdo.write(0);  
  MotorDireito.write(90); 
}

void turnRight() {
  MotorEsquerdo.write(90); 
  MotorDireito.write(0);  
}

void stop() {
  MotorEsquerdo.write(90); 
  MotorDireito.write(90); 
}
