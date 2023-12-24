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

3. **Enclosure and Installation**:
   - Design a suitable enclosure to house all electronic components while ensuring ventilation and sensor exposure.
     Enclosure model downloads are [available here](https://github.com/grandy0831/MDB-AIRBEACON/tree/main/Enclosure%20model).
   - Ensure all wires and components are neatly installed to prevent circuit shorts or damage.
   - Use soldering to connect circuits and utilize insulating tape to ensure all wires are properly insulated.
     <br><br>
     ![29221702321287_ pic](https://github.com/grandy0831/MDB-AIRBEACON/assets/140076679/a08184a6-82f4-4422-96d6-ce30b8a37b35)
     <br>
     ![29231702321290_ pic](https://github.com/grandy0831/MDB-AIRBEACON/assets/140076679/7ea0ea1f-82ae-45f0-94ad-8523640efa74)
     <div align="center">（Enclosure design）</div>
     <br><br>

