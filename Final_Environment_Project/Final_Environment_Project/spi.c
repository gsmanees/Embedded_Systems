/*
 * spi.c
 *
 * Created: 02-11-2025 8.09.33 PM
 *  Author: anees
 */ 

#define F_CPU 16000000UL
#include "spi.h"
#include <avr/io.h>
#include <util/delay.h>


void spi_init(void)
{
	// ===== SPI Pin Configuration =====
	DDRB |= (1 << PB3) | (1 << PB5) | (1 << PB2); // MOSI, SCK, CS as outputs
	DDRB &= ~(1 << PB4);                          // MISO as input
	PORTB |= (1 << PB2);                          // CS high initially

	// ===== SPI Setup =====
	SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0); // Enable SPI, Master, F_CPU/16
	SPSR &= ~(1 << SPI2X);                         // Ensure normal speed (not double)

	// Clear any pending flags
	uint8_t dummy = SPSR;
	dummy = SPDR;

	_delay_ms(2); // Allow BMP280 to power up
}

