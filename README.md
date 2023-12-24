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
<img width="1496" alt="Circuit Connection" src="https://github.com/grandy0831/MDB-AIRBEACON/assets/140076679/b471bb69-bd35-496a-a039-8694aa28ec27">
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
    ![CO2 sensor](https://github.com/grandy0831/MDB-AIRBEACON/assets/140076679/6a3a122f-6bc7-4bfe-8e6f-0fef0d9ecde9)
    ![CO2 sensor](https://github.com/grandy0831/MDB-AIRBEACON/assets/140076679/e3a1ff7e-e53a-47a0-bff0-1d29903495fc)


