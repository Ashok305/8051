#include <reg51.h>  // 8051 microcontroller header

void delay(int time);  // Delay function prototype

void main()
{
    while(1)
    {
        // Motor A forward: P2.0 = 1, P2.1 = 0
        // Motor B reverse: P3.0 = 0, P3.1 = 1
        P2 = 0x01;  // 00000001 -> A1=1, A2=0
        P3 = 0x02;  // 00000010 -> B1=0, B2=1
        delay(2000);

        // Motor A reverse: P2.0 = 0, P2.1 = 1
        // Motor B forward: P3.0 = 1, P3.1 = 0
        P2 = 0x02;  // 00000010 -> A1=0, A2=1
        P3 = 0x01;  // 00000001 -> B1=1, B2=0
        delay(2000);
    }
}

// Software delay function
void delay(int time)
{
    int i, j;
    for(i = 0; i < time; i++)
    {
        for(j = 0; j < 250; j++)
        {
            // Empty loop for delay
        }
    }
}