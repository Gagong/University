int y = 9;
int g = 10;
int r = 11;
int pot = A0;
void setup () {
  pinMode (r, OUTPUT);
  pinMode (y, OUTPUT);
  pinMode (g, OUTPUT);
  pinMode (pot, INPUT);
}
void loop() {
  int x;
  x = analogRead(pot) / 4 ;
  if (x < 84)
  {
    analogWrite(y, x);
    analogWrite(g, LOW);
    analogWrite(r, LOW);
  }
  else
  {
    if (x < 170)
    {
      analogWrite(y, LOW);
      analogWrite(g, x);
      analogWrite(r, LOW);
    }
    else
    {
      analogWrite(g, LOW);
      analogWrite(r, x);
      analogWrite(y, LOW);
    }
  }
}



