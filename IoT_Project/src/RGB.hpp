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

#define RedPin 10
#define BluePin 9
#define GreenPin 11

void rgbSetup();

void setColour (int redValue, int greenValue, int blueValue);

void rgbTestSet();

void rgbRedSet();

void rgbGreenSet();

void rgbBlueSet();