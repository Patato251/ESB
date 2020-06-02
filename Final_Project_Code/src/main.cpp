#include <Arduino.h>
#include "SoftwareSerial.h"
#include "RGB.hpp"
#include "LuxSensor.hpp"

float luxValue;

void setup() {
  while (!Serial) { delay(10); }
  
  Serial.begin(9600);
  luxSetup();
  rgbSetup();
  Serial.println("Initialisaiton Successful");
}


void loop () {
  // Read the required value from the Lux Sensor
  luxValue = luxRead();

  /* Determine the state in which the spot is currently */
  // Occupied Spot 
  if (luxValue < THRESHOLD) {
    rgbRedSet();
  }
  // Vacant Spot
  else {
    rgbGreenSet();
  }
}
