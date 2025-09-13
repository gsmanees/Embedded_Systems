/*
 * HW_motorBidirection_Functions.c
 *
 * Created: 11-09-2025 3.22.49 AM
 * Author : anees
 MOTOR ROTATION CODE USING FUNCTIONS. 
 YOU HAVE TO USE 3 FUNCTIONS. CW, STP AND CCW. 
 CALL IT FROM THE MAIN AND SHOW THE FUNCTIONALITIES. SIMULATE USING SIML IDE.

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

