int pirPin = 7;
int ledPin = 13;
int val = 0;
int val2 = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop(){
  val = digitalRead(pirPin);
  Serial.println(val);
  val2 = analogRead(A0);
  int val3 = val2/9.31l;
  Serial.println(val3);
  if (val == HIGH) {
    digitalWrite(ledPin, HIGH);
  }
 else {
    digitalWrite(ledPin, LOW);
  }
}
