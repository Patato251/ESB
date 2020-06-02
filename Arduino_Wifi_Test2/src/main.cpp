
#include <Arduino.h>
#include "SoftwareSerial.h"
#include <PubSubClient.h>
#include <WiFiEspAT.h>

IPAddress serverIp(161, 35, 2, 212);
char ssid[] = "OPTUS_385454";           // your network SSID (name)
char pass[] = "gemmymiffy66521";           // your network password
int status = WL_IDLE_STATUS;   // the Wifi radio's status

// Initiliase ESP Device for mqtt usage
WiFiClient espClient;

PubSubClient client(espClient);

SoftwareSerial espDevice(2,3); // RX, TX

// Variable Declaration

uint8_t Status = 0;

// Function declarations
void callback(char* topic, byte* payload, unsigned int length);
void reconnect();


void setup() {
  // initialize serial for debugging
  Serial.begin(9600);
  // initialize serial for ESP module
  espDevice.begin(9600);
  // initialize ESP module
  WiFi.init(&espDevice);

  // attempt to connect to WiFi network
  while ( status != WL_CONNECTED) {

    Serial.print("Attempting to connect to WPA SSID: ");
    Serial.println(ssid);
    
    // Connect to WPA/WPA2 network
    status = WiFi.begin(ssid, pass);
  }

  //connect to MQTT server and setup callback function for use in receiving and sending messages
  client.setServer(serverIp, 1883);
  client.setCallback(callback);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (!client.connected()) {
    reconnect();
  }
  
  client.loop();

}

//print any message received for subscribed topic
void callback(char* topic, byte* payload, unsigned int length) {
  
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

  // client.publish("patout", (char*)payload);
  client.publish("patout", copy, length);
  client.publish("patout", "Subscribe Sucessful");

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
    
    else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}




