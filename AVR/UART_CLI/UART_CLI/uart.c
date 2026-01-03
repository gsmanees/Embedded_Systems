/*
 * uart.c
 *
 * Created: 02-01-2026 9.50.39 PM
 *  Author: anees
 */ 

#include "uart.h"
#include <avr/io.h>
#include "global.h"


void UART_Init(void)
{
	uint16_t ubrr = 103;               // 9600 baud @16MHz
	UBRR0H = ubrr >> 8;
	UBRR0L = ubrr;

	UCSR0B = (1<<RXEN0) | (1<<TXEN0) | (1<<RXCIE0);
	UCSR0C = (1<<UCSZ01) | (1<<UCSZ00);
}

void UART_TxChar(char c)
{
	while (!(UCSR0A & (1<<UDRE0)));
	UDR0 = c;
}

void UART_TxString(const char *s)
{
	while (*s) UART_TxChar(*s++);
}