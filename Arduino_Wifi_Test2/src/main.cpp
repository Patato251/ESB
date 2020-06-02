
#include <Arduino.h>
// #include <WiFiEsp.h>
// #include <WiFiEspClient.h>
// #include <WiFiEspUdp.h>
#include "SoftwareSerial.h"
#include <PubSubClient.h>
#include <WiFiEspAT.h>

IPAddress server(161, 35, 2, 212);
char ssid[] = "OPTUS_385454";           // your network SSID (name)
char pass[] = "gemmymiffy66521";           // your network password
int status = WL_IDLE_STATUS;   // the Wifi radio's status

// Initiliase ESP Device for mqtt usage
WiFiClient espClient;

PubSubClient client(espClient);

SoftwareSerial soft(2,3); // RX, TX

// Function declarations
void callback(char* topic, byte* payload, unsigned int length);
void reconnect();


void setup() {
  // initialize serial for debugging
  Serial.begin(9600);
  // initialize serial for ESP module
  soft.begin(9600);
  // initialize ESP module
  WiFi.init(&soft);

  // attempt to connect to WiFi network
  while ( status != WL_CONNECTED) {

    Serial.print("Attempting to connect to WPA SSID: ");
    Serial.println(ssid);
    
    // Connect to WPA/WPA2 network
    status = WiFi.begin(ssid, pass);
  }

  //connect to MQTT server
  client.setServer(server, 1883);
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
  
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  
  for (int i=0; i < length;i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  Serial.println("Messaged relayed to patpub");

  client.publish("patpub", (char*)payload);
  client.publish("patpub", "Subscribe Sucessful")
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    
    Serial.println("Attempting MQTT connection...");
    
    // Attempt to connect, just a name to identify the client
    if (client.connect("ArduinoClient")) {
      Serial.println("connected");
      
      // Once connected, publish an announcement...
      client.publish("patpub","Arduino has successfully connected");
      
      // ... and resubscribe
      client.subscribe("patsub");
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




