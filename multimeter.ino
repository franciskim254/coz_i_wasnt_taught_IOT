
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
float printvoltage(){
  
  return analogRead(A0)*(5.0/1023.0);

}

void setup() {
  // put your setup code here, to run once:
pinMode(A0, INPUT);
lcd.init();
lcd.backlight();

lcd.setCursor(2,0);
lcd.print("Voltage : ");
lcd.setCursor(1,1);



}

void loop() {
  lcd.print("  ");
  lcd.setCursor(1,1);
  lcd.print(printvoltage(),2);
  delay(700);
 
}

