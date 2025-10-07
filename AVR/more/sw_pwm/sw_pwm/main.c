/*
 * sw_pwm.c
 *
 * Created: 07-10-2025 6.09.46 AM
 * Author : anees
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile uint8_t duty=0; // duty cycle from 0 to 255
volatile uint8_t pwm_counter=0; // counter from 0 to 255


ISR(TIMER0_COMPA_vect)
{
	pwm_counter++;
	if (pwm_counter<duty)
		PORTB|=(1<<PORTB5);
	else
		PORTB&=~(1<<PORTB5);
}

void timer0_init(void)
{
	DDRB |= (1<<PORTB5);         // set PB5 as output

	// --- Timer0 configuration ---
	TCCR0A = (1 << WGM01);      // CTC mode (Clear Timer on Compare)
	TCCR0B = (1 << CS01);       // prescaler 8
	OCR0A  = 62;               
	TIMSK0 = (1 << OCIE0A);     // enable compare match A interrupt
	sei();                      // enable global interrupts
}

void fade()
{
	for (uint8_t i=0; i<255; i++)
	{
		duty=i;
		_delay_ms(5);
	}
	
	for (int i=255; i>0; i--)
	{
		duty=i;
		_delay_ms(5);
	}
}

int main()
{
	timer0_init();
	
	while (1)
	{
		fade();
	}
	
}