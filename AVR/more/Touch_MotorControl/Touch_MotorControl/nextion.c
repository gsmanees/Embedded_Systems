/*
 * nextion.c
 *
 * Created: 05-11-2025 8.34.33 PM
 *  Author: anees
 */ 

#include <avr/io.h>
#include "nextion.h"
#include "uart.h"

void Nextion_SendString(char *str)
{
	while (*str)
	{
		UART_Transmit(*str++);
	}
	// Every Nextion command must end with 3 bytes: 0xFF 0xFF 0xFF
	UART_Transmit(0xFF);
	UART_Transmit(0xFF);
	UART_Transmit(0xFF);
}