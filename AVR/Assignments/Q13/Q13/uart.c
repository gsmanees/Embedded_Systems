/*
 * uart.c
 *
 * Created: 15-11-2025 7.00.30 AM
 *  Author: anees
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include "uart.h"

void UART_Init(void)
{
	UBRR0H=(UBRR_VALUE>>8);
	UBRR0L = UBRR_VALUE;
	UCSR0B=(1<<RXEN0)|(1<<TXEN0);
	UCSR0C=(1<<UCSZ01)|(1<<UCSZ00);
}

void UART_TxChar(char data)
{
	while(!(UCSR0A&(1<<UDRE0)));
	UDR0=data;
}

char UART_RxChar(void)
{
	while(!(UCSR0A&(1<<RXC0)));
	return UDR0;
}

void UART_TxString(const char *str)
{
	while (*str)
	{
		UART_TxChar(*str++);
	}
}