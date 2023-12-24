# 💡 AirBeacon

## Project Introduction

AirBeacon is an indoor environment monitoring system designed to continuously monitor and display a range of indoor air quality indicators. This project utilizes an Arduino UNO as the core controller, combined with SCD-30 and MQ-135 sensors to measure levels of carbon dioxide, temperature, humidity, and harmful gases. The data is displayed in real-time on an OLED screen, and the system is equipped with LED lights and a buzzer for warning purposes.
<br><br>
![29241702321291_ pic](https://github.com/grandy0831/MDB-AIRBEACON/assets/140076679/4080e441-114b-477d-bd2d-7c34c602b419)
<br>

## Features

- **Environmental Monitoring**: Real-time monitoring of indoor air for carbon dioxide, temperature, humidity, and harmful gases.
- **Data Display**: Intuitive presentation of environmental data on an OLED display.
- **Warning System**: Alerts through LED lights and a buzzer when environmental indicators exceed safe thresholds.

## Hardware Requirements

### Hardware Assembly:

1. **Component Preparation**:
   - <b>SCD-30 Sensor</b>: Used for measuring carbon dioxide, temperature, and humidity.
   - <b>MQ-135 Sensor</b>: Used for monitoring harmful gases in the air.
   - <b>Arduino UNO</b>: Serves as the main controller.
   - <b>OLED Display</b>: Used for displaying environmental data.
   - <b>LED Lights and Buzzer</b>: Used for the warning system.
     
2. **Circuit Connection**:
   - Connect the SCD-30 and MQ-135 sensors to the appropriate pins of the Arduino UNO. 
   - Connect the OLED display to the Arduino, ensuring the communication interface (I2C) matches.
   - Connect the LED lights and buzzer to the Arduino, setting the appropriate output pins.
   <br><br>
  ![Circuit Connection](https://github.com/grandy0831/MDB-AIRBEACON/assets/140076679/b471bb69-bd35-496a-a039-8694aa28ec27)
<br><br>

3. **Enclosure and Installation**:<br><br>
   - Design a suitable enclosure to house all electronic components while ensuring ventilation and sensor exposure.<br>
     (Enclosure model downloads are [available here](https://github.com/grandy0831/MDB-AIRBEACON/tree/main/Enclosure%20model).)
   - Ensure all wires and components are neatly installed to prevent circuit shorts or damage.
     <br><br>
     ![29221702321287_ pic](https://github.com/grandy0831/MDB-AIRBEACON/assets/140076679/a08184a6-82f4-4422-96d6-ce30b8a37b35)
     <br>
     ![29231702321290_ pic](https://github.com/grandy0831/MDB-AIRBEACON/assets/140076679/7ea0ea1f-82ae-45f0-94ad-8523640efa74)
     <div align="center">（Enclosure design）</div>
     <br>
   - Use soldering to connect circuits and utilize insulating tape to ensure all wires are properly insulated.<br><br>
     ![29201702321282_ pic](https://github.com/grandy0831/MDB-AIRBEACON/assets/140076679/9b92f6d2-17a1-4249-8711-e01570a1efd5)
     ![29211702321284_ pic](https://github.com/grandy0831/MDB-AIRBEACON/assets/140076679/ecd555f1-3b4a-4b56-b146-04fdeeadc9e2)
     <br><br>

## Software Programming and Integration

### Arduino Programming:

This section of the README explains the implementation details for each component in the AirBeacon project, including the CO2 sensor, air quality sensor, LEDs, OLED display, and buzzer.<br>
   - Write code to read data from the SCD-30 and MQ-135 sensors.
   - Set thresholds to trigger the LED lights and buzzer when carbon dioxide levels exceed certain levels.
   - Write code to control the real-time data display on the OLED screen.

#### 1. CO2 Sensor (SCD-30):
   - **Functionality**: Measures CO2, temperature, and humidity using the `SparkFun_SCD30_Arduino_Library`.
   - **Code Snippet**:
     ```cpp
     if (airSensor.dataAvailable()) {
       int co2 = airSensor.getCO2();
       float temperature = airSensor.getTemperature();
       float humidity = airSensor.getHumidity();
     }
   A complete working example of the code is [available here on GitHub](https://github.com/grandy0831/MDB-AIRBEACON/tree/main/CO2_SENSOR).
   - **Circuit Connection**: The SCD-30 sensor is connected to the Arduino's I2C ports (A4 for SDA, A5 for SCL).
   - **Illustration**:
    <br><br>
    ![SCD--30_bb](https://github.com/grandy0831/MDB-AIRBEACON/assets/140076679/73e6a49f-d5f8-4320-b96a-a2a0ac6b0cc2)
    ![CO2 sensor](https://github.com/grandy0831/MDB-AIRBEACON/assets/140076679/6a3a122f-6bc7-4bfe-8e6f-0fef0d9ecde9)
    ![CO2 sensor](https://github.com/grandy0831/MDB-AIRBEACON/assets/140076679/e3a1ff7e-e53a-47a0-bff0-1d29903495fc)

#### 2. Air Quality Sensor (MQ-135):
   - **Functionality**: Reads air quality indices using the `MQ135.h library`.
   - **Code Snippet**:
     ```cpp
     int sensorValue = analogRead(MQ135_SENSOR_PIN);
     float ppm = gasSensor.getPPM();
   A complete working example of the code is [available here on GitHub](https://github.com/grandy0831/MDB-AIRBEACON/tree/main/Air_quality_sensor).
   - **Circuit Connection**: The MQ-135 sensor's analog output is connected to the Arduino's A0 pin.
   - **Illustration**:
  <br><br>
  ![Air quality sensor_bb](https://github.com/grandy0831/MDB-AIRBEACON/assets/140076679/915f76db-d69e-4b8f-9dd2-883ba06b5fbc)
  ![Air quality sensor](https://github.com/grandy0831/MDB-AIRBEACON/assets/140076679/defef883-4890-49e0-9b42-f728dae3a0e4)
  ![Air quality sensor](https://github.com/grandy0831/MDB-AIRBEACON/assets/140076679/4829956c-aa59-4f30-810c-9a67e385e632)

#### 3. LEDs (NeoPixel):
   - **Functionality**: Controls NeoPixel LEDs to display air quality status using the `Adafruit_NeoPixel` library.
   - **Code Snippet**:
     ```cpp
     if (co2 >= 1000 || sensorValue > 100) {
          blinkRed();
      } else {
          setGreen();
      }
     
     void blinkRed() {
        for (int i = 0; i < NUMPIXELS; i++) {
          pixels.setPixelColor(i, pixels.Color(255, 0, 0)); // Set LEDs to red
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
   A complete working example of the code is [available here on GitHub](https://github.com/grandy0831/MDB-AIRBEACON/tree/main/CO2_Indicator).
   - **Circuit Connection**: NeoPixel data line is connected to the Arduino's digital pin 6.
   - **Illustration**:
  <br><br>
  ![LEDS_bb](https://github.com/grandy0831/MDB-AIRBEACON/assets/140076679/40e062c5-083e-4397-81ed-4581e75720f9)
  ![CO2 Indicator green](https://github.com/grandy0831/MDB-AIRBEACON/assets/140076679/d70f1fa3-394a-4bee-8aa9-a28dc941f69a)
  ![CO2 Indicator red](https://github.com/grandy0831/MDB-AIRBEACON/assets/140076679/2e9138fc-b66a-42cb-9a37-bb06c5875230)
  ![CO2 Indicator](https://github.com/grandy0831/MDB-AIRBEACON/assets/140076679/7006d507-12da-4ed3-a46e-3b7746c4adc3)

#### 4. OLED Display:
   - **Functionality**: Displays environmental data using the `Adafruit_GFX` and `Adafruit_SSD1306` libraries.
   - **Code Snippet**:
     ```cpp
      display.clearDisplay();
      display.setCursor(0,0);
      display.print("CO2: ");
      display.print(co2);
   A complete working example of the code is [available here on GitHub](https://github.com/grandy0831/MDB-AIRBEACON/tree/main/SHEM).
   - **Circuit Connection**: OLED display is connected to the Arduino through I2C (A4 for SDA, A5 for SCL).
   - **Illustration**:
  <br><br>
  ![SHEM](https://github.com/grandy0831/MDB-AIRBEACON/assets/140076679/9e701bef-3987-4b46-9756-f968b418ab77)
 
#### 5. Buzzer:
   - **Functionality**: Emits an audible alert when CO2 or air quality exceeds thresholds.
   - **Code Snippet**:
     ```cpp
     if (co2 >= 1000 || sensorValue > 100) {
        tone(buzzerPin, 3000);
     } else {
           noTone(buzzerPin);
     }
   A complete working example of the code is [available here on GitHub](https://github.com/grandy0831/MDB-AIRBEACON/tree/main/SHEM_buzzer_20231129002212).
   - **Circuit Connection**: The buzzer is connected to the Arduino's digital pin 8.
   - **Illustration**:
  <br><br>
 ![Circuit Connection](https://github.com/grandy0831/MDB-AIRBEACON/assets/140076679/824c53e0-642c-4098-b058-3b8852e438f0)
 ![29251702321293_ pic](https://github.com/grandy0831/MDB-AIRBEACON/assets/140076679/0314b76f-02be-4f6e-a5d3-12df158bf167)

### Thresholds and Indicators

   - **The code sets a threshold for CO2 levels (1000 ppm) and air quality (sensor value > 100).**
   - **When thresholds are exceeded, the NeoPixels blink red, and the buzzer is activated.**
   - **Under normal conditions, the NeoPixels are set to green, and the buzzer remains off.**
  <br><br>
![截屏2023-12-24 03 17 53](https://github.com/grandy0831/MDB-AIRBEACON/assets/140076679/9a13f921-cfec-4b9e-829a-89a1bf0ad700)<br>
[Indoor Carbon Dioxide Levels and Your Health](https://www.indoordoctor.com/blog/indoor-carbon-dioxide-levels-health/#:~:text=Carbon%20Dioxide%20Levels%20and%20Your,and%20stagnant%2C%20stale%2C%20stuffy%20air).
