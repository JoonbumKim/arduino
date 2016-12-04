#include <LiquidCrystal.h>


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);

  lcd.print("HELLOWORLD");
}

void loop() {
  // put your main code here, to run repeatedly:
  // set the cursor to column 0, line 1
  // 임의의 위치에 표시
  lcd.setCursor(0, 1);

  // print the number of seconds since reset
  lcd.print(millis()/1000);
}
