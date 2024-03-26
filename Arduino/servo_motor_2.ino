#include <LiquidCrystal.h>
#include <Servo.h>

const int rs=13,en=12,d4=11,d5=10,d6=9,d7=8;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
int pot=A7;
int ro1;
// name the servo, here Servo is class/
Servo servo1;

void setup() {
  // put your setup code here, to run once:

  /*  WRONG sequence servo write will not happen
  lcd.begin(16,2);
  pinMode(pot,INPUT);
  servo1.attach(5);
  below is correct sequence*/
  servo1.attach(5);
  lcd.begin(16,2);
  pinMode(pot,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  ro1=analogRead(pot);
  ro1=map(ro1,0,1023,0,180);
  lcd.clear();
  lcd.print("Servo Angle:");
  lcd.print(ro1);
   delay(1500);
  servo1.write(ro1);
  delay(10);
}
