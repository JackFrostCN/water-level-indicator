# HC-SR04 Ultrasonic Sensor with PIC16F887 and 1602A LCD

This project demonstrates how to interface the **HC-SR04 ultrasonic sensor** with the **PIC16F887 microcontroller** to measure distance and display the result on a **1602A LCD screen**. The system sends a pulse from the sensor, measures the time it takes for the echo to return, and calculates the distance. Additionally, a **buzzer** is included to provide feedback when the measured distance falls below a safe threshold (e.g., when an object is too close).

## Features
- **Distance Measurement**: Uses the HC-SR04 ultrasonic sensor to measure the distance to an object.
- **LCD Display**: Displays the measured distance on a 1602A LCD screen in real-time.
- **Buzzer Feedback**: Provides an audible alert via a buzzer when the measured distance is below a predefined safe threshold (e.g., less than 10 cm).
- **Embedded C Code**: Written in Embedded C for the PIC16F887 microcontroller using MPLAB X IDE and the XC8 Compiler.
- **Real-Time Update**: The LCD updates in real-time as the sensor measures distance.

## Requirements

### Hardware
- **PIC16F887 Microcontroller**
- **HC-SR04 Ultrasonic Sensor**
- **1602A LCD Display**
- **Buzzer (Active or Passive)**
- **4 MHz Crystal Oscillator**
- **Resistors and Connecting Wires**
  
### Software
- **MPLAB X IDE**
- **XC8 Compiler**

## Installation and Usage

1. **Clone or Download** this repository to your local machine.
   
2. **Open the Project** in MPLAB X IDE.

3. **Compile the Code** using the XC8 compiler.

4. **Upload the Program** to the **PIC16F887 microcontroller** using your preferred programmer (e.g., PICkit 3).

5. **Connect the Components** according to the schematic in the `/Schematics` folder.

6. **Power On** the circuit. The LCD should display the measured distance in real-time, and the buzzer will sound when the distance is below the safe threshold.

## Code Overview

The code runs on the **PIC16F887** and performs the following tasks:
- Initializes the **HC-SR04 ultrasonic sensor**.
- Sends a **trigger pulse** and waits for the **echo pulse**.
- Calculates the **distance** based on the time taken for the echo to return.
- Displays the **calculated distance** on the **LCD screen**.
- Provides **buzzer feedback** if the distance is less than a safe threshold (e.g., less than 10 cm).

## Circuit Diagram

You can find the circuit schematic for connecting the components in the `/Schematics` folder.

## File Structure
```
/Code:           Contains the Embedded C code for the PIC16F887 microcontroller.
/Schematics:     Contains the circuit schematic for connecting the components.
/Docs:            Contains project documentation, including setup instructions and any additional notes.
```

## License

This project is open-source and free to use. Feel free to modify and distribute the code under the **MIT License**.

## Author

**ICN Patabendige**  
Faculty of Computing, General Sir John Kotelawala Defence University

## Acknowledgements
- **HC-SR04 Ultrasonic Sensor** datasheet
- **1602A LCD** datasheet
- **MPLAB X IDE** and **XC8 compiler**
