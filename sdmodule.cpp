//this is the first step to making a dat logger 
#include <SD.h>

#define CS_PIN 10

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  if(!SD.begin(CS_PIN)){
    Serial.println("Sd error");
  }else{
    Serial.println("sd initialized sucessfully");
  }

  File thisOne = SD.open("text.txt", FILE_WRITE);

  if(thisOne){
    thisOne.println("hello, Kim");
    thisOne.close();
    Serial.println("Data written to file.");
  }else {
    Serial.println("File unable to be created");
  }

  thisOne = SD.open("text.txt");
  if (thisOne){
    Serial.println("Reading from file: ");

    while (thisOne.available()) {
      Serial.write(thisOne.read());  // Print contents
    }
    thisOne.close();
  } else {
    Serial.println("Failed to open file for reading.");
  }


}

void loop() {
  // put your main code here, to run repeatedly:

}

