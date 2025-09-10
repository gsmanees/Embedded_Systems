/*
 * motorBidirection_Functions_delayPassing.c
 *
 * Created: 11-09-2025 3.36.27 AM
 * Author : anees
 */ 

#define F_CPU 16000000LU
#include <avr/io.h>
#include <util/delay.h>

void delay_ms(unsigned int ms) { 
	while (ms--) 
	{
		_delay_ms(1); // always constant = 1 
	}
}

void CW(unsigned int delay){
	PORTB|=(1<<PORTB5);
	PORTB&=~(1<<PORTB4);
	delay_ms(delay);
}

void STP(unsigned int delay){
	PORTB&=~(1<<PORTB5);
	PORTB&=~(1<<PORTB4);
	delay_ms(delay);
}

void CCW(unsigned int delay){
	PORTB&=~(1<<PORTB5);
	PORTB|=(1<<PORTB4);
	delay_ms(delay);
}

int main(void)
{
	DDRB|=(1<<5);
	DDRB|=(1<<4);
	while (1)
	{
		CW(5000);
		STP(1000);
		CCW(5000);
		STP(1000);
		
	}
}

