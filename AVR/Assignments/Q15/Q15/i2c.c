/*
 * i2c.c
 *
 * Created: 18-05-2026 6.02.20 AM
 *  Author: anees
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "i2c.h"
#include "global.h"

void I2C_Init(void)
{
	TWSR=0x00;
	TWBR=72;
}

void I2C_Start(void)
{
	TWCR=(1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while(!(TWCR&(1<<TWINT)));
}

void I2C_Stop(void)
{
	TWCR=(1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
	_delay_us(10);
}

void I2C_Write(uint8_t data)
{
	TWDR=data;
	TWCR=(1<<TWINT)|(1<<TWEN);
	while(!(TWCR&(1<<TWINT)));
}

uint8_t I2C_Read_ACK(void)
{
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while(!(TWCR&(1<<TWINT)));
	return TWDR;
}

uint8_t I2C_Read_NACK(void)
{
	TWCR=(1<<TWINT)|(1<<TWEN);
	while(!(TWCR&(1<<TWINT)));
	return TWDR;
}