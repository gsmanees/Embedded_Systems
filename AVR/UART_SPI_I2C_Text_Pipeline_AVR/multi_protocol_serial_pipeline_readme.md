# Multi-Protocol Serial Data Pipeline (UART → SPI → I²C)

## Project Overview
This project demonstrates an **end-to-end serial data pipeline** implemented at **bare-metal, register level**, where text entered from a PC serial monitor is transferred across multiple communication protocols and microcontrollers.

The system is built incrementally in clearly defined stages, each representing a stable, working milestone.

**High-level data flow:**

PC Serial Monitor → **UART** → AVR → **SPI** → STM32 → **I²C** → OLED / LCD

---

## Objectives
- Understand and implement **UART, SPI, and I²C** at register level
- Handle **ASCII data**, control characters (CR/LF), and buffering
- Design a **multi-MCU communication pipeline**
- Build firmware without HAL or high-level abstraction layers
- Maintain clean project structure suitable for review and interviews

---

## Repository Structure

```text
Multi-Protocol-Serial-Pipeline/
│
├── stage-01_uart_lcd_echo/
│   ├── avr/
│   │   ├── main.c
│   │   ├── uart.c
│   │   ├── uart.h
│   │   ├── lcd.c
│   │   └── lcd.h
│   └── README.md
│
├── stage-02_uart_spi_bridge/      (planned)
│   ├── avr/
│   └── stm32/
│
├── stage-03_spi_i2c_oled/         (planned)
│   └── stm32/
│
└── docs/
    └── system_overview.md
```

Each **stage folder is self-contained** and represents a complete, buildable milestone.

---

## Stage 01 – UART to LCD Text Echo

### Description
In this stage, text typed into a PC serial monitor is:
- Received by an **AVR microcontroller via UART**
- Processed as ASCII characters
- Displayed on a **16×2 HD44780 LCD** in real time

### Features
- Bare-metal UART RX/TX
- ASCII character handling
- CR/LF filtering from serial input
- Manual cursor control for LCD
- Auto line wrapping from line 1 to line 2

### Hardware Used
- AVR microcontroller (bare metal)
- USB-to-UART interface
- 16×2 HD44780 compatible LCD (parallel mode)

---

## Upcoming Stages

### Stage 02 – UART to SPI Bridge
- AVR receives UART data
- Forwards characters to STM32 via SPI
- Implements SPI master (AVR) and slave (STM32)
- Focus on synchronization and data framing

### Stage 03 – SPI to I²C OLED Display
- STM32 receives SPI data
- Sends text to OLED using I²C
- OLED text rendering and cursor control

---

## Development Approach
- No HAL, no Arduino framework
- Register-level peripheral access
- Incremental development with frozen milestones
- Code written for clarity and learning

---

## How to Use
1. Navigate to the required stage folder
2. Build and flash firmware for the target MCU
3. Connect hardware as described in that stage’s README
4. Open serial monitor and type text

---

## Author
**Anees Kokadan**  
Embedded Systems | Bare-Metal Firmware | Communication Protocols

---

## Notes
This repository is designed for **learning, demonstration, and technical review**. Each stage reflects real-world embedded development practices such as modular design, protocol layering, and incremental validation.