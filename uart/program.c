#include <reg51.h>  // Include 8051 register definitions

// Function Prototypes
void UART_Init();             // UART Initialization
void UART_Transmit(char ch); // Transmit one character
char UART_Receive();          // Receive one character

// Main Function
void main() {
    UART_Init();              // Step 1: Set up UART
    UART_Transmit('h');       // Step 2: Send 'h' to terminal

    while(1) {
        char receivedChar = UART_Receive(); // Step 3: Wait and get one char
        UART_Transmit(receivedChar);        // Step 4: Send it back (echo)
    }
}

// Function to Initialize UART
void UART_Init() {
    SCON = 0x50;   // Mode 1 (8-bit UART), REN=1 (Receiver enabled)
    TMOD = 0x20;   // Timer1 in Mode 2 (8-bit auto-reload)
    TH1 = 0xFD;    // 9600 baud rate for 11.0592MHz crystal
    TR1 = 1;       // Start Timer1
}

// Function to Transmit a Character
void UART_Transmit(char ch) {
    SBUF = ch;         // Load character into Serial Buffer
    while(TI == 0);    // Wait for transmission to complete
    TI = 0;            // Clear the transmit flag for next use
}

// Function to Receive a Character
char UART_Receive() {
    while(RI == 0);    // Wait for character to be received
    RI = 0;            // Clear receive flag
    return SBUF;       // Return received character
}
