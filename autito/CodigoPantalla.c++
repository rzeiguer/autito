#include "/Users/ronizeiguer/Documents/LiquidCrystal_I2C-1.1.2/LiquidCrystal_I2C.h"
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int Trigger = 3;
const int Echo = 4;

void setup() {
  
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);

  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);
  digitalWrite(Trigger, LOW);

}

void loop() {
long t;
long d;

digitalWrite(Trigger, HIGH);
delayMicroseconds(10);
digitalWrite(Trigger, LOW);

t=pulseIn(Echo, HIGH);
d=t/59;

lcd.print(t);

}