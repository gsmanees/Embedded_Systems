/*
 * delay_both_normal_ctc.c
 *
 * Created: 20-09-2025 7.58.31 PM
 * Author : anees
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>

void delay_normal()
{
	int i;
	int count=61;
	
	for (i=0; i<count; i++)
	{
		TCNT0=0;
		TCCR0A=0;
		TCCR0B|=(1<<CS00);
		TCCR0B|=(1<<CS02); // prescalar 1024 used
		TIFR0|=(1<<TOV0); // flag reset
		while(!(TIFR0&(1<<TOV0)));
	}
}


void delay_ctc()
{
	int i=0;
	int count=61;
	
	
	for (i=0; i<count; i++)
	{
		TCNT0=0;
		TCCR0A|=(1<<WGM01); // ctc used
		TCCR0B|=(1<<CS00);
		TCCR0B|=(1<<CS02); // prescalar 1024 used
		TIFR0|=(1<<OCF0A); // flag reset
		OCR0A=200;
		while (!(TIFR0&(1<<OCF0A)));
		
	}
}

int main(void)
{
	DDRB|=(1<<DDB5);
	DDRB|=(1<<DDB4);
	while (1)
	{
		PORTB|=(1<<PORTB5);
		delay_normal();
		PORTB&=~(1<<PORTB5);
		delay_normal();
		PORTB|=(1<<PORTB4);
		delay_ctc();
		PORTB&=~(1<<PORTB4);
		delay_ctc();
	}
}
