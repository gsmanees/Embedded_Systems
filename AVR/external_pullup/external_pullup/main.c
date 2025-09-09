/*
 * external_pullup.c
 *
 * Created: 09-09-2025 5.54.46 AM
 * Author : anees
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>

int main(void)
{
	DDRB = 0b00100000;
	DDRD = 0b00000000;
	
    while (1) 
    {
		if (PIND == 0b00000000)
		PORTB = 0b00100000;
		
		else
		PORTB = 0b00000000;
    }
}

