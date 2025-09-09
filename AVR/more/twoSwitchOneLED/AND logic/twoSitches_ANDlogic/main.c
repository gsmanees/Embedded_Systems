/*
 * twoSitches_ANDlogic.c
 *
 * Created: 09-09-2025 10.23.36 PM
 * Author : anees
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>


int main(void)
{
    DDRD = 0b00000000;
	PORTD = 0b10000001;
	DDRC = 0b00100000;
    while (1) 
    {
		if ((PIND & 0b00000001) == 0 && (PIND & 0b10000000) == 0)
		PORTC = 0b00100000;
		else
		PORTC = 0b00000000;
    }
}

