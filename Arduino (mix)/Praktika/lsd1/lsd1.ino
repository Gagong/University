#include <LiquidCrystal.h>
 
LiquidCrystal disp(2, 3, 4, 9, 10, 11, 12); // создаем объект
char data;
 
void setup()
{ 
  pinMode(A0, OUTPUT);
  analogWrite(A0, 100);
  Serial.begin(9600); // инициализируем последовательны порт
  disp.begin(12, 2);  // инициализируем дисплей 4 строки по 20 символов
}
 
void loop()
{
  if (Serial.available()) {     // если есть данные
    data= Serial.read();  // читаем символ
    if( (data != 0xd) && (data != 0xa) ) {  // перевод строки
      disp.write(data);  // выводим символ на экран       
    }
  }
}
