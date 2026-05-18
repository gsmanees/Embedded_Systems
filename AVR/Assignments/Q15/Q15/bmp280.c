/*
 * bmp280.c
 *
 * Created: 18-05-2026 6.08.30 AM
 *  Author: anees
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "bmp280.h"
#include "i2c.h"
#include "global.h"

uint16_t dig_T1;
int16_t dig_T2;
int16_t dig_T3;

uint16_t dig_P1;
int16_t dig_P2;
int16_t dig_P3;
int16_t dig_P4;
int16_t dig_P5;
int16_t dig_P6;
int16_t dig_P7;
int16_t dig_P8;
int16_t dig_P9;

int32_t t_fine;

void BMP280_Write(uint8_t reg, uint8_t value)
{
	I2C_Start();
	I2C_Write((BMP280_ADDR << 1) | 0);
	I2C_Write(reg);
	I2C_Write(value);
	I2C_Stop();
}

uint16_t BMP280_Read16_LE(uint8_t reg)
{
	uint16_t value;
	uint8_t lsb, msb;
	I2C_Start();
	I2C_Write((BMP280_ADDR << 1) | 0);
	I2C_Write(reg);
	I2C_Start();
	I2C_Write((BMP280_ADDR << 1) | 1);
	lsb = I2C_Read_ACK();
	msb = I2C_Read_NACK();
	I2C_Stop();
	value = ((uint16_t)msb << 8) | lsb;
	return value;
}

int32_t BMP280_Read24(uint8_t reg)
{
	int32_t value;
	uint8_t msb, lsb, xlsb;
	I2C_Start();
	I2C_Write((BMP280_ADDR << 1) | 0);
	I2C_Write(reg);
	I2C_Start();
	I2C_Write((BMP280_ADDR << 1) | 1);

	msb  = I2C_Read_ACK();
	lsb  = I2C_Read_ACK();
	xlsb = I2C_Read_NACK();

	I2C_Stop();

	value = ((uint32_t)msb << 16) |
	((uint16_t)lsb << 8) |
	xlsb;

	return value;
}

void BMP280_Init(void)
{
	dig_T1 = BMP280_Read16_LE(0x88);
	dig_T2 = (int16_t)BMP280_Read16_LE(0x8A);
	dig_T3 = (int16_t)BMP280_Read16_LE(0x8C);

	dig_P1 = BMP280_Read16_LE(0x8E);
	dig_P2 = (int16_t)BMP280_Read16_LE(0x90);
	dig_P3 = (int16_t)BMP280_Read16_LE(0x92);
	dig_P4 = (int16_t)BMP280_Read16_LE(0x94);
	dig_P5 = (int16_t)BMP280_Read16_LE(0x96);
	dig_P6 = (int16_t)BMP280_Read16_LE(0x98);
	dig_P7 = (int16_t)BMP280_Read16_LE(0x9A);
	dig_P8 = (int16_t)BMP280_Read16_LE(0x9C);
	dig_P9 = (int16_t)BMP280_Read16_LE(0x9E);

	BMP280_Write(0xF4, 0x27);
	BMP280_Write(0xF5, 0xA0);
	_delay_ms(100);
}

float BMP280_ReadTemperature(void)
{
	int32_t adc_T;
	int32_t var1, var2;
	float T;
	adc_T = BMP280_Read24(0xFA);
	adc_T >>= 4;

	var1 = ((((adc_T >> 3) -
	((int32_t)dig_T1 << 1))) *
	((int32_t)dig_T2)) >> 11;

	var2 = (((((adc_T >> 4) -
	((int32_t)dig_T1)) *
	((adc_T >> 4) -
	((int32_t)dig_T1))) >> 12) *
	((int32_t)dig_T3)) >> 14;

	t_fine = var1 + var2;
	T = (t_fine * 5 + 128) >> 8;
	return T / 100.0;
}

float BMP280_ReadPressure(void)
{
	int64_t var1, var2, p;
	int32_t adc_P;
	adc_P = BMP280_Read24(0xF7);
	adc_P >>= 4;
	var1 = ((int64_t)t_fine) - 128000;
	var2 = var1 * var1 * (int64_t)dig_P6;
	var2 = var2 + ((var1 * (int64_t)dig_P5) << 17);
	var2 = var2 + (((int64_t)dig_P4) << 35);
	var1 = ((var1 * var1 * (int64_t)dig_P3) >> 8) +
	((var1 * (int64_t)dig_P2) << 12);
	var1 = (((((int64_t)1) << 47) + var1)) *
	((int64_t)dig_P1) >> 33;

	if(var1 == 0)
	return 0;

	p = 1048576 - adc_P;
	p = (((p << 31) - var2) * 3125) / var1;
	var1 = (((int64_t)dig_P9) * (p >> 13) * (p >> 13)) >> 25;
	var2 = (((int64_t)dig_P8) * p) >> 19;
	p = ((p + var1 + var2) >> 8) +
	(((int64_t)dig_P7) << 4);

	return (float)p / 25600.0;
}
