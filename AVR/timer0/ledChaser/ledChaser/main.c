/*
 * ledChaser.c
 *
 * Created: 20-09-2025 10.00.23 PM
 * Author : anees
 LED chaser
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>

void delay_1s()
{
	int i;
	int count=61;
	for(i=0; i<count; i++)
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
	DDRB|=(1<<DDB5)|(1<<DDB4)|(1<<DDB3)|(1<<DDB2);
    while (1) 
    {
		PORTB|=(1<<PORTB5);
		delay_1s();
		PORTB&=~(1<<PORTB5);
		PORTB|=(1<<PORTB4);
		delay_1s();
		PORTB&=~(1<<PORTB4);
		PORTB|=(1<<PORTB3);
		delay_1s();
		PORTB&=~(1<<PORTB3);
		PORTB|=(1<<PORTB2);
		delay_1s();
		
		PORTB&=~(1<<PORTB2);
		PORTB|=(1<<PORTB3);
		delay_1s();
		PORTB&=~(1<<PORTB3);
		PORTB|=(1<<PORTB4);
		delay_1s();
		PORTB&=~(1<<PORTB4);
		PORTB|=(1<<PORTB5);
		
    }
}

