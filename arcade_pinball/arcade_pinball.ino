/*Daniel Satur - 11 June 2018*/

#include <LiquidCrystal.h>
#include <Servo.h>

const int RS = 12, E = 11, D4 = 5, D5 = 4, D6 = 3, D7 = 2; //LCD pins
LiquidCrystal lcd(RS, E, D4, D5, D6, D7);

void setup(){
  lcd.begin(16, 2);
  lcd.print("Hello world!");
}

void loop(){
  lcd.setCursor(0, 1);
  lcd.print("Is this working?");
}
