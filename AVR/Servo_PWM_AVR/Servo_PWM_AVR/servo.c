/*
 * servo.c
 *
 * Created: 05-01-2026 6.19.29 AM
 *  Author: anees
 */ 

#include "servo.h"
/* ----------- SERVO PWM (TIMER1) ----------- */

void Servo_Init(void)
{
	DDRB |= (1 << PORTB1);                    // OC1A as output

	// Fast PWM, Mode 14 (ICR1 as TOP)
	TCCR1A = (1 << COM1A1) | (1 << WGM11);
	TCCR1B = (1 << WGM13)  | (1 << WGM12) | (1 << CS11); // Pre scaler 8

	ICR1  = 39999;                         // 20 ms period (50 Hz)
	OCR1A = 3000;                          // Center position (~1.5 ms)
}