/*! @file
 *
 *  @brief I/O routines and function values required for communicating with RGB LED module
 *
 *  This contains the functions for operating the RGB Led Module associated with this unit.
 *
 *  @author Patrick Le
 *  @date 27-04-2020
 */

#include <Arduino.h>
#include <SoftwareSerial.h>

#define GPSBAUD 115200

void gpsSetup();

void gpsLoop();

