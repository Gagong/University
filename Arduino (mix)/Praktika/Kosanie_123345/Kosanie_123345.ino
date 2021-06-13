int g = 0;
int x = 0;
int y = 0;
void setup()
{
  pinMode(A2,OUTPUT);
  pinMode(A3,OUTPUT);
  pinMode(A4,OUTPUT);
  pinMode(A5,OUTPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(6,INPUT);
}

void light(int n,int s,int g)
{
  
    analogWrite(n,map(constrain(s,30,511),0,511,0,255));
   
    
    delay(100);
  
}

void loop()
{
 
  x = map(analogRead(A0),0,1023,511,-511);
  y = map(analogRead(A1),0,1023,511,-511);
  if(x>0)
  {
    light(A3,x,g);
     analogWrite(A5,0);
  }
  if(x<0)
  {
    light(A5,-x,g);
    analogWrite(A3,0);
  }
  if(y>0)
  {
    light(A2,y,g);
    analogWrite(A4,0);
  }
  if(y<0)
  {
    light(A4,-y,g);
    analogWrite(A2,0);
  }
}

