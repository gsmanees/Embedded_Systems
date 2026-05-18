/*
 * pwm.c
 *
 * Created: 17-05-2026 6.06.39 PM
 *  Author: anees
 */ 

#include "pwm.h"

void PWM_Init(void)
{
	DDRD|=(1<<PD6);   // OC0A output

	TCCR0A=(1<<COM0A1)|(1<<WGM01)|(1<<WGM00);  // Fast PWM Mode
	TCCR0B=(1<<CS01)|(1<<CS00);  // Prescaler 64
	OCR0A = 0;
}

void PWM_SetBrightness(uint8_t percent)
{
	if(percent>100)
	percent=100;
	
	if(percent==0)  // Completely OFF
	{
		TCCR0A&=~(1<<COM0A1);  // Disconnect OC0A from timer
		PORTD&=~(1<<PD6);
		return;
	}

	// Re-enable PWM output
	TCCR0A|=(1<<COM0A1);
	OCR0A=(percent*255)/100;
}