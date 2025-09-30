/*
 * timer0_overflowInterrupt_ctcMode.c
 *
 * Created: 30-09-2025 6.19.00 AM
 * Author : anees
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
int count=0;

ISR (TIMER0_COMPA_vect)
{
	if (count>=62)
	{
		PORTB^=(1<<PORTB5);
		count=0;
	}
	count++;
}


int main(void)
{
    DDRB|=(1<<DDB5);
	OCR0A=247;
	TCCR0A|=(1<<WGM01); // ctc 
	TCCR0B|=(1<<CS00)|(1<<CS02); // prescalar 1024
	sei();
	TIMSK0|=(1<<OCIE0A);
    while (1) 
    {
    }
}

