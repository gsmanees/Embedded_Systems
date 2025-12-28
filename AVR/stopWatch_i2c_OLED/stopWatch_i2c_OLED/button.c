/*
 * button.c
 *
 * Created: 28-12-2025 4.37.45 PM
 *  Author: anees
 */ 
#define F_CPU 16000000UL
#include "button.h"
#include <avr/io.h>
#include <util/delay.h>

/* ---------------- Button Init ---------------- */
void Button_Init(void)
{
	DDRD &= ~((1 << START_STOP_BTN) | (1 << RESET_BTN)); // Input
	PORTD |= (1 << START_STOP_BTN) | (1 << RESET_BTN);  // Pull-up
}

/* ---------------- Button Press Detect ---------------- */
uint8_t Button_Pressed(uint8_t pin)
{
	if (!(PIND & (1 << pin)))
	{
		_delay_ms(20);                    // Debounce
		if (!(PIND & (1 << pin)))
		{
			while (!(PIND & (1 << pin))); // Wait for release
			return 1;
		}
	}
	return 0;
}