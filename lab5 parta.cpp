
#include <Arduino.h>
#include <SPI.h>
#include <SD.h>
const int chipSelect = 10;
int position = 0;
File dataFile; 
const int potPin = A0;
int sensorValue = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Program Started");
  Serial.println("Initializing SD Card...");
  if(SD.begin(chipSelect)) {
    Serial.println("SD Card Found");
  } 
  else {
    Serial.println("SD Card Not Found");
  }
  

 dataFile = SD.open("hello.txt", FILE_WRITE);
  dataFile.println("Hello Dawson");
  dataFile.close();

dataFile = SD.open("senor.txt", FILE_WRITE);
 dataFile.println(sensorValue); 
 dataFile.close(); 
// Save:
// Value = sensorValue

// Close file
if (dataFile) 
{
 dataFile.println("Time,Value");
 dataFile.close();
 Serial.println("CSV Header Written");
}
else {
  Serial.println("Failed to createfile");
}
 
delay(500);


}
 
void loop() {
  Serial.println(position);
 sensorValue = analogRead(potPin);

  Serial.print("Value = ");
  Serial.println(sensorValue);

  if (dataFile) 
{
 Serial.println("Time: ");
 Serial.println(timeSeconds);
 Serial.println(" s ");

 Serial.print("Value ");
 Serial.println (sensorValue); 

 dataFile = SD.open("senor.txt", FILE_WRITE);
 
 if (dataFile) 
 {
    dataFile.print(timeSeconds);
    dataFile.print(",");
    dataFile.println(sensorValue); 
 }
 dataFile.close();
 Serial.println("CSV Header Written");
}
else {
  Serial.println("Failed to createfile");
}
  delay(1000);
}
