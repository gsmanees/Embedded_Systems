/*
 * ds1307.c
 *
 * Created: 22-01-2026 7.25.20 AM
 *  Author: anees
 */ 
#include "ds1307.h"
#include "i2c.h"

uint8_t BCD_to_DEC(uint8_t bcd)
{
	return ((bcd >> 4) * 10) + (bcd & 0x0F);
}

uint8_t DS1307_ReadSeconds(void)
{
	uint8_t sec;

	TWI_Start();
	TWI_Write(0x68 << 1);   // DS1307 write address, left shifting by 1 to make 8 bit data(write mode=0)
	TWI_Write(0x00);        // Seconds register

	TWI_Start();
	TWI_Write((0x68 << 1) | 1);  // DS1307 read address (Read mode =1)

	sec = TWI_Read_NACK();
	TWI_Stop();

	return sec;
}

void DS1307_StartClock(void)
{
	uint8_t sec;

	// Read current seconds
	TWI_Start();
	TWI_Write(0x68 << 1);   // write mode
	TWI_Write(0x00);        // seconds register

	TWI_Start();
	TWI_Write((0x68 << 1) | 1); // read mode
	sec = TWI_Read_NACK();
	TWI_Stop();

	// Clear CH bit (bit7)
	sec &= 0x7F;

	// Write back seconds with CH = 0
	TWI_Start();
	TWI_Write(0x68 << 1);   // write mode
	TWI_Write(0x00);        // seconds register
	TWI_Write(sec);
	TWI_Stop();
}