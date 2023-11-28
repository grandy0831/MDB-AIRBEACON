#include <Wire.h>
#include <SparkFun_SCD30_Arduino_Library.h>
#include <Adafruit_NeoPixel.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define NEOPIXEL_PIN 6
#define NUMPIXELS    8
#define OLED_RESET   -1 // 如果你的 OLED 显示屏有 RST 引脚，请连接到 Arduino 的一个引脚并在此处指定
Adafruit_NeoPixel pixels(NUMPIXELS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_SSD1306 display(128, 64, &Wire, OLED_RESET);

SCD30 airSensor;
int mq135SensorPin = A0;

void setup() {
  Wire.begin();
  Serial.begin(9600);
  pixels.begin();

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // 初始化 OLED 显示屏
  display.clearDisplay();
  display.setTextSize(2); // 设置字体大小
  display.setTextColor(WHITE);

  if (!airSensor.begin()) {
    Serial.println("SCD30 not detected, please check the wiring!");
    display.println("SCD30 not detected!");
    display.display();
    while (1);
  }
}

void loop() {
  if (airSensor.dataAvailable()) {
    int co2 = airSensor.getCO2();
    float temperature = airSensor.getTemperature();
    float humidity = airSensor.getHumidity();
    int mq135SensorValue = analogRead(mq135SensorPin);
    String airQualityStatus = mq135SensorValue > 200 ? "BAD" : "GOOD";


    display.clearDisplay();
    display.setCursor(0,0);
    display.print("TEMP: ");
    display.print(temperature, 1);
    display.print("HUM:  ");
    display.print(humidity, 1);
    display.print("CO2:  ");
    display.print(co2);
    display.print("AirQ: ");
    display.println(airQualityStatus);
    display.display();

    Serial.print("CO2(ppm): ");
    Serial.print(co2);
    Serial.print(" Temperature(C): ");
    Serial.print(temperature, 1);
    Serial.print(" Humidity(%): ");
    Serial.println(humidity, 1);
    Serial.print("Air Quality : ");
    Serial.println(mq135SensorValue);

    if (co2 >= 3000) {
        blinkRed();
    } else {
        setGreen();
    }
  }
  delay(2000);
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
