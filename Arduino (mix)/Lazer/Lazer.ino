void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(A0, INPUT);
  digitalWrite(2, HIGH);
}

void loop() {
  int z = analogRead(A0);
  if (z < 100) {
    digitalWrite(3, HIGH);
    delay(100);
    digitalWrite(3, LOW);
    delay(100);
  }
  else {
    digitalWrite(3, LOW);
  }
}
