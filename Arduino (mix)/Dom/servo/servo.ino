//-----------------------------------//
#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 9
MFRC522 Inner(SS_PIN, RST_PIN);
unsigned long uidDec, uidDecTemp;
//2426003591 - Key
//3454120363 - Card

//-----------------------------------//

#include <Keypad.h>
String KeyMap;
String OpenKey = "66";
String SafeKey = "55";
bool SafeMode = false;
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
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

//-----------------------------------//

int val = 0;
bool Open = false;
bool HavePeople = false;
long previousMillis = 0;
long interval = 5000;
unsigned long currentMillis;

//-----------------------------------//

void setup() {
  //pinMode(2, INPUT);
  SPI.begin();
  Serial.begin(9600);
  Inner.PCD_Init();
}

void loop() {
  //-----------------------------------//
  if (HavePeople == false) {
    D();
  }
  //-----------------------------------//
  KeyPad();
  //-----------------------------------//
  InnerHome();
  //-----------------------------------//
}

void D() {
  //Dvijenie//
  val = digitalRead(2);
  if (val == HIGH) {
    currentMillis = millis();
    HavePeople = true;
  }
}

void DisablePower() {
  if (currentMillis - previousMillis > interval) {
    previousMillis = currentMillis; 
    //Disable Light//
  }
}

void KeyPad() {
  //Keypad//
  char key = keypad.getKey();
   if (key and key != '*' and key != '#'){
    KeyMap += key;
  }
  if (key == '*' and KeyMap == OpenKey) {
    KeyMap = "";
    Open = true;
    return;
  }
  else if (key == '*' and KeyMap != OpenKey) {
    KeyMap = "";
    Open = false;
    return;
  }
  if (key == '*' and KeyMap == SafeKey) {
    KeyMap = "";
    SafeMode = true;
    return;
  }
  else if (key == '*' and KeyMap != SafeKey) {
    KeyMap = "";
    SafeMode = false;
    return;
  }
  if (key == '#') {
    KeyMap = "";
    return;
  }
}

void InnerHome() {
  //Inner//
  if (!Inner.PICC_IsNewCardPresent()) {
    return;
  }
  if (!Inner.PICC_ReadCardSerial()) {
    return;
  }
  uidDec = 0;
  for (byte i = 0; i < Inner.uid.size; i++) {
    uidDecTemp = Inner.uid.uidByte[i];
    uidDec = uidDec * 256 + uidDecTemp;
  }
  if (uidDec == 2426003591) {
    Open = true;
    return;
  }
  else if (uidDec == 3454120363) {
    Open = true;
    return;
  }
  else {
    Open = false;
    return;
  }
}

