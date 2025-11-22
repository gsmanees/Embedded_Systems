AtmosTrack v1.0 – README

Developer: Anees Kokadan
Project: Atmospheric Pressure & Temperature Monitoring System
Sensor: BMP280 (SPI Interface)

📌 Project Overview

AtmosTrack v1.0 is a compact atmospheric monitoring system designed to measure real-time temperature and pressure using the BMP280 environmental sensor. This project showcases low-level embedded development, sensor interfacing, and data compensation techniques based on Bosch’s calibration algorithms.

🔧 Technical Features

SPI Communication: Fully implemented BMP280 interface using the SPI protocol

Sensor Data Acquisition: Raw MSB, LSB, and xLSB register reads for temperature & pressure

Calibration Processing: Extraction of all dig_T and dig_P constants from 0x88 onward

Compensation Algorithms: Accurate conversion of raw ADC values to real-world °C and Pa

Modular Embedded C Design: Clean driver architecture for clarity and reusability

Real-Time Output: Continuous environmental monitoring with stable results


📡 Connections (SPI Mode)

SCK → MCU SPI Clock

MOSI (SDI) → MCU Master Out

MISO (SDO) → MCU Master In

CS → MCU Chip Select

VCC → 3.3V

GND → Ground

🎯 Learning Outcomes

Through AtmosTrack, I strengthened my expertise in:

Low-level register communication

Embedded C driver development

Sensor calibration mathematics

SPI timing and protocol behavior

Practical debugging of real-time systems