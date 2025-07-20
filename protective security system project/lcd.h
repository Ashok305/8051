#ifndef LCD_H
#define LCD_H

#include <reg51.h>

// LCD control pins
sbit RS = P3^0;
sbit RW = P3^1;
sbit EN = P3^2;

// Function declarations
void lcd_init();
void lcd_cmd(unsigned char cmd);
void lcd_data(unsigned char dat);
void lcd_string(char *str);
void delay(unsigned int ms);

// Initialize LCD
void lcd_init() {
    lcd_cmd(0x38);   // 8-bit, 2-line, 5x7
    lcd_cmd(0x0C);   // Display ON, cursor OFF
    lcd_cmd(0x01);   // Clear screen
    lcd_cmd(0x80);   // Cursor at line 1, pos 1
}

// Send command to LCD
void lcd_cmd(unsigned char cmd) {
    P2 = cmd;
    RS = 0;
    RW = 0;
    EN = 1;
    delay(2);
    EN = 0;
    delay(2);
}

// Send data to LCD
void lcd_data(unsigned char dat) {
    P2 = dat;
    RS = 1;
    RW = 0;
    EN = 1;
    delay(2);
    EN = 0;
    delay(2);
}

// Send full string
void lcd_string(char *str) {
    while(*str) {
        lcd_data(*str);
        str++;
    }
}

// Short delay
void delay(unsigned int ms) {
    unsigned int i, j;
    for(i = 0; i < ms; i++)
        for(j = 0; j < 1275; j++);
}

#endif
