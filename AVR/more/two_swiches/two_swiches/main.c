/*
 * two_swiches.c
 *
 * Created: 09-09-2025 7.22.47 AM
 * Author : anees
 */ 


#define F_CPU 16000000UL
#include <avr/io.h>


int main(void)
{
    DDRC = 0b00110000;
	DDRD = 0b00000000;
	PORTD = 0b10000001;
    while (1) 
    {
		if ((PIND & 0b00000001) == 0)
		PORTC = 0b00100000;
		else if ((PIND & 0b10000000) == 0)
		PORTC = 0b00010000;
		else
		PORTC = 0b00000000;
		
		
		 
		

		
    }
}

