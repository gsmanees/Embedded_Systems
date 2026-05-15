/*
 * Q2.c
 *
 * Created: 13-05-2026 6.53.48 AM
 * Author : anees
 
 Objective: Write a program to toggle between a Red LED and a Green LED using a momentary 
 push-button switch.
 Requirements: The system must interface with a Red LED, a Green LED, and a push-button switch. 
 When the switch is pressed, the program must toggle the current active LED state. 
 If the Red LED is currently ON, it must be turned OFF while the Green LED is turned ON. 
 Conversely, if the Green LED is currently ON, it must be turned OFF while the Red LED is turned ON. 
 Each individual press of the switch should trigger exactly one transition between the two LEDs
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	uint8_t button_state=0;		// first take button state as 0
    DDRD|=(1<<DDD5)|(1<<DDD6);	// PORTD pin 5 and 6 set as output for LEDs
	DDRD&=~(1<<DDD7);			// PORTD pin7 set as input for push button
	PORTD|=(1<<PORTD7);		// enabled internal pull up
	
    while (1) 
    {
		if (button_state==0)	// we already set button state as 0
		{
			if (!(PIND&(1<<PIND7)))	// checks button pressed or not
			{
				while(!(PIND&(1<<PIND7)));	// stays until button release 
				_delay_ms(20);
				PORTD|=(1<<PORTD5);	// Red LED ON
				PORTD&=~(1<<PORTD6);	// Green LED off
				button_state=1;	// button state updated to 1
			}
		}
		
		else if (button_state==1)	// this condition matches
		{
			if (!(PIND&(1<<PIND7)))	 // checks button pressed or not
			{
				while(!(PIND&(1<<PIND7)));	// stays until button release 
				_delay_ms(20);
				PORTD|=(1<<PORTD6);	// green LED on
				PORTD&=~(1<<PORTD5);	// red LED off
				button_state=0;
  			}
		}
    }
}

// this program toggles between red and green LEDs while press the button
