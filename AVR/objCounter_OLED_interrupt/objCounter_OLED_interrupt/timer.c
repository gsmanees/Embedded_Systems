/*
 * timer.c
 *
 * Created: 28-12-2025 4.40.31 PM
 *  Author: anees
 */ 

#define F_CPU 16000000UL
#include "timer.h"
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

/* ---------------- Timer0 Init ---------------- */
void Timer0_Init(void)
{
	TCCR0A = 0x00;                          // Normal mode
	TCCR0B = (1 << CS01) | (1 << CS00);     // Prescaler 64
	TIMSK0 = (1 << TOIE0);                  // Enable overflow interrupt
}


