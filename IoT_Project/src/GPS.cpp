/*! @file
 *
 *  @brief 
 * 
 * 
 *  
 *  @author Patrick Le
 *  @date 13-05-2020
 */

#include <Arduino.h>
#include "GPS.hpp"

int8_t RxPin = 6;
int8_t TxPin = 7;

SoftwareSerial gpsSerial(RxPin, TxPin);

void gpsSetup() {
  gpsSerial.begin(GPSBAUD);
}

void gpsLoop() {
  while (gpsSerial.available() > 0) {
    Serial.write(gpsSerial.read());
  }
}