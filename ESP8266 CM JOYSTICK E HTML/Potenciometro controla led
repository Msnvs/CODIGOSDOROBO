
const int Led1 = 9;
const int Potenciomentro = A0;    

void setup() {
  pinMode(Led1, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int ValorPotenciometro = analogRead(Potenciomentro);
  int ValorLed = map(ValorPotenciometro, 0, 1023, 0, 255);
  
  analogWrite(Led1, ValorLed);
  Serial.print("Potenciômetro: ");     
  Serial.print(ValorPotenciometro);
  Serial.print(" - LED: ");
  Serial.println(ValorLed);
  
  delay(100); 
}
