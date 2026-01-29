/*
 * i2c.c
 *
 * Created: 22-01-2026 7.22.39 AM
 *  Author: anees
 */ 
#include "i2c.h"
#include <avr/io.h>
#include <stdint.h>

void TWI_Init(void)
{
	TWSR = 0x00;     // Prescaler = 1
	TWBR = 72;       // 100kHz @16MHz
}

void TWI_Start(void)
{
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
	while (!(TWCR & (1 << TWINT)));
}

void TWI_Stop(void)
{
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
}

void TWI_Write(uint8_t data)
{
	TWDR = data;
	TWCR = (1 << TWINT) | (1 << TWEN);
	while (!(TWCR & (1 << TWINT)));
}

uint8_t TWI_Read_NACK(void)
{
	TWCR = (1 << TWINT) | (1 << TWEN);
	while (!(TWCR & (1 << TWINT)));
	return TWDR;
}

uint8_t TWI_Read_ACK(void)
{
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
	while (!(TWCR & (1 << TWINT)));
	return TWDR;
}
