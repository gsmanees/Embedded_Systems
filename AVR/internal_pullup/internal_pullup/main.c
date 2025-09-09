/*
 * internal_pullup.c
 *
 * Created: 09-09-2025 6.14.18 AM
 * Author : anees
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>


int main(void)
{
	DDRB = 0b00100000;
	DDRD = 0b00000000;
	PORTD = 0b00000001; // internal pullup enabled for PORTD, D0
   
    while (1) 
    {
		if (PIND == 0b00000000)
		PORTB = 0b00100000;
		else
		PORTB = 0b00000000;
    }
}

