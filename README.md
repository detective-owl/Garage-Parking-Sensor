# Garage-Parking-Sensor
HC-SR04 Distance sensor with LCD and LED distance interface. This project aims to use an ultrasonic distance sensor to measure the disance the the car or any object and shows the current distance on the LCD Display and 12 LED's light up according to the distance specified. 

### Files:
1. Garage Sensor PCB Design with Top and Bottom= All the connections ang the PCB design. 
2. Garage Sensor with LED.ino= Code the Ultrasonic Garage Sensor With LED's 
3. No Ground Plate= Gerber File of the PCB

### MATERIALS USED:
1. 1 Ultrasonic Sensor HC-SR04
2. 1 IC2 LCD Display
3. 1 Arduino Uno
4. LED (3 Red, 2 Yellow, 1 Green)
5. 11 Resistors (150 OHM)

### ARDUINO CONNECTIONS:
*HC-SR04*
1. TRIG-D9
2. ECHO-D10
3. VCC-5V
4. GND-GND

*LCD*                 
1. GND-GND
2. VCC-VCC
3. SDA-A4
4. SCK-A5

*LED*
1. Green-D3
2. Yellow 1-D4
3. Yellow 2-D5
4. Red 1-D6
5. Red 2-D7
6. Red 3-D8

### SCHEMATICS
1. Ultrasonic Garage Sensor with LED's
![alt text](https://github.com/detective-owl/Garage-Parking-Sensor/blob/main/Images/Garage%20Sensor%20Schematics.png)
