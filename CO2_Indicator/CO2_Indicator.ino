#include <Wire.h>
#include <SparkFun_SCD30_Arduino_Library.h>
#include <Adafruit_NeoPixel.h>

#define NEOPIXEL_PIN 6  // Define the NeoPixel connection to digital pin 6
#define NUMPIXELS    8  // Define the number of LEDs on the NeoPixel Stick

// Initialize the NeoPixel strip
Adafruit_NeoPixel pixels(NUMPIXELS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);
SCD30 airSensor; // Create an instance of the SCD30 sensor
int mq135SensorPin = A0; // Define the MQ-135 sensor connection to pin A0

void setup() {
  Wire.begin(); // Initialize the I2C communication
  Serial.begin(9600); // Start serial communication at 9600 baud rate
  pixels.begin(); // Initialize the NeoPixel strip

  // Check if SCD30 sensor is connected properly
  if (!airSensor.begin()) {
    Serial.println("SCD30 not detected, please check the wiring!");
    while (1); // Infinite loop to halt further execution
  }
}

void loop() {
  // Check if new data is available from the air sensor
  if (airSensor.dataAvailable()) {
    int co2 = airSensor.getCO2(); // Get CO2 concentration

    // Print CO2, temperature, and humidity readings to serial
    Serial.print("CO2(ppm): ");
    Serial.print(co2);
    Serial.print(" Temperature(C): ");
    Serial.print(airSensor.getTemperature(), 1);
    Serial.print(" Humidity(%): ");
    Serial.println(airSensor.getHumidity(), 1);

    // Set LED color based on CO2 concentration
    if (co2 >= 3000) {
        blinkRed(); // Blink red continuously if CO2 is 3000ppm or higher
    } else {
        setGreen(); // Keep green if CO2 is lower than 3000ppm
    }
  }

  // Read and print the MQ-135 sensor value
  int mq135SensorValue = analogRead(mq135SensorPin);
  Serial.print("Air Quality : ");
  Serial.println(mq135SensorValue);

  delay(2000); // Delay to manage sensor data reading frequency
}

void blinkRed() {
  // Function to blink all LEDs red
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(255, 0, 0)); // Set LEDs to red
  }
  pixels.show(); // Apply the color setting
  delay(1000); // One-second delay
  pixels.clear(); // Turn off all LEDs
  pixels.show(); // Apply the off setting
  delay(10); // Very short delay before next blink
}

void setGreen() {
  // Function to set all LEDs to green
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 255, 0)); // Set LEDs to green
  }
  pixels.show(); // Apply the color setting
}

