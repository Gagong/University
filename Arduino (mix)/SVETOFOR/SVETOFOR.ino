int led_1 = 2;
int led_2 = 3;
int led_3 = 4;
int led_4 = 5;
int led_5 = 6;
int led_6 = 7;

void setup() {    
pinMode(led_1, OUTPUT); // установка 2­го контакта в режим вывода
pinMode(led_2, OUTPUT); // установка 3­го контакта в режим вывода
pinMode(led_3, OUTPUT); // установка 4­го контакта в режим вывода
pinMode(led_4, OUTPUT); // установка 5­го контакта в режим вывода
pinMode(led_5, OUTPUT); // установка 6­го контакта в режим вывода
pinMode(led_6, OUTPUT); // установка 7­го контакта в режим вывода
}   
void loop() {   
digitalWrite(led_1, HIGH);  // gorit krasny
digitalWrite(led_4, HIGH); // gorit zeleny
delay(3000);  // пауза 3­секунды
digitalWrite(led_4, LOW);
delay(1000);
digitalWrite(led_4, HIGH);
delay(1000);
digitalWrite(led_4, LOW);
delay(1000);
digitalWrite(led_4, HIGH);
delay(1000);
digitalWrite(led_4, LOW);
delay(1000);
digitalWrite(led_2, HIGH);  // zelty
digitalWrite(led_5, HIGH);
delay(1000);  // пауза 1­секунда
digitalWrite(led_1, LOW);
digitalWrite(led_4, LOW);
digitalWrite(led_2, LOW);
digitalWrite(led_5, LOW);
digitalWrite(led_6, HIGH); //krasny
digitalWrite(led_3, HIGH);  // перевод вывода №4 в активное состояние
delay(3000);  // пауза 3
digitalWrite(led_3, LOW);
delay(1000);
digitalWrite(led_3, HIGH);
delay(1000);
digitalWrite(led_3, LOW);
delay(1000);
digitalWrite(led_3, HIGH);
delay(1000);
digitalWrite(led_3, LOW);
delay(1000);
digitalWrite(led_2, HIGH);
digitalWrite(led_5, HIGH);
delay(1000);  // пауза 1­секунда
digitalWrite(led_1, LOW);
digitalWrite(led_2, LOW);
digitalWrite(led_3, LOW);
digitalWrite(led_4, LOW);
digitalWrite(led_5, LOW);
digitalWrite(led_6, LOW);

}   

