#include <xc.h>
#include <stdio.h>

// CONFIGURATION BITS (Use Internal 8MHz Oscillator)
#pragma config FOSC = INTRC_NOCLKOUT
#pragma config WDTE = OFF
#pragma config PWRTE = OFF
#pragma config BOREN = ON
#pragma config LVP = OFF

#define _XTAL_FREQ 8000000  // Define CPU Clock Frequency (8MHz)

// LCD Control Pins
#define RS RD0
#define EN RD1
#define D4 RD2
#define D5 RD3
#define D6 RD4
#define D7 RD5

// HC-SR04 Pins
#define TRIG RC0
#define ECHO RC1

// Buzzer and Relay Pins
#define BUZZER RB0
#define RELAY RB1

// Function to Send Command to LCD
void LCD_Command(unsigned char cmd) {
    RS = 0;  // Command mode
    D4 = (cmd >> 4) & 1;
    D5 = (cmd >> 5) & 1;
    D6 = (cmd >> 6) & 1;
    D7 = (cmd >> 7) & 1;
    EN = 1;
    __delay_ms(2);
    EN = 0;
    
    D4 = cmd & 1;
    D5 = (cmd >> 1) & 1;
    D6 = (cmd >> 2) & 1;
    D7 = (cmd >> 3) & 1;
    EN = 1;
    __delay_ms(2);
    EN = 0;
}

// Function to Send Data to LCD
void LCD_Char(char data) {
    RS = 1;  // Data mode
    D4 = (data >> 4) & 1;
    D5 = (data >> 5) & 1;
    D6 = (data >> 6) & 1;
    D7 = (data >> 7) & 1;
    EN = 1;
    __delay_ms(2);
    EN = 0;
    
    D4 = data & 1;
    D5 = (data >> 1) & 1;
    D6 = (data >> 2) & 1;
    D7 = (data >> 3) & 1;
    EN = 1;
    __delay_ms(2);
    EN = 0;
}

// Function to Send a String to LCD
void LCD_String(const char *str) {
    while (*str) {
        LCD_Char(*str++);
    }
}

// Function to Initialize LCD in 4-bit Mode
void LCD_Init() {
    TRISD = 0x00;  // Set PORTD as output
    __delay_ms(20);
    
    LCD_Command(0x02);  // 4-bit mode
    LCD_Command(0x28);  // 2 lines, 5x7 matrix
    LCD_Command(0x0C);  // Display ON, Cursor OFF
    LCD_Command(0x06);  // Auto Increment Cursor
    LCD_Command(0x01);  // Clear Display
    __delay_ms(2);
}

// Function to Initialize HC-SR04
void HC_SR04_Init() {
    TRISCbits.TRISC0 = 0;  // Set TRIG pin as output
    TRISCbits.TRISC1 = 1;  // Set ECHO pin as input
}

// Function to Measure Distance Using HC-SR04
unsigned int Measure_Distance() {
    unsigned int pulse_time;
    unsigned int distance;

    // Send Trigger pulse
    TRIG = 1;
    __delay_us(10);  // 10 microseconds pulse width
    TRIG = 0;
    
    // Wait for Echo to go high
    while (!ECHO);
    
    // Start Timer when Echo is high
    TMR1H = 0;  // Clear Timer1 High byte
    TMR1L = 0;  // Clear Timer1 Low byte
    T1CON = 0x01;  // Enable Timer1, prescaler 1:1
    
    // Wait for Echo to go low
    while (ECHO);
    
    // Stop Timer when Echo goes low
    T1CON = 0x00;  // Disable Timer1
    
    // Calculate pulse time in microseconds
    pulse_time = (TMR1H << 8) | TMR1L;
    
    // Calculate distance (speed of sound = 343 m/s = 0.0343 cm/us)
    distance = (pulse_time * 0.0343) / 2;  // Divide by 2 to account for the round-trip distance
    
    return distance;
}

// Main Program
void main() {
    unsigned int distance;
    char buffer[16];
    int countdown = 90;  // 90 seconds countdown

    OSCCON = 0b01110000;  // Set Internal Oscillator to 8MHz
    LCD_Init();  // Initialize LCD
    HC_SR04_Init();  // Initialize HC-SR04

    TRISBbits.TRISB0 = 0;  // Set BUZZER pin as output
    TRISBbits.TRISB1 = 0;  // Set RELAY pin as output
    
    RELAY = 1;  // Start with Relay ON

    while (1) {
        distance = Measure_Distance();  // Measure distance
        
        if (distance > 25) {  // If distance > 25 cm
            RELAY = 0;  // Turn OFF relay
            BUZZER = 1;  // Beep buzzer
            LCD_Command(0x01);  // Clear Display
            LCD_Command(0x80);  // Move Cursor to First Line
            LCD_String("Water Level Low");
            
            __delay_ms(1000);
            BUZZER = 0;
        } else {
            // Normal operation: Display countdown timer
            sprintf(buffer, "Off in: %d sec", countdown);
            LCD_Command(0x01);  // Clear Display
            LCD_Command(0x80);  // Move Cursor to First Line
            LCD_String(buffer);
            
            __delay_ms(1000);
            countdown--;

            if (countdown == 0) {
                RELAY = 0;  // Turn OFF Relay after 90 seconds
                LCD_Command(0x01);
                LCD_String("Motor OFF");
                while (1);  // Stop execution
            }
        }
    }
}
