#include <reg51.h>
#include <string.h>
#include "lcd.h"

// Keypad pins
sbit R1 = P1^0;
sbit R2 = P1^1;
sbit R3 = P1^2;
sbit R4 = P1^3;

sbit C1 = P1^4;
sbit C2 = P1^5;
sbit C3 = P1^6;

// Outputs
sbit RE = P3^4;  // Relay
sbit G = P3^5;   // Green LED
sbit R = P3^6;   // Red LED

// Variables
char actual_pass[] = "1234";
char entered_pass[5];
int n = 0;
int wrong_attempts = 0;

// Delay function (approximate 1 ms)
void delay_ms(unsigned int ms) {
    unsigned int i, j;
    for(i = 0; i < ms; i++)
        for(j = 0; j < 1275; j++);
}

void main() {
    lcd_init();
    lcd_string("Enter Pass:");
    lcd_cmd(0xC0); // Move cursor to 2nd line

    RE = 0; G = 0; R = 0; // All OFF

    while(1) {
        if(n < 4) {
            // Row 1
            R1 = 0; R2 = R3 = R4 = 1;
            if(C1 == 0) { lcd_data('1'); entered_pass[n++] = '1'; while(C1==0); delay_ms(100); }
            if(C2 == 0) { lcd_data('2'); entered_pass[n++] = '2'; while(C2==0); delay_ms(100); }
            if(C3 == 0) { lcd_data('3'); entered_pass[n++] = '3'; while(C3==0); delay_ms(100); }

            // Row 2
            R2 = 0; R1 = R3 = R4 = 1;
            if(C1 == 0) { lcd_data('4'); entered_pass[n++] = '4'; while(C1==0); delay_ms(100); }
            if(C2 == 0) { lcd_data('5'); entered_pass[n++] = '5'; while(C2==0); delay_ms(100); }
            if(C3 == 0) { lcd_data('6'); entered_pass[n++] = '6'; while(C3==0); delay_ms(100); }

            // Row 3
            R3 = 0; R1 = R2 = R4 = 1;
            if(C1 == 0) { lcd_data('7'); entered_pass[n++] = '7'; while(C1==0); delay_ms(100); }
            if(C2 == 0) { lcd_data('8'); entered_pass[n++] = '8'; while(C2==0); delay_ms(100); }
            if(C3 == 0) { lcd_data('9'); entered_pass[n++] = '9'; while(C3==0); delay_ms(100); }

            // Row 4
            R4 = 0; R1 = R2 = R3 = 1;
            if(C1 == 0) {
                // * = Backspace
                if(n > 0) {
                    n--;
                    lcd_cmd(0xC0 + n);  // Move cursor to previous char
                    lcd_data(' ');
                    lcd_cmd(0xC0 + n);  // Move cursor back again
                }
                while(C1==0); delay_ms(200);
            }
            if(C2 == 0) { lcd_data('0'); entered_pass[n++] = '0'; while(C2==0); delay_ms(200); }
            if(C3 == 0) { /* # = No action */ while(C3==0); delay_ms(200); }
        }

        if(n == 4) {
            entered_pass[4] = '\0';

            if(strcmp(entered_pass, actual_pass) == 0) {
                RE = 1; G = 1; R = 0;
                lcd_cmd(0x01);
                lcd_cmd(0x80);
                lcd_string("Access Granted");
                delay_ms(100);
                lcd_cmd(0x01);
                lcd_cmd(0x80);
                lcd_string("Enter Pass:");
                lcd_cmd(0xC0);
                RE = 0; G = 0; R = 0;
                wrong_attempts = 0;
            } else {
                wrong_attempts++;
                RE = 0; G = 0; R = 1;
                lcd_cmd(0x01);
                lcd_cmd(0x80);
                lcd_string("Access Denied");
                delay_ms(100);

                if(wrong_attempts < 3) {
                    lcd_cmd(0x01);
                    lcd_cmd(0x80);
                    lcd_string("Try Again");
                    delay_ms(100);
                    lcd_cmd(0x01);
                    lcd_cmd(0x80);
                    lcd_string("Enter Pass:");
                    lcd_cmd(0xC0);
                } else {
                    lcd_cmd(0x01);
                    lcd_cmd(0x80);
                    lcd_string("Please Wait");
                    lcd_cmd(0xC0);
                    lcd_string("few Seconds");
                    delay_ms(2500);
                    lcd_cmd(0x01);
                    lcd_cmd(0x80);
                    lcd_string("Enter Pass:");
                    lcd_cmd(0xC0);
                    wrong_attempts = 0;
                }
            }
            n = 0;
        }
    }
}
