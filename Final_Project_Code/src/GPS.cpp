/*! @file
 *
 *  @brief I/O routines and function values required for communicating with RGB LED module
 *
 *  This contains the functions for operating the RGB Led Module associated with this unit.
 *
 *  @author Patrick Le
 *  @date 27-04-2020
 */

#include "GPS.hpp"


// Display necessary information in sections split with println and divided according to category 
void displayInfo(TinyGPSPlus gpsData) {
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

  // // Date information
  // Serial.print("Date: ");
  // if (gpsData.date.isValid()) {
  //   Serial.print(gpsData.date.month());
  //   Serial.print("/");
  //   Serial.print(gpsData.date.day());
  //   Serial.print("/");
  //   Serial.println(gpsData.date.year());
  // }
  // else {
  //   Serial.println("Not Available");
  // }

  // // Local Time Information
  // Serial.print("Time: ");
  // if (gpsData.time.isValid()) {
  //   if (gpsData.time.hour() < 10) {
  //     Serial.print(F("0"));
  //   }
  //   Serial.print(gpsData.time.hour());
  //   Serial.print(":");
  //   if (gpsData.time.minute() < 10) {
  //     Serial.print(F("0"));
  //   }
  //   Serial.print(gpsData.time.minute());
  //   Serial.print(":");    
  //   if (gpsData.time.second() < 10) {
  //     Serial.print(F("0"));
  //   }
  //   Serial.print(gpsData.time.second());
  //   Serial.print(".");
  //   if (gpsData.time.centisecond() < 10) {
  //     Serial.print(F("0"));
  //   }    
  //   Serial.println(gpsData.time.centisecond());
  // }
  // else {
  //   Serial.println("Time Not Available");
  // }

  // White Space split between end of relevant data
  Serial.println();
  Serial.println();
  delay(1000);
}