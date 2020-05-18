#include <Arduino.h>
#include "Adafruit_VEML7700.h"
#include "RGB.hpp"
#include "Lux_Sensor.hpp"
#include "GPS.hpp"
#include <SoftwareSerial.h>

void setup() {
  while (!Serial) { delay(10); }
  Serial.begin(115200);
  // gpsSetup();
  // luxSetup();
  rgbSetup();
  Serial.println("Initialisaiton Successful");
}


void loop () {


  // Read the required value from the Lux Sensor
  luxRead();

  /* Determine the state in which the spot is currently */

  // Occupied Spot 
  if (veml.readLux() < THRESHOLD) {
    rgbRedSet();
    gpsLoop();
  }
  // Vacant Spot
  else {
    rgbGreenSet();
  }
}
