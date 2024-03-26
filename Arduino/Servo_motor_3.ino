/*Use one servo motor and 4 switches use.
when 1st SW is equal to zero then 60 degrees angle to be set. 
2nd button is equal to one then 100 degree angle to be set. 
3rd button is equal to 0 then 180 degree angle to be set 
4th button is equal to one then servo motor should be swap between 0 to 180 degree*  */

#include <Servo.h>
#include <LiquidCrystal.h>

const int rs=13,en=12,d4=11,d5=10,d6=9,d7=8;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
int b1=3,b2=4,b3=5,b4=6;
int ro1,ro2,ro3,ro4;

Servo servo1;

void setup() {
  // put your setup code here, to run once:
  servo1.attach(7);
  lcd.begin(16,2);
  pinMode(b1,INPUT);
  pinMode(b2,INPUT);
  pinMode(b3,INPUT);
  pinMode(b4,INPUT);
  
  lcd.setCursor(6,0);
  lcd.print("SERVO");
  lcd.setCursor(6,1);
  lcd.print("MOTOR");
}

void loop() {
  // put your main code here, to run repeatedly:
  int angle1=60, angle2=100,angle3=180;
ro1=digitalRead(b1);
ro2=digitalRead(b2);
ro3=digitalRead(b3);
ro4=digitalRead(b4);

if(ro1==1 && ro2==0 && ro3==0 && ro4==0){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Button Press:B1");
  lcd.setCursor(0,1);
  lcd.print("Angle Set: 60");

  servo1.write(angle1);
  delay(1500);
}
else if(ro1==0 && ro2==1 && ro3==0 && ro4==0){
    lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Button Press:B2");
  lcd.setCursor(0,1);
  lcd.print("Angle Set:100");
  
  servo1.write(angle2);
  delay(1500);
}
else if(ro1==0 && ro2==0 && ro3==1 && ro4==0){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Button Press:B3");
  lcd.setCursor(0,1);
  lcd.print("Angle Set:180");

  servo1.write(angle3);
  delay(1500);
}

else if(ro1==0 && ro2==0 && ro3==0 && ro4==1){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Button Press:B4");
  lcd.setCursor(0,1);
  lcd.print("Rotate 0 to 180");
  
    for (int i=0;i<=180;i++)
   {
    servo1.write(i);
    delay(10);
   }
  delay(100);
    for (int i=180;i>=0;i--)
    {
    servo1.write(i);
    delay(10);
     }
  delay(1500);
}
}
