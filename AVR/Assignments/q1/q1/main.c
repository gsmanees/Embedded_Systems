/*
 * q1.c
 *
 * Created: 13-05-2026 6.24.30 AM
 * Author : anees
 
 Objective: Write a program to toggle an LED connected to PORTD Pin 5 with
 specific timing intervals for the ON and OFF states.
 
 Requirements: The LED must be interfaced with PORTD Pin 5. Upon system start
 or reset, the LED must immediately turn ON and remain in that state for exactly 3
 seconds. After the ON period, the LED must turn OFF for a duration of exactly 5
 seconds. The program must be designed to continuously loop this 3-second ON and
 5-second OFF sequence.
 
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRD|=(1<<5); // PORT D PIN 5 set as output
	while (1) 
    {
			PORTD|=(1<<PORTD5);	// LED ON
			_delay_ms(3000);	// delay 3 seconds
			PORTD&=~(1<<PORTD5);	// LED OFF
			_delay_ms(5000);		// delay 5 seconds 
			
    }
}

