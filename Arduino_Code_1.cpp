#include <Wire.h> // Подключение библиотеки I2C
#include <TimerOne.h> // Подключение библиотеки прерывания 1 таймера 
#include <Arduino.h> // Подключения библиотеки Arduino core
#include <Time.h> // Подключение библиотеки обработки времени
#include <DS1307RTC.h> // Подключение библиотечи часов реального времени 
#include <LiquidCrystal_I2C.h> // Подключение библиотеки ЖК индикатора 
#include <MaxMatrix.h> // Подключение библиотеки светодиодной матрицы 
#include <TM1637.h> // Подключение библиотеки четырехразрядного семисегментного индикатора
#include <DHT.h> // Подключение библиотеки датчика температуры и влажности 
#include <Servo.h> // Подключени библиотеки свервомотора
#include <Ultrasonic.h> // Подключени библиотеки ультразвукового дальномера 
#include <Bounce2.h> // Подключени библиотеки от дребезга контактов

//Обьявление портов датчиков 
#define STOP 0 // Button 1
#define START 1 // Button 2 
#define VOICE 2 // Zummer 
#define DCLK 3 // 4-Digit Display 
#define DDIO 4 // 4 Digit Display 
#define DHTPIN 5 // DHT
#define SERVO 6 // Servo 
#define TRIG 7 // Ultrasonic 
#define ECHO 8 // Ultrasonic 
#define RED 9 // RGB [RED]
#define GREEN 10 // RGB [GREEN] 
#define BLUE 11 // RGB [BLUE]
#define DIN 12 // LED Matrix 
#define CS 13 // LED Matrix 
#define RES1 A0 // Slide POT 
#define RES2 A1 // POT 
#define RELAY A2 // Relay 
#define CLK A3 // LED Matrix

// Дополнительные константы
#define COUNT 1 // LED Matrix count 
#define INTENSITY 7 // LED Matrix intensity

// Массивы данных
int8_t TimeDisp[4] = {0x00, 0x00, 0x00, 0x00};
uint8_t humi[8] = {0x4, 0x4, 0xE, 0x1F, 0x1F, 0xE, 0x0}; 
uint8_t ter[8] = {0xE, 0xA, 0xA, 0xA, 0xA, 0xA, 0x4}; 
uint8_t circle[8] = {0xC, 0x12, 0x12, 0xC, 0x0, 0x0, 0x0};

//Используемые переменные 
String Spase = " ";
String Point = ".";
String doublePoint = ":"; 
int counter = 8;
bool state = true;
volatile int seconds, minutes, col, row; 
bool stateFor4D = false;
int toMin = 0;


//Инициализация модулей и датчиков 
LiquidCrystal_I2C lcd(0x27, 20, 4); // ЖК индикатор
MaxMatrix matrix(DIN, CS, CLK, COUNT); // Светодиодная матрица	
TM1637 tm1637(DCLK, DDIO); // Четырехразрядный семисегментный индикатор 
DHT dht(DHTPIN, DHT11); // Датчик температуры и влажности
Servo sg_90; // Сервопривод
Ultrasonic ultrasonic(TRIG, ECHO, 30000); // Ультразвуковой дальномер ~500cm 
tmElements_t tm; // Глобальная переменная времени часов DS1307

void setup() {
  pinMode(0, INPUT); // Установка порта 0 на вывод (Кнопка) 
  pinMode(1, INPUT); // Установка порта 1 на вывод (Кнопка) 
  digitalWrite(STOP, HIGH); // Подтягивание резистора 
  digitalWrite(START, HIGH); // Подтягивание резистора
  matrix.init(); // Инициализация матрицы 
  matrix.setIntensity(INTENSITY); // Установка яркости матрицы
  sg_90.attach(SERVO); // Инициализация сервомотора 
  sg_90.write(10); // Поворот сервомотора до 10 градусов
  pinMode(VOICE, OUTPUT); // Установка порта зуммера на вывод
  tm1637.set(); // Инициализация четырехразрядного семисегментного индикатора 
  tm1637.init(); // Запуск индикатора
  dht.begin(); // Инициализация датчика температуры и влажности
  lcd.init(); // Инициализация ЖК индикатора 
  lcd.clear(); // Очистка ЖК индикатора 
  lcd.backlight(); // Включени подсветки	
 
  // Создание пользовательских символов на ЖК индикаторе 
  lcd.createChar(1, humi);
  lcd.createChar(2, circle); 
  lcd.createChar(3, ter);

  // Установка портов RGB светодиода на вывод 
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT); 
  pinMode(BLUE, OUTPUT);
  pinMode(RELAY, OUTPUT); // Установка порта реле на вывод


  //setSerial(); // Функция подключения Serial 
  fix13Port(); // Исправление ошибки на 13 порту
  // Считывание температуры и влажности с датчика 
  int h = dht.readHumidity();
  int t = dht.readTemperature();


  // Процедура обработки и вывода данных с датчика температуры и влажности на ЖК индикатор
  if (isnan(h) || isnan(t) || (h == 0 && t == 0)) { 
    writeData(0, 1, " DHT-11 Disconected");
  }
  else {
    String data_1 = " " + toString(t);
    String data_2 = " " + toString(h) + "%	";
    lcd.setCursor(3, 1); 
    lcd.write(3); 
    lcd.print(data_1); 
    lcd.write(2); 
    lcd.print("C	"); 
    lcd.write(1); 
    lcd.print(data_2);
  }
  Timer1.initialize(1000000); // Инициализация прерывания каждую секунду 
  Timer1.attachInterrupt(interruptHandler); // Вызываемая прерыванием функция
}


void loop() // Бесконечный цикл
{
  setRTC(); // Вызов функции обработчика часов реального времени
  matrix.setDot(col, row, true); // Бегущий огонь 
  matrix.setDot(col - 1, row, false); // Бегущий огонь

  if (stateFor4D)
    tm1637.point(POINT_ON); // Точки на четырехразрядном индикаторе else
  tm1637.point(POINT_OFF); // Точки на четырехразрядном индикаторе

  // Преобразование и занесение данных минут и секунд в массив 
  TimeDisp[0] = minutes / 10;
  TimeDisp[1] = minutes % 10; 
  TimeDisp[2] = seconds / 10; 
  TimeDisp[3] = seconds % 10;

  tm1637.display(TimeDisp); // Вывод данных на индикатор 
  displayTandH(0, 1); // Обработчик температуры и влажности 
  displayDistance(); // Обработчик датчика расстояния
  keyHandler(); // Обработчик реле
}

void interruptHandler() // Тело прерывания
{
  switch (counter)
    {
      case 9 :
        digitalWrite(9, HIGH); 
        digitalWrite(10, LOW); 
        digitalWrite(11, LOW); 
        break;
      case 10 : 
        digitalWrite(9, LOW);
        digitalWrite(10, HIGH); 
        digitalWrite(11, LOW); 
        break;
      case 11 : 
        digitalWrite(9, LOW);
        digitalWrite(10, LOW); 
        digitalWrite(11, HIGH); 
        counter = 8;
        break;
      default :
        break;
    }
  counter++; 
  col++;

  if (col == 8) {
    col = 0; 
    matrix.clear(); 
    row++;
  }

  if (row == 8) 
    row = 0;
  stateFor4D = !stateFor4D; 
  seconds++;

  if (seconds == 60) {
    tone(2, 1000, 100);
    seconds = 0; 
    minutes++;
  }

  if (minutes == 60) 
    minutes = 0;
}

void keyHandler() // Тело реле
{
  String data;
  toMin = map(analogRead(A0), 0, 1000, 0, 58); 
  if (toMin <= minutes) {
    digitalWrite(A2, HIGH); 
    data = "	Relay enabled!	"; 
    writeData(0, 3, data);
  }
  else {
    digitalWrite(A2, LOW);
    data = "Relay timer: " + fixDigits(toMin) + " min"; 
    writeData(0, 3, data);
  }
}

void displayDistance() // Расстояния
{
  int v = ultrasonic.Ranging(CM); 
  String data;

  if (v == 0 && v <= 400)
    data = "HC-SR04: Disconected"; 
  else if (v >= 400 && v != 0)
    data = " HC-SR04: No signal";
  else if (v > 0 && v <= 400)
    data = " Distance: " + fix3Digits(v) + " cm ";
  writeData(0, 2, data);
}

void displayTandH(int x, int y) // Тело датчика температуры и влажности
{
  int h = dht.readHumidity(); 
  int t = dht.readTemperature();
  if (isnan(h) || isnan(t) || (h == 0 && t == 0)) { 
    writeData(x, y, " DHT-11 Disconected");
  }
  else {
    String data_1 = " " + toString(t);
    String data_2 = " " + toString(h) + "%	";
    lcd.setCursor(3, 1); 
    lcd.write(3); 
    lcd.print(data_1); 
    lcd.write(2); 
    lcd.print("C	"); 
    lcd.write(1); 
    lcd.print(data_2);
  }
}

void checkState() // Тело кнопок
{
  if (!digitalRead(STOP) && digitalRead(START)) 
    state = false;
  else if (!digitalRead(START) and digitalRead(STOP)) 
    state = true;
}

void setRTC() // Тело часов реального времени
{
  if (RTC.read(tm)) {
    String Time = fixDigits(tm.Hour) + doublePoint + fixDigits(tm.Minute) + double- Point + fixDigits(tm.Second);
    String Date = fixDigits(tm.Day) + Point + fixDigits(tm.Month) + Point + toString(tmYearToCalendar(tm.Year));
    String data = Time + Spase + Date;
    writeData(0, 0, data);
  }
  else if (RTC.chipPresent()) {
    writeData(0, 0, "	Error: SetTime");
  }
  else {
    writeData(0, 0, " Error: Circuitry");
  }
}

/* Дополнительные фунции */

String fix3Digits(int number) // Правильное отображение 3х цифр на индикаторе
{
  if (number >= 0 && number < 10) {
    return "00" + String(number, DEC);
  }
  else if (number >= 10 && number < 100) {
    return "0" + String(number, DEC);
  }
  else {
    return String(number, DEC);
  }
}

String fixDigits(int number) // Правильное отображение 2х цифр на индикаторе
{
  if (number >= 0 && number < 10) {
    return "0" + String(number, DEC);
  }
  else {
    return String(number, DEC);
  }
}

String toString(int data) // Перевод числа в строку
{
  return String(data, DEC);
}


void writeData(int x, int y, String data) // Вывод данных на экран по координатам
{
  lcd.setCursor(x, y); 
  lcd.print(data);
}


void fix13Port() // Устранение неполадок с 13 портом
{
  pinMode(13, OUTPUT); 
  digitalWrite(13, HIGH);
}


void setSerial() { // Подключение Serial 
  Serial.begin(9600);
}
