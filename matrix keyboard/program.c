#include <reg51.h>

void delay(int a);

// Keypad row and column pin mapping
sbit R1 = P2^0;
sbit R2 = P2^1;
sbit R3 = P2^2;
sbit R4 = P2^3;

sbit C1 = P2^4;
sbit C2 = P2^5;
sbit C3 = P2^6;

void main() {
	while(1) {
		// Clear all rows and set to HIGH
		R1 = R2 = R3 = R4 = C1 = C2 = C3 = 1;

		// Scan Row 1 (R1 = 0)
		R1 = 0;
		if(C1 == 0) { P3 = 0xF9; delay(200); } // 1
		else if(C2 == 0) { P3 = 0xA4; delay(200); } // 2
		else if(C3 == 0) { P3 = 0xB0; delay(200); } // 3

		// Reset all rows
		R1 = R2 = R3 = R4 = C1 = C2 = C3 = 1;

		// Scan Row 2 (R2 = 0)
		R2 = 0;
		if(C1 == 0) { P3 = 0x99; delay(200); } // 4
		else if(C2 == 0) { P3 = 0x92; delay(200); } // 5
		else if(C3 == 0) { P3 = 0x82; delay(200); } // 6

		R1 = R2 = R3 = R4 = C1 = C2 = C3 = 1;

		// Scan Row 3 (R3 = 0)
		R3 = 0;
		if(C1 == 0) { P3 = 0xF8; delay(200); } // 7
		else if(C2 == 0) { P3 = 0x80; delay(200); } // 8
		else if(C3 == 0) { P3 = 0x90; delay(200); } // 9

		R1 = R2 = R3 = R4 = C1 = C2 = C3 = 1;

		// Scan Row 4 (R4 = 0)
		R4 = 0;
		if(C1 == 0) { P3 = 0xC6; delay(200); } // * (any pattern)
		else if(C2 == 0) { P3 = 0xC0; delay(200); } // 0
		else if(C3 == 0) { P3 = 0x86; delay(200); } // # (any pattern)
	}
}

// Delay function
void delay(int a) {
	int i, j;
	for(i = 0; i < a; i++) {
		for(j = 0; j < 1275; j++);
	}
}
