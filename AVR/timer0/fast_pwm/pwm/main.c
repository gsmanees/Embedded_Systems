/*
 * pwm.c
 *
 * Created: 24-09-2025 8.57.38 PM
 * Author : anees
 FAST PWM
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRD|=(1<<DDD6); // PWM OUTPUT PIN OF ATMEGA328 MADE OUTPUT
	TCCR0A|=(1<<WGM01)|(1<<WGM00); // fast pwm selected
	TCCR0A|=(1<<COM0A1); // non inverting selected
	TCCR0B|=(1<<CS00)|(1<<CS01); // pre scalar 64 selected
	OCR0A=200;
    
    while (1) 
    {
		
    }
}

