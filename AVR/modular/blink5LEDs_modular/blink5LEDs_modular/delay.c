/*
 * delay.c
 *
 * Created: 29-09-2025 6.29.40 AM
 *  Author: anees
 */ 

#include <avr/io.h>

void timer0_init()
{
	TCNT0=0;
	OCR0A=249;
	TCCR0A|=(1<<WGM01); //ctc
	TCCR0B|=(1<<CS00)|(1<<CS02); // prescalar 1024
	TIFR0|=(1<<OCF0A);
	
}


void delay_2s()
{
	int i;
	
	timer0_init();
	
	
	{
	
		for (i=0; i<122; i++)
		{
			while (!(TIFR0&(1<<OCF0A)));
			TIFR0|=(1<<OCF0A);
		}
		
		
	}
	
}