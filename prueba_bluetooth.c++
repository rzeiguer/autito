#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Cambiá a 0x3F si no aparece texto
#define LCD_ADDR 0x27

LiquidCrystal_I2C lcd(LCD_ADDR, 16, 2);

void setup() {
  Wire.begin();

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("LCD funcionando");

  lcd.setCursor(0, 1);
  lcd.print("Probando...");
}

void loop() {
  static int contador = 0;

  lcd.setCursor(10, 1);
  lcd.print("   ");        // limpia números viejos
  lcd.setCursor(10, 1);
  lcd.print(contador);

  contador++;
  delay(1000);
}
