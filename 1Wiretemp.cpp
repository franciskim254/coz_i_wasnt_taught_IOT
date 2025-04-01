//tempsensor sketch using the 1-Wire library and LCD screen(16x2)

#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>

#define OWIRE_BUS 2
// line 9-11 is basically creating an object of the following classes
OneWire oneWire(OWIRE_BUS);
DallasTemperature sensor(&oneWire);
LiquidCrystal_I2C lcd(0x27,16,2);


void setup() {
  // put your setup code here, to run once:
  sensor.begin(); //in the library this is one of the predefined functions
  lcd.init(); // this is specific for the LiquidCrystal_I2C library while serial library uses init()
  lcd.backlight();

  lcd.setCursor(1,0);
  lcd.print("Temp : ");


}

void loop() {
  // put your main code here, to run repeatedly:
  sensor.requestTemperatures();
  float temp = sensor.getTempFByIndex(0);
  lcd.setCursor(8,0);
  lcd.print(temp);
  delay(500);

}

