/*
 * bmp280.c
 *
 *  Created on: 25-Jun-2026
 *      Author: anees
 */
#include "bmp280.h"
#include "stm32f446xx.h"

// Global Structure to hold factory calibration data
struct {
    uint16_t dig_T1; int16_t dig_T2; int16_t dig_T3;
    uint16_t dig_P1; int16_t dig_P2; int16_t dig_P3;
    int16_t  dig_P4; int16_t dig_P5; int16_t dig_P6;
    int16_t  dig_P7; int16_t dig_P8; int16_t dig_P9;
} calib;

int32_t t_fine; // Global variable used by the compensation formulas


// ==============================================================================
// 3. SENSOR CALIBRATION AND CONFIGURATION
// ==============================================================================
void BMP280_ReadCalibrationData(void)
{
    uint8_t raw[24];
    BMP280_ReadRegisters(BMP280_REG_CALIB, raw, 24);

    // Bit-shift the raw bytes into proper 16-bit integers
    calib.dig_T1 = (raw[1] << 8) | raw[0];
    calib.dig_T2 = (raw[3] << 8) | raw[2];
    calib.dig_T3 = (raw[5] << 8) | raw[4];
    calib.dig_P1 = (raw[7] << 8) | raw[6];
    calib.dig_P2 = (raw[9] << 8) | raw[8];
    calib.dig_P3 = (raw[11] << 8) | raw[10];
    calib.dig_P4 = (raw[13] << 8) | raw[12];
    calib.dig_P5 = (raw[15] << 8) | raw[14];
    calib.dig_P6 = (raw[17] << 8) | raw[16];
    calib.dig_P7 = (raw[19] << 8) | raw[18];
    calib.dig_P8 = (raw[21] << 8) | raw[20];
    calib.dig_P9 = (raw[23] << 8) | raw[22];
}

void BMP280_WakeUp(void)
{
    // Write 0x27 to Ctrl_Meas Register:
    // Temp Oversampling x1 (001), Press Oversampling x1 (001), Normal Power Mode (11)
    BMP280_WriteRegister(BMP280_REG_CTRL_MEAS, 0x27);

    // Write 0x00 to Config Register: Standby time 0.5ms, Filter Off
    BMP280_WriteRegister(BMP280_REG_CONFIG, 0x00);
}

// ==============================================================================
// 4. OFFICIAL BOSCH COMPENSATION ALGORITHMS
// ==============================================================================
// Returns Temp in DegC, resolution is 0.01 DegC. Output value of "5123" equals 51.23 DegC.
int32_t BMP280_Compensate_Temperature(int32_t adc_T)
{
    int32_t var1, var2, T;
    var1 = ((((adc_T >> 3) - ((int32_t)calib.dig_T1 << 1))) * ((int32_t)calib.dig_T2)) >> 11;
    var2 = (((((adc_T >> 4) - ((int32_t)calib.dig_T1)) * ((adc_T >> 4) - ((int32_t)calib.dig_T1))) >> 12) * ((int32_t)calib.dig_T3)) >> 14;
    t_fine = var1 + var2;
    T = (t_fine * 5 + 128) >> 8;
    return T;
}

// Returns Pressure in Pascals (Pa). Output value of "24674867" represents 24674867 / 256 = 96386.2 Pa
uint32_t BMP280_Compensate_Pressure(int32_t adc_P)
{
    int64_t var1, var2, p;
    var1 = ((int64_t)t_fine) - 128000;
    var2 = var1 * var1 * (int64_t)calib.dig_P6;
    var2 = var2 + ((var1 * (int64_t)calib.dig_P5) << 17);
    var2 = var2 + (((int64_t)calib.dig_P4) << 35);
    var1 = ((var1 * var1 * (int64_t)calib.dig_P3) >> 8) + ((var1 * (int64_t)calib.dig_P2) << 12);
    var1 = (((((int64_t)1) << 47) + var1)) * ((int64_t)calib.dig_P1) >> 33;
    if (var1 == 0) return 0; // Avoid division by zero
    p = 1048576 - adc_P;
    p = (((p << 31) - var2) * 3125) / var1;
    var1 = (((int64_t)calib.dig_P9) * (p >> 13) * (p >> 13)) >> 25;
    var2 = (((int64_t)calib.dig_P8) * p) >> 19;
    p = ((p + var1 + var2) >> 8) + (((int64_t)calib.dig_P7) << 4);
    return (uint32_t)p;
}
