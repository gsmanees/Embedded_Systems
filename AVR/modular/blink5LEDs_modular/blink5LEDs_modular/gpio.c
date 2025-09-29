/*
 * gpio.c
 *
 * Created: 29-09-2025 6.17.05 AM
 *  Author: anees
 */ 

#include <avr/io.h>

void init_pins()
{
	DDRB|=(1<<DDB5)|(1<<DDB4)|(1<<DDB3)|(1<<DDB2)|(1<<DDB1);
}

void output_pins()
{
	PORTB^=(1<<PORTB5);
	PORTB^=(1<<PORTB4);
	PORTB^=(1<<PORTB3);
	PORTB^=(1<<PORTB2);
	PORTB^=(1<<PORTB1);
	
}