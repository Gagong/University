int led_1 = 2;
int led_2 = 3;
int led_3 = 4;
int led_4 = 5;
int led_5 = 6;
int led_6 = 7;

void setup() {
  for (int i = 2; i <= 7; i++) {
    pinMode(i, OUTPUT);
  }
}

void Blink(int p, int d) {
  digitalWrite(p, LOW);
  delay(d);
  digitalWrite(p, HIGH);
  delay(d);
  digitalWrite(p, LOW);
  delay(d);
  digitalWrite(p, HIGH);
  delay(d);
  digitalWrite(p, LOW);
  delay(d);
}

void Set6(int a, int b, int c, int d, int e, int f) {
  digitalWrite(led_1, a);
  digitalWrite(led_2, b);
  digitalWrite(led_3, c);
  digitalWrite(led_4, d);
  digitalWrite(led_5, e);
  digitalWrite(led_6, f);
}

void Set2(int a, int b) {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
}

void loop() {
  Set2(led_1, led_4);
  delay(3000);
  Blink(led_4, 1000);
  Set2(led_2, led_5);
  delay(1000);
  Set6(LOW, LOW, HIGH, LOW, LOW, HIGH);
  delay(3000);
  Blink(led_3, 1000);
  Set2(led_2, led_5);
  delay(1000);
  Set6(LOW, LOW, LOW, LOW, LOW, LOW);
}

