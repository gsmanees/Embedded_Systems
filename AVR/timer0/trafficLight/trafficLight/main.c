/*
 * trafficLight.c
 *
 * Created: 20-09-2025 8.16.47 PM
 * Author : anees
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>

void delay_10s()
{
	int i;
	int count=610;
	
	
	for (i=0; i<count; i++)
	{
		TCNT0=0;
		TCCR0A=0;
		TCCR0B|=(1<<CS00)|(1<<CS02); // prescalar 1024
		TIFR0|=(1<<TOV0);
		while (!(TIFR0&(1<<TOV0)));
	}
	
}

void delay_3s()
{
	int i;
	int count=183;
	
	
	for (i=0; i<count; i++)
	{
		TCNT0=0;
		TCCR0A=0;
		TCCR0B|=(1<<CS00)|(1<<CS02); // prescalar 1024
		TIFR0|=(1<<TOV0);
		while (!(TIFR0&(1<<TOV0)));
	}
}

int main(void)
{
	DDRB|=(1<<DDB5)|(1<<DDB4)|(1<<DDB3);
	
	while (1)
	{
		PORTB|=(1<<PORTB5); //red
		delay_10s();
		PORTB&=~(1<<PORTB5);
		PORTB|=(1<<PORTB4); // yellow
		delay_3s();
		PORTB&=~(1<<PORTB4);
		PORTB|=(1<<PORTB3);
		delay_10s();
		PORTB&=~(1<<PORTB3);
		
	}
}
