/*
 * uart.c
 *
 * Created: 22-01-2026 7.21.27 AM
 *  Author: anees
 */ 
#include "uart.h"
#include <avr/io.h>

void UART_Init(void)
{
	uint16_t ubrr = 103;   // 9600 baud @16MHz

	UBRR0H = (ubrr >> 8);
	UBRR0L = ubrr;

	UCSR0B = (1 << TXEN0);                       // Enable TX
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);      // 8-bit data
}

void UART_TxChar(char c)
{
	while (!(UCSR0A & (1 << UDRE0)));
	UDR0 = c;
}

void UART_TxString(const char *s)
{
	while (*s)
	{
		UART_TxChar(*s++);
	}
}

void UART_TxNumber(uint8_t num)
{
	UART_TxChar((num / 10) + '0');
	UART_TxChar((num % 10) + '0');
}