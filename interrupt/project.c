#include <reg51.h>

void delay(int a);
sbit led = P2^0;

void isr_ex0() interrupt 0   // External interrupt 0 ISR
{
    led = ~led;              // Toggle the LED
    delay(10);               // Small delay to debounce
}

void main()
{
    P2 = 0x00;               // Initialize Port 2 to 0
    led = 0;                 // Ensure LED is off initially

    TCON = 0x01;             // Set IT0 = 1 (edge triggered), IE0 = 0
    IE = 0x81;               // Enable EA (global interrupt) and EX0 (external int 0)

    while(1);                // Infinite loop, wait for interrupt
}

void delay(int a)
{
    int i, j;
    for(i = 0; i < a; i++)
        for(j = 0; j < 1275; j++);  // Approximate delay
}
