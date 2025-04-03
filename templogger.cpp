#include <SD.h>
#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>

#define CS_PIN 10
#define OWIRE_BUS 2
float temp = 0.0;
unsigned long lastLogTime = 0;  
const unsigned long logInterval = 5000; 

OneWire oneWire(OWIRE_BUS);
DallasTemperature sensor(&oneWire);
LiquidCrystal_I2C lcd(0x27,16,2);

void datalogger(float temp){
  File thisOne = SD.open("temp.txt", FILE_WRITE);

  if(thisOne){
    thisOne.print("temp: ");
    thisOne.print(temp);
    thisOne.println(" C");
    thisOne.close();
    Serial.println(String(temp) +" C" + " logged");
  }else {
    Serial.println("File unable to be created");
  }

}




void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  if(!SD.begin(CS_PIN)){
    Serial.println("Sd error");
  }else{
    Serial.println("sd initialized sucessfully");
  }

  sensor.begin(); 
  lcd.init(); 
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("Temp : ");

}

void loop() {
  // put your main code here, to run repeatedly:
  sensor.requestTemperatures();
  temp = sensor.getTempCByIndex(0);
  lcd.setCursor(8,0);
  lcd.print("     "); 
  lcd.setCursor(8,0);
  lcd.print(temp );
  lcd.print(" C");
  delay(250);

  if (millis() - lastLogTime >= logInterval) {
    lastLogTime = millis();  // Update last log time
    datalogger(temp); 
  }
  

}
