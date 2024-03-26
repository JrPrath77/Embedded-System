#include<LiquidCrystal.h>

const int rs=12,en=11,d4=10,d5=9,d6=8,d7=7;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);


/*
Connect one of the outer pins of the potentiometer to the 5V pin on the Arduino.
Connect the other outer pin of the potentiometer to the GND pin on the Arduino.
Connect the middle pin of the potentiometer to an analog input pin on the Arduino, such as A0, A1, A2, etc
*/
int  potentiometer=A1;


void setup() {
  // put your setup code here, to run once:
  pinMode(potentiometer,INPUT);
  lcd.begin(16,2);

}

void loop() {
  // put your main code here, to run repeatedly:
  int ro1;

ro1 = analogRead(potentiometer);  // Read the raw analog input value from the potentiometer
int mappedValue = map(ro1, 0, 1023, 0, 255);  // Map the raw analog input value to a range of 0-255

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("POT VAL:");
  lcd.print(ro1);
  lcd.setCursor(0,1);
  lcd.print("Map VAL:");
  lcd.print(mappedValue);
  delay(1500);
}
