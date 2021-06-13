#include <LiquidCrystalRus.h>
                  // Can't use 0 and 1 port, cos Serial enabled
int RS = 2;       // LCD RS Port
int RW = 3;       // LCD R/W Port
int EN = 4;       // LCD E Port

int Strings = 2;  // LCD Max Strings
int Symbols = 12; // LCD Max Symbols

int D4, D5, D6, D7;
int Pins[4] = {
  D4 = 9,         // LCD Data 4 Port
  D5 = 10,        // LCD Data 5 Port
  D6 = 11,        // LCD Data 6 Port
  D7 = 12         // LCD Data 7 Port
};
String string;
char Symbol;

/*
  {
    Can Use:
      LCD.begin(symbols, strings) | Инициализирует интерфейс индикатора.
                                    Задает размерность индикатора.
                                    Метод должен быть вызван первым, до использования других функций класса.
      LCD.clear()
      LCD.home() | Установка курсора в левый верхний угол.
      LCD.setCursor(x, y)
      LCD.write(data)
      LCD.print(data)
      LCD.print(data, BASE) | BIN, DEC, OCT, HEX
      LCD.cursor() | Включает режим отображения курсора.
                     Позиция, куда будет выведен следующий символ, подчеркивается.
      LCD.noCursor()
      LCD.blink() | Включает режим мигающего курсора.
                    Используется совместно с функцией cursor().
      LCD.noBlink()
      LCD.display() | Включает экран после того, как он был выключен функцией noDisplay().
                      На экране отобразится информация, которая была до выключения.
      LCD.noDisplay()
      LCD.scrollDisplayLeft()
      LCD.scrollDisplayRight()
      LCD.autoscroll()
      LCD.leftToRight()
      LCD.rightToLegt()
      LCD.noAutoscroll()
      LCD.createChar(num, data) | Контроллер допускает создание до 8 символов  (0…7) размером 5x8 пикселей.
                                  Изображение символа задается массивом размерностью 8 байт.
                                  5 младших битов каждого байта определяют состояние пикселей строки.
                                  byte smile[8] = {
                                    B00000000,
                                    B00010001,
                                    B00000000,
                                    B00000000,
                                    B00010001,
                                    B00001110,
                                    B00000000,
                                    B00000000
                                  };
                                  LCD.createChar(0, smile);
                                  LCD.write(byte(0));
  }


*/

LiquidCrystalRus LCD(RS, RW, EN, Pins[0], Pins[1], Pins[2], Pins[3]);

void setup() {
  Serial.begin(9600);               // Connect to PC

  LCD.begin(Symbols, Strings);      // Connect to LCD
  pinMode(A0, OUTPUT);
  analogWrite(A0, 100);
  LCD.clear();                      // Clear LCD
  LCD.cursor();                     // Enable Cursor Draw
  LCD.blink();                      // Enable Cursor Blink

  string = "LCD Connected!";
  LCD.print(string);
  LCD.setCursor(0, 1);
}

void loop() {
  if (Serial.available()) {
    Symbol = Serial.read();
    LCD.write(Symbol);
  }
}

