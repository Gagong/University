#include <Keypad.h>
String z;
String y = "66";
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
}; 
byte rowPins[ROWS] = {8, 7, 6, 5}; 
byte colPins[COLS] = {4, 3, A2, A3}; 

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  Serial.begin(9600);
}
  
void loop(){
  char key = keypad.getKey();
   if (key and key != '*' and key != '#'){
    z += key;
    Serial.println(z);
  }
  if (key == '*' and z == y) {
    z = "";
    analogWrite(A0, 255);
    delay(250);
    analogWrite(A0, 0);
  }
  else if (key == '*' and z != y) {
    z = "";
  }
  if (key == '#') {
    z = "";
  }
}
