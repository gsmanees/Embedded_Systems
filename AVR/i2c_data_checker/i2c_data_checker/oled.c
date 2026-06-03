/*
 * oled.c
 *
 * Created: 03-06-2026 02:25:44 PM
 *  Author: anees
 */ 

#define F_CPU 16000000UL
#include "i2c.h"
/* ---------------- OLED ---------------- */

#define OLED_ADDR 0x3C

void OLED_Command(uint8_t cmd)
{
	I2C_Start();

	I2C_Write(OLED_ADDR << 1);

	I2C_Write(0x00);

	I2C_Write(cmd);

	I2C_Stop();
}

void OLED_Data(uint8_t data)
{
	I2C_Start();

	I2C_Write(OLED_ADDR << 1);

	I2C_Write(0x40);

	I2C_Write(data);

	I2C_Stop();
}

void OLED_Init(void)
{
	_delay_ms(100);

	OLED_Command(0xAE);
	OLED_Command(0x20);
	OLED_Command(0x00);
	OLED_Command(0xAF);
}
