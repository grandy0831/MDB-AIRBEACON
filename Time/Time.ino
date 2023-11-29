#include <WiFiNINA.h>  // Include WiFi library for Arduino.
#include <ezTime.h>  //ezTime library

// Replace with your WiFi credentials.
const char* ssid     = "yourNetworkName"; 
const char* password = "yourNetworkPassword";

Timezone GB;  //Initializes a time zone object GB

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

  waitForSync();  //Synchronize time from the Internet

  Serial.println("UTC: " + UTC.dateTime()); //Print the current UTC time

  GB.setLocation("Europe/London");  //Set the time zone of the GB object to the time zone of London
  Serial.println("London time: " + GB.dateTime());  //Get London time and print

}

void loop() {
  delay(1000);  //Delay 1 second
  Serial.println(GB.dateTime("l, d-M-y H:i:s.v T")); // Print the current time to the serial monitor
}
