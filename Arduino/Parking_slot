#include<LiquidCrystal.h>

const int rs=13, en=12, d4=11, d5=10, d6=9, d7=8;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int Entry = 5;
int Exit = 6;
int total_slots = 10;
int available_slots = 10;
int cars_in = 0;
int cars_out = 0;

void setup() {
  pinMode(Entry, INPUT);
  pinMode(Exit, INPUT);

  digitalWrite(Entry, LOW);
  digitalWrite(Exit, LOW);

  lcd.begin(20, 4);

  lcd.print("Welcome to PARKING ");
  lcd.setCursor(9, 1);
  lcd.print("lot");
  lcd.setCursor(0, 2);
  lcd.print("Total PARKING Slots:");
  lcd.setCursor(10, 3);
  lcd.print("10");

  delay(3000);
}

void loop() {
  int ro1 = digitalRead(Entry);
  int ro2 = digitalRead(Exit);

  if (ro1 == 1 && cars_in < total_slots) {
    delay(500);
    cars_in++;
  }

  if (ro2 == 1 && cars_in<= 10 && cars_in>0) {
    delay(500);
    cars_in--;
  }

  available_slots = total_slots - cars_in;

  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("CARS PARKED:");
  lcd.print(cars_in);
  lcd.setCursor(0, 2);
  lcd.print("Available Slots:");
  lcd.print(available_slots);
  delay(1500);

  if (available_slots <= 0) {
    lcd.setCursor(0, 3);
    lcd.print("No slot available");
    delay(1000);
  }
}
