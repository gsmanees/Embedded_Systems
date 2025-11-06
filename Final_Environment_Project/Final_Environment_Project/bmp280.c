/*
 * bmp280.c
 *
 * Created: 02-11-2025 8.16.18 PM
 *  Author: anees
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include<util/delay.h>
#include "bmp280.h"

void bmp280_configure(void)
{
	// ===== Configure BMP280 ctrl_meas (0xF4) =====
	PORTB &= ~(1 << PB2);           // CS low
	SPDR = 0xF4 & 0x7F;             // Write address (bit7=0)
	while (!(SPSR & (1 << SPIF)));
	(void)SPDR;

	SPDR = 0x27;                    // Write 0x27 ? normal mode, oversampling x1
	while (!(SPSR & (1 << SPIF)));
	(void)SPDR;
	PORTB |= (1 << PB2);            // CS high
	_delay_ms(100);
}

uint32_t bmp280_readTempRegisters(void)
{
	uint32_t temp;
	uint32_t msb, lsb, xlsb;
	// ===== Read Temperature Registers (0xFA, 0xFB, 0xFC) =====
	PORTB &= ~(1 << PB2);           // CS low

	SPDR = 0xFA | 0x80;             // Read address (bit7=1)
	while (!(SPSR & (1 << SPIF)));
	(void)SPDR;

	// Read MSB
	SPDR = 0x00;
	while (!(SPSR & (1 << SPIF)));
	msb = SPDR;

	// Read LSB
	SPDR = 0x00;
	while (!(SPSR & (1 << SPIF)));
	lsb = SPDR;

	// Read XLSB
	SPDR = 0x00;
	while (!(SPSR & (1 << SPIF)));
	xlsb = SPDR;

	PORTB |= (1 << PB2); // CS high
	
	// ===== Combine 20-bit Temperature Data =====
	temp = ((uint32_t)msb << 12) | ((uint32_t)lsb << 4) | (xlsb >> 4);
	return temp;
}


uint8_t bmp280_readChipID(void)
{
	uint8_t id;
	PORTB &= ~(1 << PB2);
	SPDR = 0xD0 | 0x80;           // Read address
	while (!(SPSR & (1 << SPIF)));
	(void)SPDR;

	SPDR = 0x00;
	while (!(SPSR & (1 << SPIF)));
	id = SPDR;

	
	return id;
	PORTB |= (1 << PB2);
}
