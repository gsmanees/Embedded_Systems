/*
 * uart_tx_string.c
 *
 * Created: 20-10-2025 6.11.34 AM
 * Author : anees
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>

void uart_init()
{
	UBRR0H=0;
	UBRR0L=103;
	UCSR0B|=(1<<TXEN0);
	UCSR0C|=(1<<UCSZ01)|(1<<UCSZ00);
}

void uart_tx_string(char *str)
{
	for (uint8_t i=0; str[i]!='\0'; i++)
	{
		UDR0=str[i];
		while(!(UCSR0A&(1<<UDRE0)));
	}
}

int main(void)
{
    uart_init();
	uart_tx_string("Anees Kokadan");
    while (1) 
    {
    }
}

