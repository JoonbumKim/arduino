// http://deneb21.tistory.com/208

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3f, 16, 2);
void setup() {
  // put your setup code here, to run once:
  lcd.init();

  lcd.backlight();
  lcd.print("Hello World");
}

void loop() {
  // put your main code here, to run repeatedly:

}
