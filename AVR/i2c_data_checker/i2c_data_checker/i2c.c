/*
 * i2c.c
 *
 * Created: 03-06-2026 02:24:06 PM
 *  Author: anees
 */ 




#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
/* ---------------- I2C ---------------- */

void I2C_Init(void)
{
	TWSR = 0x00;

	TWBR = 72;          // 100kHz

	TWCR = (1 << TWEN);
}

void I2C_Start(void)
{
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);

	while (!(TWCR & (1 << TWINT)));
}

void I2C_Stop(void)
{
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);

	_delay_ms(1);
}

void I2C_Write(uint8_t data)
{
	TWDR = data;

	TWCR = (1 << TWINT) | (1 << TWEN);

	while (!(TWCR & (1 << TWINT)));
}