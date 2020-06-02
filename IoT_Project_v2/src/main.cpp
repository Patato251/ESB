#include <Arduino.h>
#include <SoftwareSerial.h>
#include <TinyGPS++.h>

// Choose two Arduino pins to use for software serial
int RXPin = 2;
int TXPin = 3;

//Default baud of NEO-6M is 9600
int GPSBaud = 9600;

// Create a software serial port called "gpsSerial"
SoftwareSerial gpsSerial(RXPin, TXPin);

// Creating a TinyGPS Object
TinyGPSPlus gpsData;

void setup()
{
  // Start the Arduino hardware serial port at 9600 baud
  Serial.begin(9600);

  // Start the software serial port at the GPS's default baud
  gpsSerial.begin(GPSBaud);
  Serial.println("GPS Initialised");
}

// Display necessary information in sections split with println and divided according to category 
void displayInfo() {
  // GPS Locational Data
  if (gpsData.location.isValid()) {
    Serial.print("Latitude: ");
    Serial.println(gpsData.location.lat(), 6);
    Serial.print("Longitude: ");
    Serial.println(gpsData.location.lng(), 6);    
    Serial.print("Altitude: ");
    Serial.println(gpsData.altitude.meters());    
  }
  else {
    Serial.println("Location: Not available data");
  }

  // Date information
  Serial.print("Date: ");
  if (gpsData.date.isValid()) {
    Serial.print(gpsData.date.month());
    Serial.print("/");
    Serial.print(gpsData.date.day());
    Serial.print("/");
    Serial.println(gpsData.date.year());
  }
  else {
    Serial.println("Not Available");
  }

  // Local Time Information
  Serial.print("Time: ");
  if (gpsData.time.isValid()) {
    if (gpsData.time.hour() < 10) {
      Serial.print(F("0"));
    }
    Serial.print(gpsData.time.hour());
    Serial.print(":");
    if (gpsData.time.minute() < 10) {
      Serial.print(F("0"));
    }
    Serial.print(gpsData.time.minute());
    Serial.print(":");    
    if (gpsData.time.second() < 10) {
      Serial.print(F("0"));
    }
    Serial.print(gpsData.time.second());
    Serial.print(".");
    if (gpsData.time.centisecond() < 10) {
      Serial.print(F("0"));
    }    
    Serial.println(gpsData.time.centisecond());
  }
  else {
    Serial.println("Time Not Available");
  }

  // White Space split between end of relevant data
  Serial.println();
  Serial.println();
  delay(1000);
}

void loop()
{
  // If 5000 milliseconds pass and there are no characters coming in
  // over the software serial port, show a "No GPS detected" error
  if (millis() > 5000 && gpsData.charsProcessed() < 10)
  {
    Serial.println("No GPS detected");
    while(true);
  }

  // Displays information when new sentence is encoded corretly for information display
  while (gpsSerial.available() > 0) {
    if (gpsData.encode(gpsSerial.read())) {
      displayInfo();
    } 
   }
}