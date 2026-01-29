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

void UART_TxFloat(float value, uint8_t decimalPlaces)
{
	int intPart;
	int fracInt;
	float scale = 1.0f;

	// handle sign
	if (value < 0)
	{
		UART_TxChar('-');
		value = -value;
	}

	// scale for decimals
	for (uint8_t i = 0; i < decimalPlaces; i++)
	scale *= 10.0f;

	// rounding
	value += 0.5f / scale;

	intPart = (int)value;
	fracInt = (int)((value - intPart) * scale);

	// print integer part
	UART_TxNumber(intPart);
	UART_TxChar('.');

	// print fractional part with leading zeros
	for (int i = decimalPlaces - 1; i >= 0; i--)
	{
		int divisor = 1;
		for (int j = 0; j < i; j++)
		divisor *= 10;

		UART_TxChar((fracInt / divisor) % 10 + '0');
	}
}


void UART_printTime(void)
{
			UART_TxNumber(hh);
			UART_TxString(":");
			UART_TxNumber(mm);
			UART_TxString(":");
			UART_TxNumber(ss);
			UART_TxString("\r\n");
}


void UART_printDate(void)
{
			UART_TxNumber(dd);
			UART_TxString(":");
			UART_TxNumber(mon);
			UART_TxString(":");
			UART_TxNumber(yy);
			UART_TxString("\r\n");
}