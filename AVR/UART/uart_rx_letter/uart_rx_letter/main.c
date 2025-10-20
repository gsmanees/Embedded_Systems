/*
 * uart_rx_letter.c
 *
 * Created: 20-10-2025 6.21.27 AM
 * Author : anees
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>

void uart_init(unsigned long baud)
{
	unsigned int regVal=0;
	UCSR0A|=(1<<U2X0); // if not used , makes error for higher baud rates
	regVal = (F_CPU/(8UL*baud))-1; // UL used for 32 bit unsigned long 
	UBRR0H= (regVal>>8); // to get the higher byte
	UBRR0L=  regVal;
	
	UCSR0B|=(1<<RXEN0)|(1<<TXEN0); // rx and tx enabling 
	
	UCSR0C|=(1<<UCSZ01)|(1<<UCSZ00); // 8 bit transfer mode 
}

char uart_rx_letter()
{
	
	while(!(UCSR0A&(1<<RXC0))); // waits until receiving completes
	return UDR0;
}

void uart_tx_string(char *str)
{
	for (uint8_t i=0; str[i]!='\0'; i++)
	{
		UDR0=str[i];
		while(!(UCSR0A&(1<<UDRE0))); // waiting until uart data register empty
	}
}

void uart_tx_char(char c)
{
	
	UDR0=c;
	while(!(UCSR0A&(1<<TXC0))); // waits until transmission completes
}

int main(void)
{
	char c_rx;
	uart_init(9600);
	uart_tx_string("\nEnter a letter: ");
	c_rx=uart_rx_letter();
	uart_tx_string("\nYou entered: ");
	uart_tx_char(c_rx);
    
    while (1) 
    {
    }
}

