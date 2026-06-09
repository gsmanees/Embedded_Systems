/*
 * i2c.c
 *
 * Created: 28-12-2025 8.31.44 AM
 *  Author: anees
 */ 

#define F_CPU 16000000UL
#include<avr/io.h>
#include "i2c.h"

void I2C_Init(void)
{
	TWSR = 0x00;       // Prescaler = 1
	TWBR = 72;         // 100kHz @ 16MHz
	TWCR = (1<<TWEN);  // Enable TWI
}

void I2C_Start(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
}

void I2C_Stop(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}

void I2C_Write(uint8_t data)
{
	TWDR = data;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
}
