#include <Wire.h>  // Include Wire library for I2C communication
#include <SparkFun_SCD30_Arduino_Library.h>  // Include library for SCD30 CO2 sensor
#include <Adafruit_NeoPixel.h>  // Include library for controlling NeoPixels
#include <Adafruit_GFX.h>  // Include Adafruit Graphics library for graphical functions
#include <Adafruit_SSD1306.h>  // Include library for OLED display
#include <MQ135.h>

#define NEOPIXEL_PIN 6  // Define the pin for NeoPixels
#define NUMPIXELS    8  // Number of pixels in the NeoPixel strip
#define OLED_RESET   -1 // OLED reset pin (set to -1 if not used)

Adafruit_NeoPixel pixels(NUMPIXELS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800); // Initialize NeoPixel strip
Adafruit_SSD1306 display(128, 64, &Wire, OLED_RESET); // Initialize OLED display

SCD30 airSensor; // Create an instance of the SCD30 sensor
const int MQ135_SENSOR_PIN = A0; // Connect the analog output pin of MQ-135 to Arduino's A0 pin
MQ135 gasSensor = MQ135(MQ135_SENSOR_PIN);
int buzzerPin = 8; // Pin for the buzzer

void setup() {
  Wire.begin();  // Start the I2C communication
  Serial.begin(9600);  // Begin serial communication at 9600 baud rate
  pixels.begin();  // Initialize NeoPixel strip
  pinMode(buzzerPin, OUTPUT); // Set buzzer pin as an output
  pixels.setBrightness(20);

  // Initialize OLED display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); 
  display.clearDisplay();
  display.setTextSize(2);  // Set text size for the OLED display
  display.setTextColor(WHITE);

  // Check if SCD30 sensor is connected
  if (!airSensor.begin()) {
    Serial.println("SCD30 not detected, please check the wiring!");
    display.println("SCD30 not detected!");
    display.display();
    while (1); // Stop execution if the sensor is not detected
  }
}

void loop() {
  // Check if there's data available from the SCD30 sensor
  if (airSensor.dataAvailable()) {
    int co2 = airSensor.getCO2(); // Get CO2 reading
    float temperature = airSensor.getTemperature(); // Get temperature reading
    float humidity = airSensor.getHumidity(); // Get humidity reading
    int sensorValue = analogRead(MQ135_SENSOR_PIN);
    float ppm = gasSensor.getPPM(); 
    String airQualityStatus = sensorValue > 100 ? "BAD" : "GOOD"; // Determine air quality

    // Update OLED display with sensor readings
    display.clearDisplay();
    display.setCursor(0,0);
    display.print("TEMP: ");
    display.print(temperature, 1);
    display.setCursor(0, 16);
    display.print("HUM:  ");
    display.print(humidity, 1);
    display.setCursor(0, 32);
    display.print("CO2:  ");
    display.print(co2);
    display.setCursor(0, 48);
    display.print("AirQ: ");
    display.println(airQualityStatus);
    display.display();

    // Print readings to serial monitor
    Serial.print("CO2(ppm): ");
    Serial.print(co2);
    Serial.print(" Temperature(C): ");
    Serial.print(temperature, 1);
    Serial.print(" Humidity(%): ");
    Serial.println(humidity, 1);
    Serial.print("Air Quality : ");
    Serial.println(sensorValue);

    // Change NeoPixel color and activate buzzer based on CO2 level or Air Quality
    if (co2 >= 1000 || sensorValue > 100) {
        blinkRed(); // Activate red LEDs
        tone(buzzerPin, 3000); // Activate buzzer
        delay(500);            // Continue for 500 milliseconds
        clearPixels();         // Clear LEDs
        noTone(buzzerPin);     // Deactivate buzzer
    } else {
        setGreen(); // Set LEDs to green
        noTone(buzzerPin); // Ensure the buzzer is off
    }
  }
  delay(2000); // Delay between readings
}

// Function to blink NeoPixels red
void blinkRed() {
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(255, 0, 0));
  }
  pixels.show();
}

// Function to clear NeoPixels
void clearPixels() {
  pixels.clear();
  pixels.show();
}

// Function to set NeoPixels to green
void setGreen() {
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 255, 0));
  }
  pixels.show();
}
