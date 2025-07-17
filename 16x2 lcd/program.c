#include <reg51.h>

// Define LCD control pins
sbit RS = P1^0;  // Register Select
sbit RW = P1^1;  // Read/Write
sbit EN = P1^2;  // Enable

// Function declarations
void lcd_init();
void lcd_cmd(unsigned char cmd);
void lcd_data(unsigned char dat);
void lcd_string(char *str);
void delay(unsigned int ms);

// Main function
void main() {
    lcd_init();              // Initialize LCD
    lcd_string("Welcome");   // Display "Welcome" on 1st line
    lcd_cmd(0xC0);           // Move to 2nd line
    lcd_string("Home");      // Display "Home" on 2nd line

    while(1);                // Infinite loop to keep display on
}

// Initialize LCD
void lcd_init() {
    lcd_cmd(0x38);   // 8-bit mode, 2-line, 5x7 matrix
    lcd_cmd(0x0C);   // Display ON, Cursor OFF
    lcd_cmd(0x01);   // Clear display
    lcd_cmd(0x80);   // Set cursor to beginning of first line
}

// Send command to LCD
void lcd_cmd(unsigned char cmd) {
    P2 = cmd;        // Send command on data lines
    RS = 0;          // RS = 0 for command
    RW = 0;          // RW = 0 for write
    EN = 1;          // Enable pulse
    delay(2);
    EN = 0;
    delay(2);
}

// Send data (character) to LCD
void lcd_data(unsigned char dat) {
    P2 = dat;        // Send data on data lines
    RS = 1;          // RS = 1 for data
    RW = 0;          // RW = 0 for write
    EN = 1;          // Enable pulse
    delay(2);
    EN = 0;
    delay(2);
}

// Send full string to LCD
void lcd_string(char *str) {
    while(*str) {         // Until null character
        lcd_data(*str);   // Send each character
        str++;            // Move to next character
    }
}

// Simple delay function
void delay(unsigned int ms) {
    unsigned int i, j;
    for(i = 0; i < ms; i++)
        for(j = 0; j < 1275; j++);
}
