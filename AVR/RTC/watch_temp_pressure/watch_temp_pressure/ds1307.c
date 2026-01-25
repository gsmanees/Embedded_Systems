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


void DS1307_ReadTime(uint8_t *hh, uint8_t *mm, uint8_t *ss)
{
	uint8_t sec_raw, min_raw, hour_raw;

	// Select starting register: seconds (0x00)
	TWI_Start();
	TWI_Write(0x68 << 1);   // DS1307 write
	TWI_Write(0x00);        // Start from seconds register

	// Switch to read mode
	TWI_Start();
	TWI_Write((0x68 << 1) | 1); // DS1307 read

	sec_raw  = TWI_Read_ACK();   // seconds
	min_raw  = TWI_Read_ACK();   // minutes
	hour_raw = TWI_Read_NACK();  // hours

	TWI_Stop();

	// Convert BCD to decimal
	*ss = BCD_to_DEC(sec_raw & 0x7F); // mask CH
	*mm = BCD_to_DEC(min_raw);
	
	*hh = BCD_to_DEC(hour_raw & 0x3F); // 24-hour mode
}


uint8_t DEC_to_BCD(uint8_t dec)
{
	return ((dec / 10) << 4) | (dec % 10);
}


void DS1307_SetTime(uint8_t hh, uint8_t mm, uint8_t ss)
{
	TWI_Start();
	TWI_Write(0x68 << 1);   // DS1307 I2C address + WRITE
	TWI_Write(0x00);        // Start at seconds register

	// Seconds (clear CH bit explicitly)
	TWI_Write(DEC_to_BCD(ss) & 0x7F);

	// Minutes
	TWI_Write(DEC_to_BCD(mm));

	// Hours (24-hour mode)
	TWI_Write(DEC_to_BCD(hh) & 0x3F);

	TWI_Stop();
}


void DS1307_ReadTimeDate(uint8_t *hh, uint8_t *mm, uint8_t *ss,
uint8_t *dd, uint8_t *mon, uint8_t *yy)
{
	uint8_t sec_raw, min_raw, hour_raw;
	uint8_t date_raw, month_raw, year_raw;

	TWI_Start();
	TWI_Write(0x68 << 1);   // DS1307 write
	TWI_Write(0x00);        // start from seconds

	TWI_Start();
	TWI_Write((0x68 << 1) | 1); // DS1307 read

	sec_raw   = TWI_Read_ACK();   // 0x00
	min_raw   = TWI_Read_ACK();   // 0x01
	hour_raw  = TWI_Read_ACK();   // 0x02
	TWI_Read_ACK();               // 0x03 (day of week) – ignore
	date_raw  = TWI_Read_ACK();   // 0x04
	month_raw = TWI_Read_ACK();   // 0x05
	year_raw  = TWI_Read_NACK();  // 0x06

	TWI_Stop();

	*ss  = BCD_to_DEC(sec_raw & 0x7F);
	*mm  = BCD_to_DEC(min_raw);
	*hh  = BCD_to_DEC(hour_raw & 0x3F);
	*dd  = BCD_to_DEC(date_raw);
	*mon = BCD_to_DEC(month_raw & 0x1F);
	*yy  = BCD_to_DEC(year_raw);
}

void DS1307_SetDate(uint8_t dd, uint8_t mm, uint8_t yy)
{
	TWI_Start();
	TWI_Write(0x68 << 1);   // DS1307 write
	TWI_Write(0x04);        // Date register

	TWI_Write(DEC_to_BCD(dd));        // Day (1–31)
	TWI_Write(DEC_to_BCD(mm));        // Month (1–12)
	TWI_Write(DEC_to_BCD(yy));        // Year (00–99)

	TWI_Stop();
}
