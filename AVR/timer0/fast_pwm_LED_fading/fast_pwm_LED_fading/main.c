/*
 * fast_pwm_LED_fading.c
 *
 * Created: 25-09-2025 7.55.38 AM
 * Author : anees
 fast pwm led fading
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	int i;
	DDRD|=(1<<DDD6); // PWM OUTPUT PIN OF ATMEGA328 MADE OUTPUT
	TCCR0A|=(1<<WGM01)|(1<<WGM00); // fast pwm selected
	TCCR0A|=(1<<COM0A1); // non inverting selected
	TCCR0B|=(1<<CS00)|(1<<CS01); // pre scalar 64 selected
	OCR0A=0;
	
	while (1)
	{
		
		for (i=0; i<=255; i++)
		{
			OCR0A++;
			_delay_ms(10);
		}
		
		for (i=255; i>=0; i--)
		{
			OCR0A--;
			_delay_ms(10);
		}
	}
}

