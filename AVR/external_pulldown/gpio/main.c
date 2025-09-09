/*
 * gpio.c
 *
 * Created: 08-09-2025 8.44.43 PM
 * Author : anees
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>



int main (void)
{
	
	DDRB=0b00100000;
	DDRD=0b00000000;
    /* Replace with your application code */
    while (1) 
    {
		if (PIND == 0b00000001)
		{
			PORTB=0b00100000;
		}
	
		else
		{
			PORTB=0b00000000;
		}
	}
}

