#include <LiquidCrystal.h>

const int rs=12,en=11,d4=10,d5=9,d6=8,d7=7;

LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

//Buttons
int b1=2;//bottom
int b2=3;//mid
int b3=4;//top

void setup() {
  // put your setup code here, to run once:
pinMode(b1,INPUT);
pinMode(b2,INPUT);
pinMode(b3,INPUT);

  lcd.begin(16,2);
  lcd.print("Tank Water Level");
  lcd.setCursor(0,1);
  lcd.print("Indicator");
  delay(1500);

}

void loop() {
  // put your main code here, to run repeatedly:
  int ro1=digitalRead(b1);
  int ro2=digitalRead(b2);
  int ro3=digitalRead(b3);

  if(ro1==1 && ro2==1 && ro3==1){
    lcd.clear();
    lcd.print("Top level");
    lcd.setCursor(0,1);
    lcd.print("Motor OFF");
    delay(1500);
  }
  else if(ro1==1 && ro2==1 && ro3==0){
    lcd.clear();
    lcd.print("Middle level");
    delay(1500);
  }
  else if(ro1==1 && ro2==0 && ro3==0){
    lcd.clear();
    lcd.print("Bottom level");
    lcd.setCursor(0,1);
    lcd.print("Motor ON");
    delay(1500);  
  }
  else{
  lcd.clear();
  lcd.print("Tank Water Level");
  lcd.setCursor(0,1);
  lcd.print("Indicator");
  delay(1000);
  }

}
