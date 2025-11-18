/*
 * bmp280_temp.c
 *
 * Created: 16-11-2025 11.22.07 PM
 * Author : anees
 -----------------------------------------------------------------------
 this program reads the raw temperature from bmp280
 Address     Register Name   Function
 0xFA		 TEMP_MSB		 Temperature bits [19:12]
 0xFB		 TEMP_LSB		 Temperature bits [11:4]
 0xFC		 TEMP_XLSB		 Temperature bits [3:0] (upper nibble)
------------------------------------------------------------------------

 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "spi.h" // to communicate with bmp280, SPI protocol
#include "uart.h" // to print the value on serial monitor, UART protocol
#include "bmp280.h" // bmp codes are added here
#include "lcd.h"

int main(void)
{
	SPI_init();
	UART_Init();
	lcd_init();
	
    
    while (1) 
    {
		getChip_ID();
		getMSB();
		getLSB();
		getxLSB();
		getRawTemp();
		ctrl_meas();
		get_dig_T1();
		get_dig_T2();
		get_dig_T3();
		realTemp();
		
		
		_delay_ms(1000);
    }
}

