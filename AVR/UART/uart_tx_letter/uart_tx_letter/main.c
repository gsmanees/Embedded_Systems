/*
 * uart_tx_letter.c
 *
 * Created: 19-10-2025 11.50.09 PM
 * Author : anees
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>

void uart_init()
{
	// init baud 9600
	UBRR0H=0;
	UBRR0L=103;
	UCSR0B|=(1<<TXEN0); //TX ENABLE
	UCSR0C|=(1<<UCSZ01)|(1<<UCSZ00); // 8 BIT MODE
}

void uart_tx_char(char c)
{
	
	UDR0=c;
	while(!(UCSR0A&(1<<TXC0)));
}

int main(void)
{
    uart_init();
	uart_tx_char('a');
    while (1) 
    {
    }
}

