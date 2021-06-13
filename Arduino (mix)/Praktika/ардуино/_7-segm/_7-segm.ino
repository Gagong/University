int x1 = 815 ; //Минимальное значение освещенности
int x2 = 251 ; //Максимальное значение освещенности
int z = 0 ;//Временная переменная

void setup() {
  Serial.begin(9600);
  analogWrite(A2,0);
}

void loop() {
  z = constrain(analogRead(A1),x2,x1);
  analogWrite(A2,map(z,x1,x2,255,0));
}
