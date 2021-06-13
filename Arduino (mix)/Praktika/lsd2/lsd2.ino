#include <LiquidCrystalRus.h>
int pos = 9;
int pos2 = 6;
bool Stop;
//int Sensor = 0;    // Sensor Port
//int Key = 1;       // Key Port
int RS = 2;        // LCD RS Port
int RW = 3;        // LCD R/W Port
int EN = 4;        // LCD E Port
int Strings = 2;   // LCD Max Strings
int Symbols = 12;  // LCD Max Symbols
int k, z, KeyPress;//Key state
String Text = "";  // M
String MText = ""; // Rus
int D0, D1, D2, D3, D4, D5, D6, D7;
int Pins[8] = {
  D0 = 5,          // LCD Data 0 Port
  D1 = 6,          // LCD Data 1 Port
  D2 = 7,          // LCD Data 2 Port
  D3 = 8,          // LCD Data 3 Port
  D4 = 9,          // LCD Data 4 Port
  D5 = 10,         // LCD Data 5 Port
  D6 = 11,         // LCD Data 6 Port
  D7 = 12          // LCD Data 7 Port
};
LiquidCrystalRus LCD(RS, RW, EN, Pins[0], Pins[1], Pins[2], Pins[3], Pins[4], Pins[5], Pins[6], Pins[7]);
String M[] = {
  "*-",
  "-***",
  "-*-*",
  "-**",
  "*",
  "**-*",
  "--*",
  "****",
  "**",
  "*---",
  "-*-",
  "*-**",
  "--",
  "-*",
  "---",
  "*--*",
  "--*-",
  "*-*",
  "***",
  "-",
  "**-",
  "***-",
  "*--",
  "-**-",
  "-*--",
  "--**",
  "*----",    // 1
  "**---",    // 2
  "***--",    // 3
  "****-",    // 4
  "*****",    // 5
  "-****",    // 6
  "--***",    // 7
  "---**",    // 8
  "----*",    // 9
  "-----",    // 0
  "******",   // .
  "*-*-*-",   // ,
  "---***",   // :
  "-*-*-*",   // ;
  "-*--*-",   // (
  "*----*",   // '
  "*-**-*",   // "
  "-****-",   // -
  "-**-*",    // /
  "**--**",   // ?
  "--**--",   // !
  ""
};

String Rus[] = {
 "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z",
 "\1", "2", "3", "4", "5", "6", "7", "8", "9", "0",
 "\.", ",", ":", ";", "(", "\'", "\"", "-", "/", "?", "!", ""
};

void setup() {
  Serial.begin(9600);
  //pinMode(Sensor, INPUT);           // Connect to Sensor
  //pinMode(Key, INPUT);              // Connect to Key
  pinMode(A0, OUTPUT);              // Connect to Led 1
  pinMode(A1, OUTPUT);              // Connect to Led 2
  pinMode(A2, OUTPUT);              // Connect to Led 3
  pinMode(A4, OUTPUT);
  analogWrite(A4, 100);
  LCD.begin(Symbols, Strings);      // Connect to LCD
  LCD.clear();                      // Clear LCD
  LCD.cursor();                     // Enable Cursor Draw
  LCD.blink();                      // Enable Cursor Blink
  //LCD.setCursor(pos, 0);
  Text = "--";
  MText = SelectText(Text);
  Serial.println(Text);
  Serial.println(MText);
  UpdateLCD(Text, MText);
  //UpdateLCD("*", "O");
  Stop = false;
  
}

void loop() {
  //z = digitalRead(Sensor);
  /*KeyPress = digitalRead(13);
  if (KeyPress == HIGH and Stop == false) {
    Add("*");
    Stop = true;
  }*/
  /*if (Text.length() == 6 or KeyPress == HIGH) {
    UpdateLCD("", SelectText(Text));
    Text = "";
    analogWrite(A0, 255);
    delay(50);
    analogWrite(A0, 0);
  }
  if (z == HIGH) {
    delay(random(150, 200));
    k = digitalRead(Sensor);
    if (z = k) {
      //Add("-");
      analogWrite(A1, 255);
    }
    else if (z != k) {
      //Add("*");
      analogWrite(A2, 255);
    }
  }*/
}

String Add(String param) {
  if (param == "-") {
    Text += "-";
    UpdateLCD(Text, SelectText(Text));
  }
  else if (param == "*") {
    Text += "*";
    UpdateLCD(Text, SelectText(Text));
  }
}

String UpdateLCD(String txt, String text) {
  LCD.clear();
  LCD.print("Symbol: ");
  LCD.print(Text += txt);
  pos++;
  LCD.setCursor(0, 1);
  LCD.print("Text: "); 
  LCD.setCursor(pos2, 1);
  LCD.print(MText += text);
  pos2++;
  LCD.setCursor(pos-1, 0);
}

String SelectText(String mtxt) {
  for (int v = 0; M[v] != ""; v++) {
    if (mtxt == M[v]) {
      return Rus[12];
    }
    else {
      return Rus[12];
    }
  }  
}
