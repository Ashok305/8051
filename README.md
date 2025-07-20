# 🔐 Embedded Systems: Interfacing Modules & Security System Project

A collection of embedded systems mini-projects focused on hardware interfacing using the **8051 microcontroller**, along with a **complete password-protected security system**.

This repository is ideal for beginners learning how to interface peripherals like LCDs, keypads, motors, switches, and serial devices with the 8051 MCU.

---

## 🛠️ Tools & Technologies

- **Microcontroller**: 8051 (AT89C51)
- **Programming Language**: Embedded C
- **IDE**: Keil µVision
- **Simulation**: Proteus 8
- **Peripherals Used**: LCD, 7-Segment Display, Matrix Keypad, DC Motor, Switches, UART

---

## 📦 Interface Modules

These folders contain basic interfacing programs used in embedded systems:

| Module | Description |
|--------|-------------|
| `16x2 lcd` | Display messages or data on a 16x2 alphanumeric LCD. |
| `7 segment with common anode` | Display numbers using a 7-segment display (common anode). |
| `counter0` | Button-based counter using interrupts. |
| `dc motor` | Control motor direction using GPIOs. |
| `interrupt` | Handle external interrupt (e.g., toggle LED). |
| `led blink` | Blink LED using software delay. |
| `led with pull up switch` | Control LED using a pull-up configured switch. |
| `matrix keyboard` | Scan and detect keys from a 4x3 keypad. |
| `timer 0` | Generate delay (e.g., 10ms) using Timer 0. |
| `uart` | Serial data communication using UART (send & receive). |

---

## 🛡️ Security System Project

**Folder**: `protective security system project`

This is the main project in this repository – a **password-protected system** using a matrix keypad and 16x2 LCD.

### 🔑 Features

- User inputs a 4-digit PIN using keypad  
- Feedback is displayed on the LCD screen  
- Access is granted or denied based on correctness  
- Can be extended with buzzer, relay, or motor for door control

---

## ▶️ How to Run

1. Clone this repo or download the ZIP.
2. Open any folder in **Keil µVision**.
3. Build the project and generate the HEX file.
4. Open **Proteus** and load the HEX into the microcontroller.
5. Simulate or flash it onto real hardware.

---

## 📌 Notes

- All codes are written in simple Embedded C.
- Simulation-ready with Proteus-compatible HEX files.
- Helpful for academic labs, mini-projects, and embedded practice.

---

## 👨‍💻 Author

**Ashok T**  
Embedded Systems Learner  
[LinkedIn](https://www.linkedin.com/in/ashok-t-b911b0257)

---

## 📄 License

Free for personal and educational use. Attribution appreciated.
