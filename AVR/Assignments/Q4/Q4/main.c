/*
 * Q4.c
 *
 * Created: 15-05-2026 11.46.02 PM
 * Author : anees
 
 Objective: Write a program that uses four LEDs to display a 4-bit binary 
 count triggered by a switch.
 Requirements: Four LEDs must be connected to PORTB (Pins 0 through 3) 
 and a push-button must be connected to PORTD Pin 2. Every time the switch is pressed, 
 the value displayed by the LEDs must increment by one in binary format (from 0000 to 1111). 
 When the count reaches 15 (all LEDs ON), the next press must reset the counter back to 0. 
 The program should use a dedicated function to update the LED states based on the current 
 counter variable.
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

/*
bit0 - PORTB0
bit1 - PORTB1
bit2 - PORTB2
bit3 - PORTB3

*/

void updateBin(uint8_t counter)
{
	PORTB&=0x00;// clears all LEDs on PORTB
	PORTB|=counter&(0x0F);	// the LEDs corresponding to 1s position will become ON
	
}

int main(void)
{
	// set pb0, pb1, pb2, pb3 as output
	DDRB|=(1<<DDB0)|(1<<DDB1)|(1<<DDB2)|(1<<DDB3);
	DDRD&=~(1<<DDD2);		// set pind2 as inout 
	PORTD|=(1<<PORTD2);		// enabled internal pull up
	
	uint8_t counter=0;
	
    while (1) 
    {
		
		if (!(PIND&(1<<PIND2)))
		{
			while(!(PIND&(1<<PIND2)));
			_delay_ms(20);
			
			updateBin(counter);
			counter++;
			
			if (counter>15)
			{
				counter=0;
			}
			
			
		}
    }
}

