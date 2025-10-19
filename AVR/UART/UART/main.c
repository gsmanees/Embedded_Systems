/*
 * UART.c
 *
 * Created: 18-10-2025 6.42.32 AM
 * Author : anees
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>



int main(void)
{
    // setting baud rate to 9600
	UBRR0H=0;
	UBRR0L=103;
	
	// tx enable 
	UCSR0B|=(1<<TXEN0);
	
	// 8 bit setting
	UCSR0C|=(1<<UCSZ00)|(1<<UCSZ01);
	
	// clearing UDR0 register 
	UDR0=0;
	
	unsigned char str[]="Anees Kokadan";
	
    while (1) 
    {
		for (uint8_t i=0; str[i]!='\0'; i++)
		{
			UDR0=str[i];
			while(!(UCSR0A&(1<<UDRE0)));
			//UDR0=0;
		}
		
		UDR0='\n';
		
		_delay_ms(1000);
		
    }
}

