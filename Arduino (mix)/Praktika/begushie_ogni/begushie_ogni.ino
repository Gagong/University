
int led1=9;
int led2=10;
int led3=11;
void setup()
{
pinMode(led1,OUTPUT);  
pinMode(led2,OUTPUT); 
pinMode(led3,OUTPUT); 
  }
  void loop()
  {
digitalWrite(led1,HIGH);
delay(200);
digitalWrite(led1,LOW);
delay(200);
digitalWrite(led2,HIGH);
delay(200);
digitalWrite(led2,LOW);
delay(200);
digitalWrite(led3,HIGH);
delay(200);
digitalWrite(led3,LOW);
    }
