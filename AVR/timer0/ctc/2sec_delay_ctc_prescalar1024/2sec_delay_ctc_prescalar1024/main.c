/*
 * 2sec_delay_ctc_prescalar1024.c
 *
 * Created: 20-09-2025 7.17.50 AM
 * Author : anees
 CTC mode
 dlelay: 2 sec 
 prescalar: 1024
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>

void delay_2sec()
{
	int i;
	int count=122;
	TCNT0=0;
	TCCR0A|=(1<<WGM00); // ctc mode selected
	TCCR0B|=(1<<CS00);
	TCCR0B|=(1<<CS02); // prescalar 1024 selected
	TIFR0|=(1<<OCF0A); // flag reset
	OCR0A=200;
	for (i=0; i<count; i++)
	{
		while (!(TIFR0&(1<<OCF0A)));
		TIFR0|=(1<<OCF0A);
	}
}

int main(void)
{
    DDRB|=(1<<DDB5);
    while (1) 
    {
		PORTB^=(1<<PORTB5);
		delay_2sec();
    }
}

