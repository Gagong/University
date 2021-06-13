#include <Keypad.h>
String z;
String y = "12C45";
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
}; 
byte rowPins[ROWS] = {11,10, 9, 8}; 
byte colPins[COLS] = {7, 6, 5, 4}; 

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(13, OUTPUT);
}
  
void loop(){
  char key = keypad.getKey();
  
  if (key and key != '*' and key != '#'){
    z += key;
    Serial.println(z);
  }
  if (key == '*' and z == y) {
    digitalWrite(13, HIGH);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    z = "";

  }
  else if (key == '*' and z != y) {
    digitalWrite(13, LOW);
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    z = "";
  }
  if (key == '#') {
    digitalWrite(13, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    z = "";
  }
}
