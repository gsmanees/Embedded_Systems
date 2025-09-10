/*
 * led_bitwise.c
 *
 * Created: 10-09-2025 8.21.03 PM
 * Author : anees
 LED blink bitwise
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRB|= (1<<DDB5); // PB5 initialized as output
	
    while (1) 
    {
		PORTB|=(1<<PORTB5); // PB5 = 1
		_delay_ms(1000);
		PORTB&=~(1<<PORTB5); // PB5 = 0
		_delay_ms(1000);
    }
}

