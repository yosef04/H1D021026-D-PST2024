#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int SDA_pin = D3;
int SCL_pin = D2;

void setup()
{
  Wire.begin(SDA_pin, SCL_pin);
  lcd.init();
  lcd.backlight();
}

void loop()
{
  lcd.setCursor(0, 0);
  lcd.print(" Prak PST 2024");
  lcd.setCursor(0, 1);
  lcd.print("Informatika Jaya");
  delay(5000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Informatika Jaya");
  lcd.setCursor(0, 1);
  lcd.print("Jaya Jaya Jaya");
  delay(5000);
  lcd.clear();
}