#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>

/*
** Port CS - 10;
** Port DIN - 11;
** Port CLC - 13
*/
String Info[3] = {};
int pinCS = 10;
int numberOfHorizontalDisplays = 1;
int numberOfVerticalDisplays = 4;
int vv = 0;

Max72xxPanel matrix = Max72xxPanel(pinCS, numberOfHorizontalDisplays, numberOfVerticalDisplays);

String tape = "";
int wait = 45; // Скорость!
int spacer = 1;
int width = 5 + spacer;

String utf8rus(String source) {
  int i, k;
  String target;
  unsigned char n;
  char m[2] = { '0', '\0' };
  k = source.length(); i = 0;
  while (i < k) {
    n = source[i]; i++;
    if (n >= 0xC0) {
      switch (n) {
        case 0xD0: {
            n = source[i]; i++;
            if (n == 0x81) {
              n = 0xA8;
              break;
            }
            if (n >= 0x90 && n <= 0xBF) n = n + 0x2F;
            break;
          }
        case 0xD1: {
            n = source[i]; i++;
            if (n == 0x91) {
              n = 0xB7;
              break;
            }
            if (n >= 0x80 && n <= 0x8F) n = n + 0x6F;
            break;
          }
      }
    }
    m[0] = n; target = target + String(m);
  }
  return target;
}

String Serial_Read() {
  unsigned char c;
  String Serial_string = "";
  while (Serial.available() > 0) {
    c = Serial.read();
    if (c == '\n') {
      return Serial_string;
    }
    if (c == 0xB8) c = c - 0x01;
    if (c >= 0xBF && c <= 0xFF) c = c - 0x01;
    Serial_string = Serial_string + String(char(c));
  }
  return Serial_string;
}

void setup() {
  Serial.begin(9600);
  matrix.setIntensity(1); // Яркость!
  matrix.setRotation(matrix.getRotation() + 3);
  Info[0] = utf8rus("Добро пожаловать в СК \"Олимпия\"!");
  Info[1] = utf8rus("Мы рады приветствовать вас на мастер - классах от \"ИЭК\"!");
}
void loop() {
  if (vv == 2) {
    vv = 0;
  };
  tape = Info[vv];
  vv++;
  //if (Serial.available()) {
    //tape = Serial_Read(); // Текст при вводе!
  //}
  for ( int i = 0 ; i < width * tape.length() + matrix.width() - 1 - spacer; i++ )
  {
    matrix.fillScreen(LOW);
    int letter = i / width;
    int x = (matrix.width() - 1) - i % width;
    int y = (matrix.height() - 8) / 2;
    while ( x + width - spacer >= 0 && letter >= 0 ) {
      if ( letter < tape.length() ) {
        matrix.drawChar(x, y, tape[letter], HIGH, LOW, 1);
      }
      letter--;
      x -= width;
    }
    matrix.write();
    delay(wait);
  }
}
