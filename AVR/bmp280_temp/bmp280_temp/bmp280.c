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

uint32_t MSB;
uint32_t LSB;
uint32_t xLSB;
uint32_t rawTemp=0;

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
	_delay_ms(10);
	
	UART_TxString("\nChip ID: ");
	UART_TxHex(Chip_ID);
	//_delay_ms(1000);
}

void getMSB(void)
{
	
	PORTB&=~(1<<CS); // making CS as LOW to start communication
	SPDR=0xFA|80; // MSB is stored on 0xFA register, ORed with 80 to start read operation from the register
	while(!(SPSR&(1<<SPIF))); // wait until communication complete 
	(void)SPDR; // it will reply the dummy value inside 0xFA
	SPDR=0x00; // writing any value to get the exact value stored on 0xFA register, whioch is MSB
	while(!(SPSR&(1<<SPIF)));
	MSB=SPDR;
	
	PORTB|=(1<<CS); //making CS HIGH for stopping communication
	_delay_ms(10);
	UART_TxString("\nMSB: ");
	UART_TxNumber(MSB);

	//_delay_ms(1000);
	
}


void getLSB(void)
{
	
	PORTB&=~(1<<CS); // making CS as LOW to start communication
	SPDR=0xFB|80; // LSB is stored on 0xFB register, ORed with 80 to start read operation from the register
	
	while(!(SPSR&(1<<SPIF))); // wait until communication complete
	(void)SPDR; // it will reply the dummy value inside 0xFB
	SPDR=0x00; // writing any value to get the exact value stored on 0xFB register, which is LSB
	while(!(SPSR&(1<<SPIF)));
	LSB=SPDR;
	PORTB|=(1<<CS); //making CS HIGH for stopping communication
	_delay_ms(10);
	UART_TxString("\nLSB: ");
	UART_TxNumber(LSB);
	//_delay_ms(1000);
}

void getxLSB(void)
{
	
	PORTB&=~(1<<CS); // making CS as LOW to start communication
	SPDR=0xFC|80; // xLSB is stored on 0xFc register, ORed with 80 to start read operation from the register
	
	while(!(SPSR&(1<<SPIF))); // wait until communication complete
	(void)SPDR; // it will reply the dummy value inside 0xFC
	SPDR=0x00; // writing any value to get the exact value stored on 0xFC register, which is xLSB
	while(!(SPSR&(1<<SPIF)));
	xLSB=SPDR;
	PORTB|=(1<<CS); //making CS HIGH for stopping communication
	_delay_ms(10);
	UART_TxString("\nxLSB: ");
	UART_TxNumber(xLSB);
	//_delay_ms(1000);
}

void getRawTemp(void)
{
	rawTemp=(MSB<<12)|(LSB<<4)|(xLSB>>4);
	UART_TxString("\nRaw Temp: ");
	UART_TxNumber(rawTemp);
}