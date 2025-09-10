/*
 * motorBidirection.c
 *
 * Created: 11-09-2025 3.13.54 AM
 * Author : anees
 Motor Bi direction
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRB|= (1<<DDB5);
	DDRB|= (1<<DDB4);
	while (1)
	{
		
		PORTB|=(1<<PORTB5);
		PORTB&=~(1<<PORTB4);
		_delay_ms(3000);
		PORTB&=~(1<<PORTB5);
		PORTB&=~(1<<PORTB4);
		_delay_ms(1000);
		PORTB&=~(1<<PORTB5);
		PORTB|=(1<<PORTB4);
		_delay_ms(3000);
		PORTB&=~(1<<PORTB5);
		PORTB&=~(1<<PORTB4);
		_delay_ms(1000);
		
	}
}


