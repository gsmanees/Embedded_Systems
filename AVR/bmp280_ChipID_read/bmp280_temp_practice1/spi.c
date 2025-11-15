/*
 * spi.c
 *
 * Created: 15-11-2025 7.07.03 AM
 *  Author: anees
 * 

 *  Author: anees
 PB2 --> SS
 PB3 --> MOSI
 PB4 --> MISO
 PB5 --> SCK
 */

 #define F_CPU 16000000UL
 #include "spi.h"
 #include <avr/io.h>
 #include <util/delay.h>

 void SPI_init(void)
 {
 DDRB |= (1 << PB3) | (1 << PB5) | (1 << PB2); // MOSI, SCK, SS as outputs
 DDRB &= ~(1 << PB4);                           // MISO as input
 PORTB |= (1 << PB2);                           // SS high initially
 DDRD|=(1<<PD3);
 // ===== SPI SETUP =====
 SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0); // Enable SPI Master

 _delay_ms(10); // allow BMP280 to power up
 }