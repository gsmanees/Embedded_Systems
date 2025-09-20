/*
 * timer0_ctc.c
 *
 * Created: 19-09-2025 8.32.14 PM
 * Author : anees
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>


int main(void)
{
    DDRB|=(1<<DDB5);
	TCNT0=0;
	
	TCCR0A|=(1<<WGM00); // CTC 
	OCR0A=200; // set point 
	TCCR0B|=(1<<CS00); // no pre scalar used, uses system clock 16mhz
	TIFR0|=(1<<OCF0A); // reset flag
	
	
	
	
    while (1) 
    {
		PORTB^=(1<<PORTB5);
		for (long int i=0; i<160000; i++)
		{
			while (!(TIFR0&(1<<OCF0A)))
			{
				
			}
			TIFR0|=(1<<OCF0A);
		}
		
	}
}

