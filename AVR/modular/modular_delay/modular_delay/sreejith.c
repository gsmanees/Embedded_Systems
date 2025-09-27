/*
 * sreejith.c
 *
 * Created: 26-09-2025 8.31.01 PM
 *  Author: anees
 */ 
#include <avr/io.h>

void timer0_init(void)
{
	TCNT0=0;
	OCR0A=249;
	TCCR0A|=(1<<WGM01); // CTC mode 
	TCCR0B|=(1<<CS00)|(1<<CS01); // pre scalar 64
	TIFR0|=(1<<OCF0A); // flag cleared
	
}

void anees (uint16_t ms)
{
	timer0_init();
	while (ms--)
	{
		while (!(TIFR0&(1<<OCF0A)))
		{
		}
		TIFR0|=(1<<OCF0A);
	}
}