/*
 * pwm_concept_dso.c
 *
 * Created: 01-10-2025 6.08.39 AM
 * Author : anees
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
	int i;
	DDRD|=(1<<DDD6); // PWM OUTPUT PIN OF ATMEGA328 MADE OUTPUT
	DDRD|=(1<<DDD5);
	TCCR0A|=(1<<WGM01)|(1<<WGM00); // fast pwm selected
	TCCR0A|=(1<<COM0B1);
	TCCR0A|=(1<<COM0A1); // non inverting selected
	TCCR0B|=(1<<CS02)|(1<<CS00); // pre scalar 124 selected
	OCR0A=124;
	
	while (1)
	{
		for (i=0; i<255; i++)
		{
			OCR0B=i;
			_delay_ms(10);
		}
		
		for (i=255; i>0; i--)
		{
			OCR0B=i;
			_delay_ms(10);
		}
		
	}
	
	
}

