#include <WiFiNINA.h>  // Include WiFi library for Arduino.

// Replace with your WiFi credentials.
const char* ssid     = "yourNetworkName"; 
const char* password = "yourNetworkPassword";

void setup() {
  Serial.begin(115200); // Initialize serial communication.
  delay(10);

  // Attempt to connect to WiFi.
  Serial.print("Connecting to ");
  Serial.println(ssid);  
  WiFi.begin(ssid, password); 

  while (WiFi.status() != WL_CONNECTED) { // Wait for connection.
    delay(500);
    Serial.print(".");
  }

  // WiFi connection successful.
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP()); // Display IP address.
}

void loop() {
 
 
 
}
