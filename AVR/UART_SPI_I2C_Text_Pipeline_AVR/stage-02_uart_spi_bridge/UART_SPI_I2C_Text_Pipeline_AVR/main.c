/*
 * UART_SPI_I2C_Text_Pipeline_AVR.c
 *
 * Created: 23-12-2025 7.20.56 AM
 * Author : anees
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include "uart.h"
#include "spi.h"
#include "lcd.h"

int main(void)
{
	// declarations
	uint8_t message;
	uint16_t newMsg=0;
	
	// drivers initializations
	UART_Init(); // from serial monitor to AVR
	lcd_init(); // for UART to 16x2 LCD echo
	SPI_Init(); // to transmit from Atmega328 to STM32, SPI as master 
	
	// LCD cursor initially set to 0,0
	lcd_set_cursor(0,0);
    while (1) 
    {	
		// receives message from serial monitor
		message=UART_Receive();
		
		// SPI communication
		SPI_SelectSlave(); // makes CS low - starts transmission
		SPI_Master_Transmit(message); // transmit message to STM32
		SPI_DeselectSlave(); // makes CS high - transmission ends

	// printing echo on LCD 
		UART_Transmit(message);
		
		if (message == '\0')        // Enter key (CR)
		{
			newMsg=1;
		}
		else if (message == '\n')   // Line feed
		{
			newMsg=1;
		}
		else
		{
			if (newMsg)
			{
				lcd_clear();
				lcd_set_cursor(0, 0);
				newMsg = 0;
			}
			lcd_data(message);      // print only valid characters
		}	
}
}

