/*
 * decimalToBinary_LED.c
 *
 * Created: 14-09-2025 10.37.31 PM
 * Author : anees
 decimal to binary converter
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>


int main(void)
{
	
    DDRC|=(1<<DDC0);
	DDRC|=(1<<DDC1);
	DDRC|=(1<<DDC2);
	DDRC|=(1<<DDC3);
	
	DDRC&=~(1<<DDC6);
	PORTC|=(1<<PORTC6);
	
	DDRD&=~(1<<DDD0);
	PORTD|=(1<<PORTD0);
	DDRD&=~(1<<DDD1);
	PORTD|=(1<<PORTD1);
	DDRD&=~(1<<DDD2);
	PORTD|=(1<<PORTD2);
	DDRD&=~(1<<DDD3);
	PORTD|=(1<<PORTD3);
	DDRD&=~(1<<DDD4);
	PORTD|=(1<<PORTD4);
	
	DDRB&=~(1<<DDB6);
	PORTB|=(1<<PORTB6);
	DDRB&=~(1<<DDB7);
	PORTB|=(1<<PORTB7);
	
	DDRD&=~(1<<DDD5);
	PORTD|=(1<<PORTD5);
	DDRD&=~(1<<DDD6);
	PORTD|=(1<<PORTD6);
	DDRD&=~(1<<DDD7);
	PORTD|=(1<<PORTD7);
	
	DDRB&=~(1<<DDB0);
	PORTB|=(1<<PORTB0);
	
	
    while (1) 
    {
			
		
		if ((PINC & (1<<PINC6))==0)
		{
			
			PORTC&=~(1<<PORTC0);
			PORTC&=~(1<<PORTC1);
			PORTC&=~(1<<PORTC2);
			PORTC&=~(1<<PORTC3);
			
			
		}
		else if ((PIND&(1<<PIND0))==0)
		{
			
			PORTC&=~(1<<PORTC0);
			PORTC&=~(1<<PORTC1);
			PORTC&=~(1<<PORTC2);
			PORTC|=(1<<PORTC3);
		}
		else if ((PIND&(1<<PIND1))==0)
		{
			
			PORTC&=~(1<<PORTC0);
			PORTC&=~(1<<PORTC1);
			PORTC|=(1<<PORTC2);
			PORTC&=~(1<<PORTC3);
		}
		
			else if ((PIND&(1<<PIND2))==0)
			{
				
				PORTC&=~(1<<PORTC0);
				PORTC&=~(1<<PORTC1);
				PORTC|=(1<<PORTC2);
				PORTC|=(1<<PORTC3);
			}
			
			else if ((PIND&(1<<PIND3))==0)
			{
				
				PORTC&=~(1<<PORTC0);
				PORTC|=(1<<PORTC1);
				PORTC&=~(1<<PORTC2);
				PORTC&=~(1<<PORTC3);
			}
			
			else if ((PIND&(1<<PIND4))==0)
			{
				PORTC&=~(1<<PORTC0);
				PORTC|=(1<<PORTC1);
				PORTC&=~(1<<PORTC2);
				PORTC|=(1<<PORTC3);
			}
			
			else if ((PINB&(1<<PINB6))==0)
			{
				
				PORTC&=~(1<<PORTC0);
				PORTC|=(1<<PORTC1);
				PORTC|=(1<<PORTC2);
				PORTC&=~(1<<PORTC3);
			}
			
			else if ((PINB&(1<<PINB7))==0)
			{
				
				PORTC&=~(1<<PORTC0);
				PORTC|=(1<<PORTC1);
				PORTC|=(1<<PORTC2);
				PORTC|=(1<<PORTC3);
			}
			
			else if ((PIND&(1<<PIND5))==0)
			{
				
				PORTC|=(1<<PORTC0);
				PORTC&=~(1<<PORTC1);
				PORTC&=~(1<<PORTC2);
				PORTC&=~(1<<PORTC3);
			}
			
			else if ((PIND&(1<<PIND6))==0)
			{
				
				PORTC|=(1<<PORTC0);
				PORTC&=~(1<<PORTC1);
				PORTC&=~(1<<PORTC2);
				PORTC|=(1<<PORTC3);
			}
			
			else if ((PIND&(1<<PIND7))==0)
			{
				
				PORTC|=(1<<PORTC0);
				PORTC&=~(1<<PORTC1);
				PORTC|=(1<<PORTC2);
				PORTC&=~(1<<PORTC3);
			}
			
			else if ((PINB&(1<<PINB0))==0)
			{
				PORTC&=~(1<<PORTC0);
				PORTC&=~(1<<PORTC1);
				PORTC&=~(1<<PORTC2);
				PORTC&=~(1<<PORTC3);
			}
			
			else
			{	
				PORTC&=~(1<<PORTC0);
				PORTC&=~(1<<PORTC1);
				PORTC&=~(1<<PORTC2);
				PORTC&=~(1<<PORTC3);
			}
		
		
		
		
    }
	
}

