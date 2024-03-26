#include<LiquidCrystal.h>

const int rs=12,en=11,d4=5,d5=4,d6=3,d7=2;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);



void setup() {
  // put your setup code here, to run once:
  
  lcd.begin(16,2);

  lcd.print("Welcome E-yantra");
  delay(1500);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("College Name: -");
  lcd.setCursor(5,1);
  lcd.print("ADCET");
  delay(1500);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Student Name:-");
  lcd.setCursor(0,1);
  lcd.print("Prathmesh");
  delay(1500);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Class: -SY");
  delay(1500);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Department:- CSE");
  delay(1500);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Welcome");
  lcd.setCursor(0,1);
  lcd.print("E-yantra Lab");
  delay(1500);
}



