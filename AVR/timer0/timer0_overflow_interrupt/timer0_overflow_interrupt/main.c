/*
 * timer0_overflow_interrupt.c
 *
 * Created: 29-09-2025 8.47.49 PM
 * Author : anees
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint16_t count =0;
ISR (TIMER0_OVF_vect)
{
	if (count>=977)
	{
		PORTB^=(1<<PORTB5);
		count=0;
	}
	count++;
}

int main(void)
{
	sei();
    DDRB|=(1<<DDB5);
	TCCR0A=0;
	TCCR0B|=(1<<CS00)|(1<<CS01);
	TIMSK0|=(1<<TOIE0);
	
	while (1);
}

