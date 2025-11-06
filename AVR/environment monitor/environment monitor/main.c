#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"

int main(void)
{
	uint32_t temp;
	uint8_t msb, lsb, xlsb;

	UART_Init();

	// ===== SPI Pin Configuration =====
	DDRB |= (1 << PB3) | (1 << PB5) | (1 << PB2); // MOSI, SCK, SS as outputs
	DDRB &= ~(1 << PB4);                          // MISO as input
	PORTB |= (1 << PB2);                          // SS high initially

	// ===== SPI Setup =====
	SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0); // Enable SPI Master, F_CPU/16

	_delay_ms(100); // allow BMP280 to power up

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

	// ===== Transmit Over UART =====
	while (1)
	{
		UART_TxNumber(temp);
		UART_TxChar('\n');
		_delay_ms(500);
	}
}