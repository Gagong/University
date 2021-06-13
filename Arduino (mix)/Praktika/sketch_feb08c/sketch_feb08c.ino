int Arr[] = {8, 9, 10, 11, 12, 13, A0, A1};
void setup() {
  // put your setup code here, to run once:
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  for (int i = 0; i <= 8; i++) {
    pinMode(Arr[i], OUTPUT); 
  }
}

void loop() {
  /*for (int i = 0; i <= 8; i++) {
    digitalWrite(Arr[i], LOW);
    delay(50);
  }*/
  digitalWrite(A0, LOW);
  /*digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);*/
}
