int button = 11;
int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;
int h = 9;
int O = HIGH;
int L = LOW;
int m = 0;
int i;
int k;
int leds[10][7] = 
{
  {O, O, O, O, O, O, L},
  {L, O, O, L, L, L, L},
  {O, O, L, O, O, L, O},
  {O, O, O, O, L, L, O},
  {L, O, O, L, L, O, O},
  {O, L, O, O, L, O, O},
  {O, L, O, O, O, O, O},
  {O, O, O, L, L, L, L},
  {O, O, O, O, O, O, O},
  {O, O, O, O, L, O, O}
};

void setup() {
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(h, OUTPUT);
  pinMode(button, INPUT); 
}

void GetNum(int numa) {
  for(i = 0; i < 10; i = i + 1) {
    if (i == numa) {
      for(k = 0; k < 7; k = k + 1) {
        digitalWrite(k + 2, leds[i][k]);
      }
    }
  }
}

void loop() {
  int buttonstate = digitalRead(button);
  if ((buttonstate == LOW) and (m <= 9)) {
    m = 0;
    delay(500);
  }
  else
  {
    m = m + 1;
  }
  GetNum(m);
}
