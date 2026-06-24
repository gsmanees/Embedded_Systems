STM32 BMP280 Sensor Interface
This project demonstrates how to interface a BMP280 Barometric Pressure and Temperature sensor with an STM32F446RE (Nucleo-64) board using the SPI communication protocol.

Project Overview
This firmware captures raw atmospheric data from the BMP280 sensor, applies Bosch’s official compensation algorithms, and outputs the calibrated Temperature (Celsius) and Pressure (Pascals) to the SWV (Serial Wire Viewer) ITM console.

Hardware Requirements
Microcontroller: Nucleo-F446RE

Sensor: BMP280 Breakout Board

Wiring Setup (SPI Mode):

VCC -> 3.3V

GND -> GND

SCK (D13) -> PA5

MISO (D12) -> PA6

MOSI (D11) -> PA7

CSB (A2) -> PA4

Features
Custom SPI Driver: Bare-metal implementation of SPI master mode.

Calibration Support: Reads factory-trimmed compensation coefficients from the sensor's ROM.

Bosch Compensation Algorithms: Integer-based math to convert raw ADC values to accurate environmental data.

Real-time Monitoring: Data output via SWV for non-intrusive debugging.

How to Compile
Open the project in STM32CubeIDE.

Ensure the project is set to use the standard ARM GCC Toolchain.

Build the project using the "Build" (hammer icon) button.

Flash the binary to the Nucleo board using the integrated ST-LINK debugger.

Usage
Once flashed, open the SWV ITM Data Console in your IDE.

Configure the trace clock to match your system core clock (usually 16 MHz).

Enable Port 0 and click the Start Trace (red record button).

Reset the board; the console will display the sensor initialization status and streaming weather data.

Troubleshooting
Sensor not found? Ensure the CSB pin is being pulled low during communication.

Garbage data? Verify that the MSB bit logic in BMP280_ReadRegisters (reading) and BMP280_WriteRegister (writing) matches the sensor's SPI protocol requirements.

No Output? Confirm that your SWV settings are enabled and that the trace frequency is set correctly in the debug configuration.

This project was developed as a bare-metal embedded systems learning exercise.