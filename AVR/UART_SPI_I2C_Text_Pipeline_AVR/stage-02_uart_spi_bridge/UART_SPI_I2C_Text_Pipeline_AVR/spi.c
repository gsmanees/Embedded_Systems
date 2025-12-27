/*
 * spi.c
 *
 * Created: 15-11-2025 7.07.03 AM
 *  Author: anees
 * 

 *  Author: anees
 PB2 --> SS
 PB3 --> MOSI  SDA
 PB4 --> MISO  SDO
 PB5 --> SCK
 */

 #define F_CPU 16000000UL
 #include "spi.h"
 #include <avr/io.h>
 #include <util/delay.h>

void SPI_Init(void)
{
	// MOSI, SCK, SS as OUTPUT
	DDRB |= (1 << PB3) | (1 << PB5) | (1 << PB2);

	// MISO as INPUT
	DDRB &= ~(1 << PB4);

	// SS HIGH initially
	PORTB |= (1 << PB2);

	// SPI Enable, Master, Mode 0, F_CPU/16
	SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);

	// Ensure Mode 0 explicitly
	SPCR &= ~((1 << CPOL) | (1 << CPHA));
}

 
 uint8_t SPI_Master_Transmit(uint8_t data)
 {
	 SPDR = data;
	 while (!(SPSR & (1 << SPIF)));
	 return SPDR;


 }
 
 
 void SPI_SelectSlave(void)
 {
	 PORTB &= ~(1 << PB2);   // SS LOW
 }

 void SPI_DeselectSlave(void)
 {
	 PORTB |= (1 << PB2);    // SS HIGH
 }
