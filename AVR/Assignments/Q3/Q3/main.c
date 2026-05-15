/*
 * Q3.c
 *
 * Created: 15-05-2026 10.57.07 PM
 * Author : anees
 
 Objective: Write a program to create a "train" animation where a single active LED 
 appears to move across a series of connected GPIO pins.
 
 Requirements: The system must control a sequence of at least eight LEDs 
 connected to PORTB. When the program starts, only the first LED should turn ON. 
 After a short delay, the first LED must turn OFF and the second LED must turn ON. 
 This sequential shifting must continue until the last LED in the row is reached. 
 Once the "train" reaches the end of the line, the pattern should immediately reset 
 to the first LED and repeat the sequence indefinitely to create a continuous moving 
 light effect.
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    /*
	here I used 8 LEDs
	in Question, it asked to use PORTB
	but PORTB has only 6 output pins, So i used PORTD7 and PORTD8 as 7th and 8ht LEDs
	LED1 - PORTB0
	LED2 - PORTB1
	LED3 - PORTB2
	LED4 - PORTB3
	LED5 - PORTB4
	LED6 - PORTB5
	LED7 - PORTD7
	LED8 - PORTD6
	*/
	
	// SETTING LED OUTPUT PINS 
	DDRB|=(1<<DDB0)|(1<<DDB1)|(1<<DDB2)|(1<<DDB3)|(1<<DDB4)|(1<<DDB5);
	DDRD|=(1<<DDD7)|(1<<DDD6);
    while (1) 
    {
		PORTB|=(1<<PORTB0);		// LED1 ON
		PORTD&=~(1<<PORTD6);
		_delay_ms(500);
		
		PORTB&=~(1<<PORTB0);
		PORTB|=(1<<PORTB1);		// LED2 ON
		_delay_ms(500);
		
		PORTB&=~(1<<PORTB1);
		PORTB|=(1<<PORTB2);		// LED3 ON
		_delay_ms(500);
		
		PORTB&=~(1<<PORTB2);
		PORTB|=(1<<PORTB3);		// LED4 ON
		_delay_ms(500);
		
		PORTB&=~(1<<PORTB3);
		PORTB|=(1<<PORTB4);		// LED5 ON
		_delay_ms(500);
		
		PORTB&=~(1<<PORTB4);	
		PORTB|=(1<<PORTB5);		// LED6 ON
		_delay_ms(500);
		
		PORTB&=~(1<<PORTB5);
		PORTD|=(1<<PORTD7);		// LED7 ON
		_delay_ms(500);
		
		PORTD&=~(1<<PORTD7);
		PORTD|=(1<<PORTD6);		// LED8 ON
		_delay_ms(500);
		
    }
}

