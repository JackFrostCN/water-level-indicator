# Setup Instructions

This guide will help you set up the HC-SR04 ultrasonic sensor, PIC16F887 microcontroller, and 1602A LCD display.

## Components Required
- PIC16F887 Microcontroller
- HC-SR04 Ultrasonic Sensor
- 1602A LCD Display
- 4MHz Crystal Oscillator
- Resistors (for pull-up/down as needed)
- Jumper Wires
- Breadboard

## Wiring Instructions
1. **HC-SR04**:
   - Connect the **VCC** pin to 5V.
   - Connect the **GND** pin to GND.
   - Connect the **Trig** pin to Pin 1 (GPIO) on PIC16F887.
   - Connect the **Echo** pin to Pin 2 (GPIO) on PIC16F887.
   
2. **1602A LCD**:
   - Connect the **VCC** pin to 5V.
   - Connect the **GND** pin to GND.
   - Connect **RS** to Pin 3 (GPIO) on PIC16F887.
   - Connect **EN** to Pin 4 (GPIO) on PIC16F887.
   - Connect **D4, D5, D6, D7** to Pins 5-8 (GPIO) on PIC16F887.

## Software Setup
1. Install MPLAB X IDE and the XC8 compiler.
2. Open the project in MPLAB X IDE.
3. Compile the code and upload it to the PIC16F887 using a programmer (e.g., PICkit 3).
4. After successful upload, power the circuit, and the distance will be displayed on the LCD.

## Troubleshooting
- **LCD not displaying anything**: Double-check wiring connections, especially the LCD pins.
- **No distance readings**: Verify that the Trig and Echo pins are connected properly, and the ultrasonic sensor is functioning.
