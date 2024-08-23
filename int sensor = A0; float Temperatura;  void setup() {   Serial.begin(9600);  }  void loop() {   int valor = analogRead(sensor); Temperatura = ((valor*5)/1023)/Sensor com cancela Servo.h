#include <Servo.h>

const int sensorPin = A0; // Sensor de linha conectado ao pino A0
const int servoPin = 9; // Servo motor conectado ao pino 9
const int gateOpenAngle = 120; // Ângulo de abertura da cancela
const int gateCloseAngle = 30; // Ângulo de fechamento da cancela

Servo gateServo; // Cria um objeto Servo para controlar o servo motor

void setup() {
  gateServo.attach(servoPin); // Inicializa o servo motor no pino 9
  pinMode(sensorPin, INPUT); // Define o pino do sensor de linha como entrada
}

void loop() {
  int sensorValue = analogRead(sensorPin); // Lê o valor do sensor de linha

  if (sensorValue < 500) { // Se o sensor de linha não detectar a linha
    openGate(); // Abre a cancela
  } else { // Se o sensor de linha detectar a linha
    closeGate(); // Fecha a cancela
  }

  delay(50); // Aguarda 50 ms antes de ler o sensor novamente
}

void openGate() {
  gateServo.write(gateOpenAngle); // Abre a cancela
}

void closeGate() {
  gateServo.write(gateCloseAngle); // Fecha a cancela
}
