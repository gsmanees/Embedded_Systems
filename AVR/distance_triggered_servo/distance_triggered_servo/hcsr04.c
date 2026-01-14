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
	HCSR04_DDR|=(1<<TRIG); // TRIG INPUT TO ULTRASONIC SENSOR, IT WILL BE OUTPUT FROM AVR
	HCSR04_DDR&=~(1<<ECHO); // ECHO FROM SENSOR, IT WILL BE INPUT TO SENSOR
}

void hcsr04_EN_trigger(void)
{
	HCSR04_PORT&=~(1<<TRIG); // TRIG pulse low edge
	_delay_us(2);
	HCSR04_PORT|=(1<<TRIG); // trig pulse high edge
	_delay_us(10);
	HCSR04_PORT&=~(1<<TRIG); // trig pulse low edge
	while(!(HCSR04_PIN&(1<<ECHO))); // wait for echo high 
}
	
float measure_distance(void)
{
	// count how long echo stays high
	float count=0;
	while(HCSR04_PIN&(1<<ECHO))
	{
		_delay_us(1);
		count++;
	}
	return count/58.0;
	
}


void LED_init(void)
{
	DDRB|=(1<<PORTB3); // red led
}


void LED_ON(void)
{
	PORTB|=(1<<PORTB3); //led on
}

void LED_OFF(void)
{
	PORTB&=~(1<<PORTB3); //LED OFF

}
