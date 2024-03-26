#include <Servo.h>
#include <LiquidCrystal.h>

Servo servo1;
Servo servo2;
const int rs=13,en=12,d4=11,d5=10,d6=9,d7=8;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
//pin numbers
const int trigPin=6;
const int echoPin=7;

//variables
long duration;
long distance;
long inch;
long foot;

int s1=2,s2=3,s3=4,s4=5;

void setup() {
  // put your setup code here, to run once:
  servo1.attach(A5);
  servo2.attach(A6);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  lcd.begin(16,2);
  //DC motor
  pinMode(s1,OUTPUT);
  pinMode(s2,OUTPUT);
  pinMode(s3,OUTPUT);
  pinMode(s4,OUTPUT);
}

void forward()
{
// motor 1
digitalWrite (s1,1);
digitalWrite (s2,0);
// motor 1
digitalWrite (s3,1);
digitalWrite (s4,0);
}

void stop()
{   // motor 1
digitalWrite (s1,0);
digitalWrite (s2,0);
  // motor 2
digitalWrite (s3,0);
digitalWrite (s4,0);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;

  if(distance>50){
    lcd.clear();
    lcd.print(distance);
    forward();
  }
  else{
    stop();
    lcd.clear();
    lcd.print(distance);
    lcd.setCursor(0,1);
    lcd.print("STOP");
    lcd.clear();
    lcd.print("Removing");
    lcd.setCursor(0,1);
    lcd.print("Obstacle");
    // servo one bring down 
    for (int i=0;i<=180;i++)
   {
     servo1.write(i);
    delay(10);
   }
   delay(100);
    for (int i=0;i<=180;i++)
   {
     servo2.write(i);
    delay(10);
    }
    for (int i=180;i>=0;i--)
    {
     servo2.write(i);
     delay(10);
   }
     for (int i=180;i>=0;i--)
    {
     servo1.write(i);
     delay(10);
   }
   forward();
  }
  
}
