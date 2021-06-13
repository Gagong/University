int t1, t2, v;
void setup() {
  Serial.begin(9600);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
}

void loop() 
{
  t1 = analogRead(A1);
  t2 = analogRead(A2);
  v = analogRead(A3);
  Serial.print("Temp 1: ");
  Serial.println(t1);
  Serial.print("Temp 2: ");
  Serial.println(t2);
  Serial.print("Vlagnost: ");
  Serial.println(v);
  delay(1000);
}
