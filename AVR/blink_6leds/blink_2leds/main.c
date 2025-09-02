/*
 * blink_2leds.c
 *
 * Created: 02-09-2025 6.07.34 AM
 * Author : anees
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include<util/delay.h>

int main(void)
{
    DDRB=0b11000111;
	DDRD=0b10000000;
    while (1) 
    {	
		PORTB=0b00000001;
		_delay_ms(1000);
		PORTB=0b00000010;
		_delay_ms(1000);
		PORTB=0b0000100;
		_delay_ms(1000);
		PORTB=0b01000000;
		_delay_ms(1000);
		PORTB=0b10000000;
		_delay_ms(1000);
		PORTB=0b00000000;
		PORTD=0b10000000;
		_delay_ms(1000);
		PORTD=0b00000000;
		}
	}

