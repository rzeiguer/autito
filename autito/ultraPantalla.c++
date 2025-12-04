#include <Wire.h>
#include <LCD_I2C.h>

const int Trigger = 3;
const int Echo = 4;

LCD_I2C lcd(0x27, 16, 2);  // probá 0x27 y 0x3F

void setup() {
  lcd.begin();
  lcd.backlight();
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);
  digitalWrite(Trigger, LOW);
}

void loop() {
  long t;
  long d;

  // Envío de pulso
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);

  // Lectura
  t = pulseIn(Echo, HIGH);
  d = t / 59;
  lcd.print(d);

  delay(500); // pequeño delay para estabilidad
  lcd.clear();
}