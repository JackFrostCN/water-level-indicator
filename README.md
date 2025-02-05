# HC-SR04 Ultrasonic Sensor with PIC16F887 and 1602A LCD

This project demonstrates how to interface the HC-SR04 ultrasonic sensor with the PIC16F887 microcontroller to measure distance and display the result on a 1602A LCD screen. The system works by sending a pulse from the sensor, measuring the time it takes for the echo to return, and calculating the distance. The result is then displayed in real-time on the LCD.

## Features
- **Distance Measurement**: Uses the HC-SR04 ultrasonic sensor to measure the distance to an object.
- **LCD Display**: Displays the measured distance on a 1602A LCD screen.
- **Embedded C Code**: Written in Embedded C for the PIC16F887 microcontroller.
- **Real-Time Update**: LCD is updated in real time with distance measurements.

## Requirements
- **Hardware**:
  - PIC16F887 Microcontroller
  - HC-SR04 Ultrasonic Sensor
  - 1602A LCD Display
  - 4 MHz Crystal Oscillator
  - Resistors and Connecting Wires
- **Software**:
  - MPLAB X IDE
  - XC8 Compiler

## Circuit Diagram
You can find the schematic diagram and connection details in the `/Schematics` folder.

## Installation and Usage
1. Clone or download this repository to your local machine.
2. Open the project in MPLAB X IDE.
3. Compile the code using the XC8 compiler.
4. Upload the program to the PIC16F887 microcontroller using your preferred programmer (e.g., PICkit 3).
5. Wire the components according to the schematic in the `/Schematics` folder.
6. Power on the circuit, and the LCD should display the measured distance.

## Code Overview
The code runs on the PIC16F887 and:
- Initializes the HC-SR04 ultrasonic sensor.
- Sends a trigger pulse and waits for the echo pulse.
- Calculates the distance based on the time taken for the echo to return.
- Displays the calculated distance on the LCD screen.

The code is written in Embedded C and is compatible with MPLAB X IDE and the XC8 compiler.

## Folder Structure
- `/Code`: Contains the Embedded C code for the PIC16F887 microcontroller.
- `/Schematics`: Contains the circuit schematic for connecting the components.
- `/Docs`: Contains project documentation, including setup instructions and any additional notes.

## License
This project is open-source and free to use. Feel free to modify and distribute the code under the [MIT License](LICENSE).

## Author
ICN Patabendige  
Faculty of Computing, General Sir John Kotelawala Defence University

## Acknowledgements
- HC-SR04 Ultrasonic Sensor datasheet
- 1602A LCD datasheet
- MPLAB X IDE and XC8 compiler
