/*
 * buttonHold.c
 *
 * Created: 16-10-2025 7.11.29 AM
 * Author : anees
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	int counter=0;
	DDRD&=~(1<<DDD2);
	PORTD|=(1<<PORTD2);
	DDRC|=(1<<DDC2)|(1<<DDC0)|(1<<DDC1);
	while (1)
	{
		
		if (!(PIND&(1<<PIND2))) // checking switch pressed or not
		{
			while (!(PIND&(1<<PIND2)))
			{
				_delay_ms(10); // 10 ms delay in every loop
				counter+=10; // 10 counter update in every 10 ms, so counter=1000 in 1 sec 
				// here to get 1000 counter we need to hold the push button for 1 second 
			}
			
			if (counter<1000) // if short press
			{
				_delay_ms(10);
				PORTC^=(1<<PORTC2); // led toggle
				counter=0;
				_delay_ms(50);
			}
			
			if (counter>=1000) // if long press 
			{	
				PORTC^=(1<<PORTC1); // motor rotation state toggles
				PORTC&=~(1<<PORTC0);
				counter=0;
			}
				
		}
	}
	
}


