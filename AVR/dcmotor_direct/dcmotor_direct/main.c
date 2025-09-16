/*
 * dcmotor_direct.c
 *
 * Created: 16-09-2025 5.57.54 AM
 * Author : anees
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void CW(){
	PORTB|=(1<<PORTB5);
	PORTB&=~(1<<PORTB4);
	_delay_ms(3000);
}

void STP(){
	PORTB&=~(1<<PORTB5);
	PORTB&=~(1<<PORTB4);
	_delay_ms(1000);
}

void CCW(){
	PORTB&=~(1<<PORTB5);
	PORTB|=(1<<PORTB4);
	_delay_ms(3000);
}

int main(void)
{
	
	DDRB|=(1<<5);
	DDRB|=(1<<4);
	while (1)
	{
		
			CW(); // Clock wise
			STP(); // Stop
			CCW(); // Counter clock wise
			STP(); // Stop
	}
}
