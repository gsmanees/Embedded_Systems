/*
 * led.c
 *
 * Created: 02-01-2026 9.52.55 PM
 *  Author: anees
 */ 

#define F_CPU 16000000UL
#include <avr/interrupt.h>
#include "uart.h"
#include <avr/io.h>
#include <util/delay.h>
#include "global.h"
#include "led.h"
#include <string.h>


void LED_Init(void)
{
	DDRB |= (1<<PB5);
	DDRB|=(1<<PORTB4);
}

void GreenLED_On(void)
{
	PORTB |=  (1<<PB5);
}
void GreenLED_Off(void)
{
	PORTB &= ~(1<<PB5);
}

void RedLED_on(void)
{
	PORTB|=(1<<PORTB4);
}

void RedLED_off(void)
{
	PORTB&=~(1<<PORTB4);
}

void bothLED_on(void)
{
	RedLED_on();
	GreenLED_On();
}

void bothLED_off(void)
{
	RedLED_off();
	GreenLED_Off();
}

void dance(void)
{
	while (strcmp(cmd,"dance")==0)
	{
		RedLED_on();
		GreenLED_Off();
		_delay_ms(500);
		RedLED_off();
		GreenLED_On();
		_delay_ms(500);
	}
}

void stop(void)
{
	bothLED_off();
}



void toggleGreen(void)
{
	while (strcmp(cmd,"toggle green")==0)
	{
		GreenLED_On();
		_delay_ms(500);
		GreenLED_Off();
		_delay_ms(500);
	}
}

void toggleRed(void)
{
	while (strcmp(cmd,"toggle red")==0)
	{
		RedLED_on();
		_delay_ms(500);
		RedLED_off();
		_delay_ms(500);
	}
	
}

