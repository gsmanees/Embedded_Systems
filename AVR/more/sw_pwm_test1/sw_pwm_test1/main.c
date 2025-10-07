/*
 * sw_pwm_test1.c
 *
 * Created: 07-10-2025 7.27.23 AM
 * Author : anees
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

volatile uint8_t duty=0;
volatile uint8_t counter=0;

ISR(TIMER0_COMPA_vect)
{
	counter++;
	if (counter<duty)
	PORTB|=(1<<PORTB5);
	else
	PORTB&=~(1<<PORTB5);
}

void timer0_init()
{
	DDRB|=(1<<DDB5);
	TCCR0A=(1<<WGM01); // ctc
	TCCR0B=(1<<CS01); // pre scalar 8
	OCR0A=62;
	TIMSK0=(1<<OCIE0A);
	sei();
}

void fade()
{
	// fade in
	for (uint8_t i=0; i<255; i++)
	{
		duty=i;
		_delay_ms(5);
	}
	
	// fade out
	for (int i=255; i>0; i--)
	{
		duty=i;
		_delay_ms(5);
	}
	
}

int main(void)
{
    timer0_init();
    while (1) 
    {
		fade();
    }
}

