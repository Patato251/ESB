#include <Arduino.h>
#include <SoftwareSerial.h>

// Setup Software Serial for ESP8266

SoftwareSerial ESPSoftwareSerial(2, 3); // Rx and Tx pins

void setup() {
  Serial.begin(115200);
  ESPSoftwareSerial.begin(115200);
  Serial.println("Setup Initialised");
}

void loop() {
  // Have Arduino listen for Serial communication between the ESP and the PC
  if (ESPSoftwareSerial.available()) {
    Serial.write(ESPSoftwareSerial.read());
  }

  // Have data read via serial monitor to be written to device
  if (Serial.available()) {
    ESPSoftwareSerial.write(Serial.read());
  }
}