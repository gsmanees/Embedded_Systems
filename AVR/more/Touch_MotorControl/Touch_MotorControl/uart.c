/*
 * uart.c
 *
 * Created: 01-11-2025 13:55:56
 *  Author: sreej
 */ 
#include "uart.h"

void UART_Init(unsigned int ubrr)
{
	UBRR0H = (unsigned char)(ubrr >> 8);
	UBRR0L = (unsigned char)ubrr;
	UCSR0B = (1 << RXEN0) | (1 << TXEN0);
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // 8-bit data
}

void UART_TxChar(char data)
{
	while (!(UCSR0A & (1 << UDRE0)));
	UDR0 = data;
}

void UART_TxString(const char *str)
{
	while (*str)
	{
		UART_TxChar(*str++);
	}
}

void UART_TxHex(uint8_t value)
{
	const char hexChars[] = "0123456789ABCDEF";
	char hex[5];
	hex[0] = hexChars[(value >> 4) & 0x0F];
	hex[1] = hexChars[value & 0x0F];
	hex[2] = '\r';
	hex[3] = '\n';
	hex[4] = '\0';
	UART_TxString("0x");
	UART_TxString(hex);
}
void UART_TxNumber(uint32_t num)
{
    char buffer[12];
    ltoa(num, buffer, 10);   // convert to string (long to ASCII)
    UART_TxString(buffer);
}


void UART_Transmit(uint8_t data)
{
	while (!(UCSR0A & (1 << UDRE0)));
	UDR0 = data;
}

uint8_t UART_Read(void)
{
	while (!(UCSR0A & (1 << RXC0)));
	return UDR0;
}
