/*
 * UART_SPI_I2C_Text_Pipeline_AVR.c
 *
 * Created: 23-12-2025 7.20.56 AM
 * Author : anees
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"
#include "spi.h"
#include "lcd.h"

int main(void)
{
	UART_Init();
	lcd_init();
	
	uint8_t message;
	uint16_t newMsg;
	
	lcd_set_cursor(0,0);
    while (1) 
    {
		
		
		message=UART_Receive();
		UART_Transmit(message);
		
		//lcd_clear();
		
		
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

