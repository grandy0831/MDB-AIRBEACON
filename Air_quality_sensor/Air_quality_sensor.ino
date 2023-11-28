int sensorPin = A0; // MQ-135 connected to A0 pin

void setup() {
    Serial.begin(9600); // Initialize serial communication
}

void loop() {
    int sensorValue = analogRead(sensorPin); // Read the sensor value
    Serial.print("Air quality: "); // Print message
    Serial.println(sensorValue); // Print the air quality reading

    delay(1000); // Wait for 1 second before the next reading
}
