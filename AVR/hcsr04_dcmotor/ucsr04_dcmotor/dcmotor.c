/*
 * dcmotor.c
 * Created: 04-12-2025 7.07.28 AM
 *  Author: anees
 */ 

#include <util/delay.h>
#include <avr/io.h>
#include "dcmotor.h"

void motor_init(void)
{
	// initialize both motor pins as output pins 
	DDRB|=(1<<motor_P);
	DDRB|=(1<<motor_N);
}

void motorON(void)
{
	_delay_ms(1000);
	PORTB|=(1<<motor_P);	// HIGH
	PORTB&=~(1<<motor_N);	// LOW
}

void motorOFF(void)
{
	PORTB&=~(1<<motor_P);	// LOW
	PORTB&=~(1<<motor_N);	// LOW
}



