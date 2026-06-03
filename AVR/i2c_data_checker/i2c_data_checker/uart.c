/*
 * uart.c
 *
 * Created: 03-06-2026 02:22:19 PM
 *  Author: anees
 */ 
/* ---------------- UART ---------------- */

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>


void UART_Init(void)
{
	uint16_t ubrr = 103; // 9600 baud @16MHz

	UBRR0H = (ubrr >> 8);
	UBRR0L = ubrr;

	UCSR0B = (1 << RXEN0) | (1 << TXEN0);

	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

char UART_RxChar(void)
{
	while (!(UCSR0A & (1 << RXC0)));
	return UDR0;
}

void UART_TxChar(char data)
{
	while (!(UCSR0A & (1 << UDRE0)));
	UDR0 = data;
}
