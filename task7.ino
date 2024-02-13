int led1=5;
int led2=4;
int led3=3;
int led4=2;
int trig=6;
int echo=7;
long t=0;
int d=0;
void setup()
{
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);
}
void loop()
{
   digitalWrite(trig,0);
   delayMicroseconds(2);
   digitalWrite(trig,1);
   delayMicroseconds(10);
   digitalWrite(trig,0);
   t=pulseIn(echo,1);
   d=(.0343/2)*t;
   Serial.println(d);
  
  if(d<=100)
  {
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
  }
  else if(d<=200)
  {
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
  }
  else if(d<=300)
  {
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,LOW);
  }
  else if(d>300)
  {
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,HIGH);
  }
}