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
int16_t dig_T1, dig_T2, dig_T3; // if used uint instead of int, twmperature reading will be slightly high 
								// for 30 it will show 37
float rawTemp_float, var1, var2, T, t_fine;

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
	
	/*
	UART_TxString("\nChip ID: ");
	UART_TxHex(Chip_ID);
	UART_TxString("\r\n");
	*/
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
	/*
	UART_TxString("MSB: ");
	UART_TxNumber(MSB);
	UART_TxString("\r\n");
	*/
	
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
	/*
	UART_TxString("LSB: ");
	UART_TxNumber(LSB);
	UART_TxString("\r\n");
	*/
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
	/*
	UART_TxString("xLSB: ");
	UART_TxNumber(xLSB);
	UART_TxString("\r\n");
	*/
}

void getRawTemp(void)
{
	rawTemp=(uint32_t)(MSB<<12)|(uint32_t)(LSB<<4)|(uint32_t)(xLSB>>4);
	/*
	UART_TxString("\nRaw Temp: ");
	UART_TxNumber(rawTemp);
	UART_TxString("\r\n");
	*/
}


// Get Temperature Compensation values 
/*
Constant	Address (LSB)	Address (MSB)	Data type	Bits	Example value
dig_T1		0x88			0x89			uint16_t	16		27504
dig_T2		0x8A			0x8B			uint16_t	16		26435
dig_T3		0x8C			0x8D			uint16_t	16		-1000

*/

// finding dig_T1
void get_dig_T1(void)
{
	uint16_t dig_T1_lsb, dig_T1_msb;
	PORTB&=~(1<<CS); // start communication
	
	SPDR=0x88|0x80;
	while(!(SPSR&(1<<SPIF)));
	(void)SPDR;
	
	SPDR=0x00;
	while(!(SPSR&(1<<SPIF)));
	dig_T1_lsb=SPDR;
	
	SPDR=0x00;
	while(!(SPSR&(1<<SPIF)));
	dig_T1_msb=SPDR;
	
	PORTB|=(1<<CS); // stop communication
	
	// combine msb and lsb to get 16 bit dig_T1 value 
	dig_T1=(uint16_t)(dig_T1_msb<<8)|(dig_T1_lsb);
	/*
	UART_TxString("dig_T1: ");
	UART_TxNumber(dig_T1);
	UART_TxString("\r\n");
	*/
}



// finding dig_T2
void get_dig_T2(void)
{
	uint16_t dig_T2_msb, dig_T2_lsb;
	PORTB&=~(1<<CS);// start
	
	SPDR=0x8A|0x80;
	while(!(SPSR&(1<<SPIF)));
	(void)SPDR;
	
	SPDR=0x00;
	while(!(SPSR&(1<<SPIF)));
	dig_T2_lsb=SPDR;
	
	SPDR=0x00;
	while(!(SPSR&(1<<SPIF)));
	dig_T2_msb=SPDR;
	
	PORTB|=(1<<CS); // stop
	
	// combine msb and lsb to get 16 bit dig_T2 value 
	dig_T2=(uint16_t)(dig_T2_msb<<8)|(dig_T2_lsb);
	/*
	UART_TxString("dig_T2: ");
	UART_TxNumber(dig_T2);
	UART_TxString("\r\n");
	*/
}


// finding dig_T3
void get_dig_T3(void)
{
	uint16_t dig_T3_lsb, dig_T3_msb;
	PORTB&=~(1<<CS);  // start
	
	SPDR=0x8C|0x80;
	while(!(SPSR&(1<<SPIF)));
	(void)SPDR;
	
	SPDR=0x00;
	while(!(SPSR&(1<<SPIF)));
	dig_T3_lsb=SPDR;
	
	SPDR=0x00;
	while(!(SPSR&(1<<SPIF)));
	dig_T3_msb=SPDR;
	
	PORTB|=(1<<CS);  // stop
	
	// combine msb and lsb to get 16 bit dig_T3 value 
	dig_T3=(uint16_t)(dig_T3_msb<<8)|(dig_T3_lsb);
	/*
	UART_TxString("dig_T3: ");
	UART_TxNumber(dig_T3);
	UART_TxString("\r\n");
	*/
}


void ctrl_meas(void)
{
	uint16_t ctrl_meas;
	// ctrl_meas register is 0xF4, we need to write 0x27 to this register 
	PORTB&=~(1<<CS);
	// configure reg for writing, ie we need to AND with 7F
	
	SPDR=0xF4 & 0x7F; // ctrl_meas writing mode
	while(!(SPSR&(1<<SPIF)));
	(void)SPDR;
	
	SPDR=0x27;
	while(!(SPSR&(1<<SPIF)));
	(void)SPDR;
	PORTB|=(1<<CS);
	
	// check ctrl_meas
	PORTB&=~(1<<CS);
	SPDR=0xF4|0x80; // ctrl_meas reading mode 
	while(!(SPSR&(1<<SPIF)));
	(void)SPDR;
	
	SPDR=0x00;
	while(!(SPSR&(1<<SPIF)));
	ctrl_meas=SPDR;
	PORTB|=(1<<CS);
	/*
	UART_TxString("ctrl_meas: ");
	UART_TxHex(ctrl_meas);
	UART_TxString("\r\n");
	*/
}

void realTemp(void)
{
	// T = t_fine / 5120.0
	// t_fine = var1+var2
	// var1= ( (rawTemp_float/16384.0) - (dig_T1/1024.0) )* dig_T2
	// var2 =  ((rawTemp_float/131072.0) - (dig_T2/8192.0))* dig_T3
	
	
	 rawTemp_float = (float) rawTemp;
	 var1=(((rawTemp_float/16384.0f)-((float)dig_T1/1024.0f))*(float)dig_T2);
	 var2 =  ((rawTemp_float/131072.0f) - (dig_T2/8192.0f))* dig_T3;
	 /*var2 = (((rawTemp_float/131072.0f) - ((float)dig_T1/8192.0f)) *
	 ((rawTemp_float/131072.0f) - ((float)dig_T1/8192.0f))) *
	 (float)dig_T3;*/
;

	 t_fine = var1+var2;
	 T = t_fine/5120.0f;
	 UART_TxString("Real time room temperature: ");
	 UART_TxFloat(T, 2);
	 UART_TxString(" C");
	 UART_TxString("\r\n");
	 
	
}