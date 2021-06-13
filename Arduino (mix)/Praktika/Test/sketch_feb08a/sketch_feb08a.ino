
int ledPin = 13;
void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  Serial.println(digitalRead(13));
  digitalWrite(ledPin, HIGH);
  //delay(1000);
  digitalWrite(ledPin, LOW);
  //delay(1000);
  // put your main code here, to run repeatedly:

}
