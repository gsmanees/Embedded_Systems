/*
 * hcsr04.c
 *
 * Created: 28-11-2025 11.38.30 PM
 *  Author: anees
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "hcsr04.h"


void hcsr04_IO_Init(void)
{
	DDRB|=(1<<TRIG); // TRIG INPUT TO ULTRASONIC SENSOR, IT WILL BE OUTPUT FROM AVR
	DDRB&=~(1<<ECHO); // ECHO FROM SENSOR, IT WILL BE INPUT TO SENSOR
}

void hcsr04_EN_trigger(void)
{
	PORTB&=~(1<<TRIG); // TRIG pulse low edge
	_delay_us(2);
	PORTB|=(1<<TRIG); // trig pulse high edge
	_delay_us(10);
	PORTB&=~(1<<TRIG); // trig pulse low edge
	while(!(PINB&(1<<ECHO))); // wait for echo high 
}
	
float measure_distance(void)
{
	// count how long echo stays high
	float count=0;
	while(PINB&(1<<ECHO))
	{
		_delay_us(1);
		count++;
	}
	return count/58.0;
	
}



