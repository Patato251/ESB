#include <Arduino.h>
// #include "SoftwareSerial.h"
#include "RGB.hpp"
#include "Lux_Sensor.hpp"

void setup() {
  while (!Serial) { delay(10); }
  
  Serial.begin(115200);
  luxSetup();
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
  }
  // Vacant Spot
  else {
    rgbGreenSet();
  }
}
