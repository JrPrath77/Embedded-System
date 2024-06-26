#include <LiquidCrystal.h>

// include servo library
#include <Servo.h>
// name the servo, here Servo is class/
Servo myservo;
int initial = 0;
int pot = A15;

const int rs=8,en=9,d4=10,d5=11,d6=12,d7=13;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

void setup() {
  // put your setup code here, to run once:
  myservo.attach(1);
  lcd.begin(16,2);
  pinMode(pot,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  int movement = analogRead(pot);
  movement = map(movement,0,1024,0,180);

  lcd.clear();
  lcd.print("Servo Angle:");
  lcd.print(movement);
  delay(1500);
  myservo.write(movement);
  delay(10);
  
}
/* error
#include <Servo.h>
#include <LiquidCrystal.h>

const int rs=13,en=12,d4=11,d5=10,d6=9,d7=8;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
Servo myServo;
int pot=A7;


void setup() {
  // put your setup code here, to run once:
  pinMode(pot,INPUT);
  lcd.begin(16,2);
   myServo.attach(5);

}

void loop() {
  // put your main code here, to run repeatedly:
  int ro;
  ro=analogRead(pot);
  ro=map(ro,0,1023,0,180);
lcd.clear();
lcd.print("Servo Angle:");
lcd.print(ro);
delay(100);
myServo.write(ro);
delay(10);
}
*/
