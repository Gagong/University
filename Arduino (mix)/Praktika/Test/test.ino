int Arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, A0, A1, A2, A3, A4};
int Data1[] = {0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7};
int Data2[] = {8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 12, 12, 13, 13, 13, 13, 13, 13, 13, 13, A0, A0, A0, A0, A0, A0, A0, A0, A1, A1, A1, A1, A1, A1, A1, A1};
void setup() {
  for (int i = 0; i <= 16; i++) {
     pinMode(Arr[i], OUTPUT);
     if (i > 7) {
      digitalWrite(Arr[i], HIGH);
     }
  }
  //analogWrite(A1, 0);
  //digitalWrite(7, HIGH);
}

void loop() {
  for (int j = 0; j < 50; j++) {
    for (int v = 0; v < 64; v++) { 
      digitalWrite(Data1[v], HIGH);
      if (Data2[v] >= 14 and Data2[v] <= 19) {
        analogWrite(Data2[v], 0);
      }
      else
      {
        digitalWrite(Data2[v], LOW);
      }
      delay(50);
      digitalWrite(Data1[v], LOW);
      if (Data2[v] >= 14 and Data2[v] <= 19) {
        analogWrite(Data2[v], 255);
      }
      else
      {
        digitalWrite(Data2[v], HIGH);
      }
    }
  }
}

