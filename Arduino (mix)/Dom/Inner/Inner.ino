#include <Servo.h>
Servo servo;
//-----------------------------------//
#include "Stepper.h"
#define STEPS 32
Stepper stepp(STEPS, 7, 6, 4, 3);
//-----------------------------------//
//https://lesson.iarduino.ru/page/urok-6-arduino-schityvaem-metki-rfid-modul-rc522/
#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 9
MFRC522 Inner(SS_PIN, RST_PIN);
unsigned long uidDec, uidDecTemp;
//2426003591 - Key
//3454120363 - Card
//-----------------------------------//
//http://arduino.ru/forum/programmirovanie/podklyuchenie-matrichnoi-klaviatury-po-i2c
#include <Wire.h>
#include <i2ckeypad.h>
#define PCF8574_ADDR 0x20
#define ROWS 4
#define COLS 4
i2ckeypad keypad = i2ckeypad(PCF8574_ADDR, ROWS, COLS);
//#include <Keypad.h>
String KeyMap;
String OpenKey = "66";
String SafeKey = "55";
bool SafeMode = false;
/*const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
}; 
byte rowPins[ROWS] = {8, 7, 6, 5}; 
byte colPins[COLS] = {4, 3, A5, A4}; 
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
*/
//-----------------------------------//
int val = 0;
bool Open = false;
bool HavePeople = false;
long previousMillis = 0;
long interval = 5000;
unsigned long currentMillis;
const int analogPin = A0;
//-----------------------------------//
void setup() {
  Wire.begin();
  keypad.init();
  SPI.begin();
  Serial.begin(9600);
  Inner.PCD_Init();
  servo.attach(8);
  servo.write(0);
  pinMode(A0, INPUT);
  pinMode(5, OUTPUT);
  digitalWrite(5, LOW); 
}

void loop() {
  //-----------------------------------//
  HlopokInit();
  //-----------------------------------//
  KeyPad();
  //-----------------------------------//
  InnerHome();
  //-----------------------------------//
  if (digitalRead(2) == HIGH ) {
    stepp.setSpeed(1000);
    stepp.step(1);
  }
  //-----------------------------------//
  if (Open == true) {
    servo.write(80);
  }
  if (HavePeople == true and Open == true) {
    delay(1000);
    servo.write(0);
    Open = false;
  }
}
void HlopokInit() {
  int mn = 1024;
  int mx = 0;
  for (int i=0; i < 1000; i++) {
    int hlopok = analogRead(analogPin);
    mn = min(mn, hlopok);
    mx = max(mx, hlopok);
  }
  if (mx > 40){
    digitalWrite(5, HIGH);
  }
  if (mx > 50){
    digitalWrite(5, LOW); 
  }
  //Serial.print("mn=");
  //Serial.println(mn);
  Serial.print("mx=");
  Serial.println(mx);
}

void DisablePower() {
  if (currentMillis - previousMillis > interval) {
    previousMillis = currentMillis; 

  }
}

void KeyPad() {
  //Keypad//
  char key = keypad.get_key();
  if (key and key != '*' and key != '#'){
    KeyMap += key;
  }
  if (key == '*' and KeyMap == OpenKey) {
    KeyMap = "";
    Open = true;
    currentMillis = millis();
    HavePeople = true;
  }
  else if (key == '*' and KeyMap != OpenKey) {
    KeyMap = "";
    Open = false;
  }
  if (key == '*' and KeyMap == SafeKey) {
    KeyMap = "";
    SafeMode = true;
  }
  else if (key == '*' and KeyMap != SafeKey) {
    KeyMap = "";
    SafeMode = false;
  }
  if (key == '#') {
    KeyMap = "";
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
    currentMillis = millis();
    HavePeople = true;
    Serial.println("Open");
  }
  else if (uidDec == 3454120363) {
    Open = true;
    currentMillis = millis();
    HavePeople = true;
    Serial.println("Open");
  }
  else {
    Open = false;
    currentMillis = 0;
    Serial.println("Close");
  }
}

