/*
 * uart_rx_letter.c
 *
 * Created: 20-10-2025 6.21.27 AM
 * Author : anees
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>

void uart_init()
{
	UBRR0H=0;
	UBRR0L=103;
	
	UCSR0B|=(1<<RXEN0)|(1<<TXEN0);
	
	UCSR0C|=(1<<UCSZ01)|(1<<UCSZ00);
}

char uart_rx_letter()
{
	
	while(!(UCSR0A&(1<<RXC0)));
	return UDR0;
}

void uart_tx_string(char *str)
{
	for (uint8_t i=0; str[i]!='\0'; i++)
	{
		UDR0=str[i];
		while(!(UCSR0A&(1<<UDRE0)));
	}
}

void uart_tx_char(char c)
{
	
	UDR0=c;
	while(!(UCSR0A&(1<<TXC0)));
}

int main(void)
{
	char c_rx;
	uart_init();
	uart_tx_string("\nEnter a letter: ");
	c_rx=uart_rx_letter();
	uart_tx_string("\nYou entered: ");
	uart_tx_char(c_rx);
    
    while (1) 
    {
    }
}

