#include<Servo.h>
int position = 90;
boolean forward = false;
Servo servo;

const int IRsensor1 = 13;
const int IRsensor2 = 12;
const int Earthquake = 11;
const int Flamesensor = 10;
const int door = 9;

const int Buzzer = 14;
const int temp = 17;
const int ledlight = 18;
const int Fan = 19;

unsigned long off_time1;
unsigned long off_time2;
unsigned long off_time3;

int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
Int tempvalue = 0;

boolean State1 = false;
boolean State2 = false;

void setup ()   {
servo. attach(door) ;
pinMode(Buzzer, OUTPUT) ;
pinMode(Fan, OUTPUT) ;
pinMode(ledlight, OUTPUT) ;

digitalWrite(Buzzer, LOW) ;
digitalWrite(Fan, LOW) ;
digitalWrite(ledlight, LOW) ;

pinMode(IRsensor1, INPUT) ;
pinMode(IRsensor2, INPUT) ;
pinMode(Flamesensor, INPUT) ;
pinMode(Earthquake, INPUT) ;
pinMode (temp, INPUT) ;
}

void loop()  {

buttonState1 = digitalRead(IRsensor1);
buttonState2 = digitalRead(IRsensor2);
buttonState4 = digitalRead(Flamesensor);
buttonState3 = digitalRead(Earthquake);
tempvalue = analogRead(temp);


if (!State1)
{
if (buttonState4 == HIGH | | buttonState3 == HIGH) 
{
digitalwrite(Buzzer,HIGH);
State1 = true; 
off_time1 = millis() + 3000;
}
}
else if ((State1) && (millis() >= off_time1))
{
digitalwrite (Buzzer, LOW);
State1 = false; 
}

if (! State2)
{
if (buttonState2 == HIGH) 
{
digitalwrite(Fan, HIGH);
digitalwrite(ledlight, HIGH); 
State2 = true; 
off_time2 = millis() + 5000;
}
}
else if ((State2) && (millis() >= off_time2))
{
digitalwrite (Fan, LOW);
digitalwrite(ledlight,LOW);
State2 = false; 
}

if (!forward)
{
if (buttonState1 == HIGH | |  buttonState4 == HIGH | |  buttonState3 == HIGH) 
{
servo.write(-- position); 
if (position == 0)
forward = true; 
off_time3 = millis()  + 5000;
}
}
else if (( forward) && (millis() >= off_time3))
{
servo. write (++ position);
if (position == 90)
forward = false; 
}
}