int pirPin = 7;
int ledPin = 13;
int val = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop(){
  val = digitalRead(pirPin);
  if (val == HIGH) {
    digitalWrite(ledPin, HIGH);
    Serial.print("Alarm");
    delay(2000);
  }
 else {
     Serial.print("Scan");
    digitalWrite(ledPin, LOW);
    delay(1000);
  }
}

