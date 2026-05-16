/*
 * Q5.c
 *
 * Created: 16-05-2026 6.23.18 AM
 * Author : anees
 
 Objective: Write a program to simulate a basic one-way traffic light controller 
 using three LEDs to represent the Green, Orange, and Red signals without using 
 inbuilt _delay() function.
 Requirements: The system must control three LEDs connected to any three available 
 GPIO pins on PORTB. Upon system start, the Green LED must turn ON for a duration 
 of 10 seconds. After this period, the Green LED must turn OFF and the Orange LED 
 must turn ON for 3 seconds. Once the Orange duration ends, it must turn OFF and the 
 Red LED must turn ON for 10 seconds. The program must be designed to continuously 
 cycle through this Green-Orange-Red sequence indefinitely.
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
/*
Green LED - PORTB5
Orange LED - PORTB4
Red LED - PORTB3
*/

void delay_10s()
{
	int i;
	int count=610;
	
	
	for (i=0; i<count; i++)
	{
		TCNT0=0;
		TCCR0A=0;
		TCCR0B|=(1<<CS00)|(1<<CS02); // prescalar 1024
		TIFR0|=(1<<TOV0);
		while (!(TIFR0&(1<<TOV0)));
	}
	
}

void delay_3s()
{
	int i;
	int count=183;
	
	
	for (i=0; i<count; i++)
	{
		TCNT0=0;
		TCCR0A=0;
		TCCR0B|=(1<<CS00)|(1<<CS02); // prescalar 1024
		TIFR0|=(1<<TOV0);
		while (!(TIFR0&(1<<TOV0)));
	}
}


int main(void)
{
	#define GreenLED PORTB5
	#define OrangeLED PORTB4
	#define RedLED PORTB3
	
	
    
    while (1) 
    {
		
		DDRB|=(1<<DDB5)|(1<<DDB4)|(1<<DDB3);
		
		while (1)
		{
			PORTB|=(1<<GreenLED); //Green 
			delay_10s();
			PORTB&=~(1<<GreenLED);
			PORTB|=(1<<OrangeLED); // orange
			delay_3s();
			PORTB&=~(1<<OrangeLED);
			PORTB|=(1<<RedLED);		// red LED
			delay_10s();
			PORTB&=~(1<<RedLED);
			
		}
    }
}

