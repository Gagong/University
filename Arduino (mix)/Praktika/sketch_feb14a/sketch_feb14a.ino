#include <Wire.h>
#include <LiquidCrystal_I2C.h>
int pin = 3;
LiquidCrystal_I2C lcd(0x27, 20, 4); // LCD2004
void setup()
{

  lcd.init();  // initialize the lcd
  lcd.backlight();
  lcd.print("start LCD2004");
  pinMode(pin, INPUT);
  delay(1000);
  lcd.clear();
}
void loop()
{
  lcd.setCursor(0, 0);
  lcd.print("S040:Knock sensor");
  int vibration = digitalRead(pin);
  lcd.setCursor(0, 1);
  lcd.print("digital=" + (String)vibration + "  ");
  if (vibration == LOW)
  {
    lcd.setCursor(0, 2);
    lcd.print("knock=detected");
  }

  else {
    lcd.setCursor(0, 2);
   lcd.print("knock=NONE    ");
  }
  delay(500);
}

