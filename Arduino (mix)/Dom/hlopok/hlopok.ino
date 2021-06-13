const int analogPin = A0;
int ledPin = 13;
void setup() {
Serial.begin(9600);
pinMode(5, OUTPUT);
digitalWrite(5, LOW); 
}

void loop() {
int mn = 1024;
int mx = 0;
for (int i=0; i < 1000; i++) {
int val = analogRead(analogPin);
mn = min(mn, val);
mx = max(mx, val);
}
if  ( mx > 40  ){
  digitalWrite(5, HIGH);
}
if  ( mx > 60  ){
  digitalWrite(5, LOW); 
}
Serial.print("m=");
Serial.print(mx);
Serial.println();
}
