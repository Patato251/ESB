#include <Arduino.h>
#include "SoftwareSerial.h"
#include "RGB.hpp"
#include "LuxSensor.hpp"
#include "GPS.hpp"
#include "espwifi.hpp"

#define DEFAULT_BAUD 9600

/****************************************************************/
// Create luxValue variable to compare data readings
float luxValue;

// Initialise GPS Software for location transmission
// SoftwareSerial gpsSerial(gpsRx, gpsTx);
TinyGPSPlus gpsData;

// Initiliase ESP Device for mqtt usage
IPAddress serverIp(161, 35, 2, 212);
WiFiClient espClient;
PubSubClient client(espClient);
SoftwareSerial espDevice(2,3); // RX, TX
 
const char ssid[] = "OPTUS_385454"; // your network SSID (name)
const char pass[] = "gemmymiffy66521"; // your network password
int status = WL_IDLE_STATUS; // the Wifi radio's status

const char condition[] = "Occupied";

/****************************************************************/
void setup() {
  while (!Serial) { 
    delay(10); 
  }
  
  // Begin monitor for each serial
  Serial.begin(DEFAULT_BAUD);
  espDevice.begin(DEFAULT_BAUD);
  // gpsSerial.begin(DEFAULT_BAUD);

  // Call remaing setup functions
  luxSetup();
  rgbSetup();

  WiFi.init(&espDevice);
  // Connect to WPA/WPA2 network
  status = WiFi.begin(ssid, pass);
  // Attempt to connect to WiFi network
  while ( status != WL_CONNECTED) {
    Serial.println("Attempting to connect");

  }
  Serial.println("Successfully Connected to Wifi");

  //connect to MQTT server and setup callback function for use in receiving and sending messages
  client.setServer(serverIp, 1883);
  client.setCallback(callback);

  // Print Successful Initialisation
  Serial.println("Initialisaiton Successful");
}


/**************************************************************/
void callback(char* topic, byte* payload, unsigned int length){
  
  byte* copy = (byte*)malloc(length);

  // Print in terminal when receiving from a certain topic/the subscribed topic
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  
  memcpy(copy,payload,length);

  // Print payload into terminal
  Serial.println();
  for (int i=0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  Serial.println("Messaged relayed to patpub");

  client.publish("patout", copy, length);

  // Free memory allocation of temp buffer for transitional period
  free(copy);
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    
    Serial.println("Attempting MQTT connection...");
    
    // Attempt to connect, just a name to identify the client
    if (client.connect("ArduinoClient")) {
      Serial.println("connected");
      
      // Once connected, publish an announcement...
      client.publish("patout","Arduino has successfully connected");
      
      // ... and resubscribe
      client.subscribe("patin");
    } 
  }
}

/**************************************************************/
void loop () {
  // If device is disconnected
  if (!client.connected()) {
    reconnect();
  }

  // Read the required value from the Lux Sensor
  luxValue = luxRead();

  /* Determine the state in which the spot is currently */
  // Occupied Spot 
  if (luxValue < THRESHOLD) {
    rgbRedSet();
    client.publish("patout", condition);
  }

  // Vacant Spot
  else {
    rgbGreenSet();
  }

  client.loop();
}