/*
#include "espwifi.hpp"

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

  // client.publish("patout", copy, length);
  // client.publish("patout", "Subscribe Sucessful");

  // Free memory allocation of temp buffer for transitional period
  free(copy);
}

void reconnect(PubSubClient client) {
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
}*/