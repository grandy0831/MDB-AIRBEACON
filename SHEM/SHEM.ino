#include <Wire.h>
#include <SparkFun_SCD30_Arduino_Library.h>
#include <Adafruit_NeoPixel.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define NEOPIXEL_PIN 6
#define NUMPIXELS    8
#define OLED_RESET   -1
Adafruit_NeoPixel pixels(NUMPIXELS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_SSD1306 display(128, 64, &Wire, OLED_RESET);
SCD30 airSensor;
int mq135SensorPin = A0;

void setup() {
  Wire.begin();
  Serial.begin(115200);
  pixels.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); 
  display.clearDisplay();
  display.setTextSize(2);  // Set text size for the OLED display
  display.setTextColor(WHITE);

  if (!airSensor.begin()) {
    Serial.println("SCD30 not detected, please check the wiring!");
    display.println("SCD30 not detected!");
    display.display();
    while (1);
  }
}

void loop() {
  readCO2();
  readAirQuality();
  updateDisplay();
  delay(2000);
}

void readCO2() {
  if (airSensor.dataAvailable()) {
    int co2 = airSensor.getCO2(); // Get CO2 concentration

    Serial.print("CO2(ppm): ");
    Serial.print(co2);
    Serial.print(" Temperature(C): ");
    Serial.print(airSensor.getTemperature(), 1);
    Serial.print(" Humidity(%): ");
    Serial.println(airSensor.getHumidity(), 1);

    if (co2 >= 3000) {
        blinkRed(); // Blink red continuously if CO2 is 3000ppm or higher
    } else {
        setGreen(); // Keep green if CO2 is lower than 3000ppm
    }
  }
}


void readAirQuality() {
  int mq135SensorValue = analogRead(mq135SensorPin);
  Serial.print("Air Quality: ");
  Serial.println(mq135SensorValue);
}

void updateDisplay() {
  if (airSensor.dataAvailable()) {
    float temperature = airSensor.getTemperature();
    float humidity = airSensor.getHumidity();
    int co2 = airSensor.getCO2();
    int mq135SensorValue = analogRead(mq135SensorPin);
    String airQualityStatus = mq135SensorValue > 200 ? "BAD" : "GOOD";

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
  }
}

void blinkRed() {
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(255, 0, 0));
  }
  pixels.show();
  delay(1000);
  pixels.clear();
  pixels.show();
  delay(10);
}

void setGreen() {
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 255, 0));
  }
  pixels.show();
}
