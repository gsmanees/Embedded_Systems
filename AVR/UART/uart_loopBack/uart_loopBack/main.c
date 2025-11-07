/*
 * uart_loopBack.c
 *
 * Created: 06-11-2025 10.17.04 PM
 * Author : anees
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void UART_Init(void)
{
	uint16_t ubrr = 103; // 9600 baud @16MHz
	UBRR0H = (ubrr >> 8);
	UBRR0L = ubrr;
	UCSR0B = (1 << RXEN0) | (1 << TXEN0);
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // 8-bit data
}

void UART_Transmit(uint8_t data)
{
	while (!(UCSR0A & (1 << UDRE0)));  // Wait for buffer empty
	UDR0 = data;                       // Send data
	
}

uint8_t UART_Receive(void)
{
	while (!(UCSR0A & (1 << RXC0)));   // Wait for received data
	return UDR0;                       // Return received byte
	
}

int main(void)
{
	DDRB |= (1 << PB5); // LED pin (Arduino pin 13)
	UART_Init();

	while (1)
	{
		uint8_t data = UART_Receive();  // Wait for a byte
		UART_Transmit(data);            // Send it back (echo)
		PORTB ^= (1 << PB5);            // Toggle LED to show activity

	}
}


