int pirPin = 7;
int ledPin = 13;
int val = 0;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop(){
  val = digitalRead(pirPin);
  if (val == HIGH) {
    digitalWrite(ledPin, HIGH);
  }
 else {
    digitalWrite(ledPin, LOW);
  }
}

