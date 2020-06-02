#include "RGB.hpp"

void rgbSetup() {
  pinMode(RedPin, OUTPUT);
  pinMode(BluePin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
}

void setColour (int redValue, int greenValue, int blueValue) {
  analogWrite (RedPin, redValue);
  analogWrite (GreenPin, greenValue);
  analogWrite (BluePin, blueValue);
}

void rgbTestSet() {
  setColour(255, 0, 0); //Red Value
  Serial.println("Colour Set to Red");
  delay(1000);
  setColour(0, 255, 0); //Green Value
  Serial.println("Colour Set to Green");
  delay(1000);
  setColour(0, 0, 255); //Blue Value
  Serial.println("Colour Set to Blue");
  delay(1000);
}

void rgbRedSet() {
  setColour(255, 0, 0); // Red Value
}

void rgbGreenSet() {
  setColour(0, 255, 0); // Green Value
}

void rgbBlueSet() {
  setColour(0, 0, 255); // Blue Value
}