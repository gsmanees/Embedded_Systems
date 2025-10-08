/*
 * multi_fade.c
 *
 * Created: 08-10-2025 6.08.47 AM
 * Author : anees
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile uint8_t duty[10]={0}; // duty cycle from 0 to 255
volatile uint8_t pwm_counter=0; // counter from 0 to 255
int port=0;
ISR(TIMER0_COMPA_vect)
{
	pwm_counter++;
	
	    if (pwm_counter<duty[0]) PORTC |= (1 << PORTC1); else PORTC &= ~(1 << PORTC1);
	    if (pwm_counter<duty[1]) PORTC |= (1 << PORTC2); else PORTC &= ~(1 << PORTC2);
	    if (pwm_counter<duty[2]) PORTC |= (1 << PORTC3); else PORTC &= ~(1 << PORTC3);
	    if (pwm_counter<duty[3]) PORTC |= (1 << PORTC4); else PORTC &= ~(1 << PORTC4);
	    if (pwm_counter<duty[4]) PORTC |= (1 << PORTC5); else PORTC &= ~(1 << PORTC5);
	    if (pwm_counter<duty[5]) PORTD |= (1 << PORTD0); else PORTD &= ~(1 << PORTD0);
	    if (pwm_counter<duty[6]) PORTD |= (1 << PORTD1); else PORTD &= ~(1 << PORTD1);
	    if (pwm_counter<duty[7]) PORTD |= (1 << PORTD2); else PORTD &= ~(1 << PORTD2);
	    if (pwm_counter<duty[8]) PORTD |= (1 << PORTD3); else PORTD &= ~(1 << PORTD3);
	  
	
}


void timer0_init(void)
{
	TCCR0A = (1 << WGM01);      // CTC mode (Clear Timer on Compare)
	TCCR0B = (1 << CS01);       // prescaler 8
	OCR0A  = 62;
	TIMSK0 = (1 << OCIE0A);     // enable compare match A interrupt
	sei();                      // enable global interrupts
}


void led_init()
{
	DDRC|=(1<<DDC1)|(1<<DDC2)|(1<<DDC3)|(1<<DDC4)|(1<<DDC5);
	DDRD|=(1<<DDD0)|(1<<DDD1)|(1<<DDD2)|(1<<DDD3)|(1<<DDD4);
	DDRB&=~(1<<DDB0);
	PORTB|=(1<<PORTB0); // pin b6 is input active low
}

void fade()
{
	for (int k=0; k<10; k++)
	{
		for (uint8_t i=0; i<255; i++)
		{
			duty[k]=i;
			_delay_ms(5);
		}
		
		for (int i=255; i>0; i--)
		{
			duty[k]=i;
			_delay_ms(5);
		}
		duty[k]=0;
		
	}
	
}

int main(void)
{
	led_init();
	timer0_init();
	while (1)
	{
		if (!(PINB&(1<<PINB0)))
		{
			_delay_ms(50);
			while(!(PINB&(1<<PINB0)));
			fade();
		}
	}
}
