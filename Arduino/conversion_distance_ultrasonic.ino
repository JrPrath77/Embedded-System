#include <LiquidCrystal.h>

const int rs=13,en=12,d4=11,d5=10,d6=9,d7=8;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
//pin numbers
const int trigPin=6;
const int echoPin=7;

//variables
long duration;
long distance;
float inch;
float foot;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  lcd.begin(16,2);
}

void loop() {
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
  inch=distance* 0.3937;
  foot=distance*0.0328;

lcd.clear();
lcd.print("CM\tINCH\tFOOT");
lcd.setCursor(0,1);
lcd.print(distance);
lcd.print("\t");
lcd.print(inch);
lcd.print("\t");
lcd.print(foot);
delay(1500);

}
