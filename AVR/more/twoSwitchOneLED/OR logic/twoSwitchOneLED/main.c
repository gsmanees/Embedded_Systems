/*
 * twoSwitchOneLED.c
 *
 * Created: 09-09-2025 10.08.04 PM
 * Author : anees
 
 Two switches controlling one LED

 LED on PC5.

 If any one switch (PD0 or PD7) is pressed ? LED ON.

 Else LED OFF.
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>


int main(void)
{
    DDRD = 0b00000000; // PORT D declared as input port
	PORTD = 0b10000001;// internal pull-ups activated for PD0 and PD7
	DDRC = 0b00100000; // port C c5 declared as output
    while (1) 
    {
		if ((PIND & 0b00000001) == 0)
		PORTC = 0b00100000;
		else if ((PIND & 0b10000000) == 0)
		PORTC = 0b00100000;
		else
		PORTC = 0b00000000;
		
    }
}

