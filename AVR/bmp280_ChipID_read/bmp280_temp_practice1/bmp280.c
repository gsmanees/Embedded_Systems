/*
 * bmp280.c
 *
 * Created: 15-11-2025 7.40.24 AM
 *  Author: anees
 */ 

#define F_CPU 16000000UL
#include "bmp280.h"
#include <util/delay.h>
#include <avr/io.h>
#include "uart.h"
#include "spi.h"


void getChip_ID(void)
{
	uint8_t Chip_ID;
	// first reading chip ID
	PORTB&=~(1<<CS); // CS select
	
	// we need to read the register of chip ID which is 0xD0
	// to read a resister we need to OR the register address with MSB1 (ie; OR with 80)
	SPDR=0xD0|0x80;
	while(!(SPSR&(1<<SPIF)));
	(void)SPDR; // getting garbage from bmp280 chip id register
	
	SPDR=0x00; // sending any value to get chip ID from bmp280
	while(!(SPSR&(1<<SPIF)));
	Chip_ID=SPDR;
	// now we need to deselect CS, if not deselected, chip ID will not get, instead we will get 0x00
	// after de selecting CS, we will get chip id as 0x58 as per data sheet
	
	PORTB|=(1<<CS); // communication stops while we de select CS
	UART_TxHex(Chip_ID);
	_delay_ms(1000);
}