/*
 * led_multiPattern_pushButton_v2.c
 *
 * Created: 06-10-2025 6.22.59 AM
 * Author : anees
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h> // v2

volatile uint8_t duty[10]={0}; // duty cycle from 0 to 255  // v2
volatile uint8_t pwm_counter=0; // counter from 0 to 255  // v2


ISR(TIMER0_COMPA_vect)  // v2
{
	pwm_counter++;
	
	if (pwm_counter<duty[0]) PORTC |= (1 << PORTC1); else PORTC &= ~(1 << PORTC1);
	if (pwm_counter<duty[1]) PORTC |= (1 << PORTC2); else PORTC &= ~(1 << PORTC2);
	if (pwm_counter<duty[2]) PORTC |= (1 << PORTC3); else PORTC &= ~(1 << PORTC3);
	if (pwm_counter<duty[3]) PORTC |= (1 << PORTC4); else PORTC &= ~(1 << PORTC4);
	if (pwm_counter<duty[4]) PORTC |= (1 << PORTC5); else PORTC &= ~(1 << PORTC5);
	if (pwm_counter<duty[5]) PORTD |= (1 << PORTD4); else PORTD &= ~(1 << PORTD4);
	if (pwm_counter<duty[6]) PORTD |= (1 << PORTD0); else PORTD &= ~(1 << PORTD0);
	if (pwm_counter<duty[7]) PORTD |= (1 << PORTD1); else PORTD &= ~(1 << PORTD1);
	if (pwm_counter<duty[8]) PORTD |= (1 << PORTD2); else PORTD &= ~(1 << PORTD2);
	if (pwm_counter<duty[9]) PORTD |= (1 << PORTD3); else PORTD &= ~(1 << PORTD3);
}

void timer0_init(void) // v2
{
	TCCR0A = (1 << WGM01);      // CTC mode (Clear Timer on Compare)
	TCCR0B = (1 << CS01);       // prescaler 8
	OCR0A  = 62;
	TIMSK0 = (1 << OCIE0A);     // enable compare match A interrupt
	sei();                      // enable global interrupts
}



void delay_500ms()
{
	int i,count=30;
	for (i=0; i<count; i++)
	{
		TCNT0=0;
		OCR0A=247;
		TCCR0A|=(1<<WGM00)|(1<<WGM01); // ctc
		TCCR0B|=(1<<CS00)|(1<<CS02); // prescalar 1024
		TIFR0|=(1<<OCF0A);
		while (!(TIFR0&(1<<OCF0A)))
		{
		}
	}
	
}

void alternate ()
{
	PORTC^=(1<<PORTC1);
	PORTC^=(1<<PORTC3);
	PORTC^=(1<<PORTC5);
	PORTD^=(1<<PORTD0);
	PORTD^=(1<<PORTD2);
	
	PORTC&=~(1<<PORTC2);
	PORTC&=~(1<<PORTC4);
	PORTD&=~(1<<PORTD4);
	PORTD&=~(1<<PORTD1);
	PORTD&=~(1<<PORTD3);
	
	delay_500ms();
	PORTC^=(1<<PORTC2);
	PORTC^=(1<<PORTC4);
	PORTD^=(1<<PORTD4);
	PORTD^=(1<<PORTD1);
	PORTD^=(1<<PORTD3);
	
	PORTC&=~(1<<PORTC1);
	PORTC&=~(1<<PORTC3);
	PORTC&=~(1<<PORTC5);
	PORTD&=~(1<<PORTD0);
	PORTD&=~(1<<PORTD2);
	delay_500ms();
	PORTD&=0;
	PORTC&=0;
}

void forward ()
{
	PORTC|=(1<<PORTC1);delay_500ms();
	PORTC|=(1<<PORTC2);delay_500ms();
	PORTC|=(1<<PORTC3);delay_500ms();
	PORTC|=(1<<PORTC4);delay_500ms();
	PORTC|=(1<<PORTC5);delay_500ms();
	PORTD|=(1<<PORTD4);delay_500ms();
	PORTD|=(1<<PORTD0);delay_500ms();
	PORTD|=(1<<PORTD1);delay_500ms();
	PORTD|=(1<<PORTD2);delay_500ms();
	PORTD|=(1<<PORTD3);delay_500ms();
	
	PORTC&=~(1<<PORTC1);delay_500ms();
	PORTC&=~(1<<PORTC2);delay_500ms();
	PORTC&=~(1<<PORTC3);delay_500ms();
	PORTC&=~(1<<PORTC4);delay_500ms();
	PORTC&=~(1<<PORTC5);delay_500ms();
	PORTD&=~(1<<PORTD4);delay_500ms();
	PORTD&=~(1<<PORTD0);delay_500ms();
	PORTD&=~(1<<PORTD1);delay_500ms();
	PORTD&=~(1<<PORTD2);delay_500ms();
	PORTD&=~(1<<PORTD3);delay_500ms();
	
	PORTD&=0;
	PORTC&=0;
}

void reverse ()
{
	PORTD|=(1<<PORTD3);delay_500ms();
	PORTD|=(1<<PORTD2);delay_500ms();
	PORTD|=(1<<PORTD1);delay_500ms();
	PORTD|=(1<<PORTD0);delay_500ms();
	PORTD|=(1<<PORTD4);delay_500ms();
	PORTC|=(1<<PORTC5);delay_500ms();
	PORTC|=(1<<PORTC4);delay_500ms();
	PORTC|=(1<<PORTC3);delay_500ms();
	PORTC|=(1<<PORTC2);delay_500ms();
	PORTC|=(1<<PORTC1);delay_500ms();
	
	PORTD&=~(1<<PORTD3);delay_500ms();
	PORTD&=~(1<<PORTD2);delay_500ms();
	PORTD&=~(1<<PORTD1);delay_500ms();
	PORTD&=~(1<<PORTD0);delay_500ms();
	PORTD&=~(1<<PORTD4);delay_500ms();
	PORTC&=~(1<<PORTC5);delay_500ms();
	PORTC&=~(1<<PORTC4);delay_500ms();
	PORTC&=~(1<<PORTC3);delay_500ms();
	PORTC&=~(1<<PORTC2);delay_500ms();
	PORTC&=~(1<<PORTC1);delay_500ms();
	
	PORTD&=0;
	PORTC&=0;
}

void chaser ()
{
	PORTC|=(1<<PORTC1);delay_500ms();
	PORTC&=~(1<<PORTC1);
	PORTC|=(1<<PORTC2);delay_500ms();
	PORTC&=~(1<<PORTC2);
	PORTC|=(1<<PORTC3);delay_500ms();
	PORTC&=~(1<<PORTC3);
	PORTC|=(1<<PORTC4);delay_500ms();
	PORTC&=~(1<<PORTC4);
	PORTC|=(1<<PORTC5);delay_500ms();
	PORTC&=~(1<<PORTC5);
	PORTD|=(1<<PORTD4);delay_500ms();
	PORTD&=~(1<<PORTD4);
	PORTD|=(1<<PORTD0);delay_500ms();
	PORTD&=~(1<<PORTD0);
	PORTD|=(1<<PORTD1);delay_500ms();
	PORTD&=~(1<<PORTD1);
	PORTD|=(1<<PORTD2);delay_500ms();
	PORTD&=~(1<<PORTD2);
	PORTD|=(1<<PORTD3);delay_500ms();
	PORTD&=~(1<<PORTD3);
	delay_500ms();
	
	PORTD|=(1<<PORTD2);delay_500ms();
	PORTD&=~(1<<PORTD2);
	PORTD|=(1<<PORTD1);delay_500ms();
	PORTD&=~(1<<PORTD1);
	PORTD|=(1<<PORTD0);delay_500ms();
	PORTD&=~(1<<PORTD0);
	PORTD|=(1<<PORTD4);delay_500ms();
	PORTD&=~(1<<PORTD4);
	PORTC|=(1<<PORTC5);delay_500ms();
	PORTC&=~(1<<PORTC5);
	PORTC|=(1<<PORTC4);delay_500ms();
	PORTC&=~(1<<PORTC4);
	PORTC|=(1<<PORTC3);delay_500ms();
	PORTC&=~(1<<PORTC3);
	PORTC|=(1<<PORTC2);delay_500ms();
	PORTC&=~(1<<PORTC2);
	PORTC|=(1<<PORTC1);delay_500ms();
	PORTC&=~(1<<PORTC1);
	delay_500ms();
}


void half ()
{
	PORTC|=(1<<PORTC1);
	PORTC|=(1<<PORTC2);
	PORTC|=(1<<PORTC3);
	PORTC|=(1<<PORTC4);
	PORTC|=(1<<PORTC5);
	PORTD&=~(1<<PORTD4);
	PORTD&=~(1<<PORTD0);
	PORTD&=~(1<<PORTD1);
	PORTD&=~(1<<PORTD2);
	PORTD&=~(1<<PORTD3);
	delay_500ms();
	PORTC&=~(1<<PORTC1);
	PORTC&=~(1<<PORTC2);
	PORTC&=~(1<<PORTC3);
	PORTC&=~(1<<PORTC4);
	PORTC&=~(1<<PORTC5);
	PORTD|=(1<<PORTD4);
	PORTD|=(1<<PORTD0);
	PORTD|=(1<<PORTD1);
	PORTD|=(1<<PORTD2);
	PORTD|=(1<<PORTD3);
	delay_500ms();
	PORTC&=0;
	PORTD&=0;
}


void together()
{
	
	PORTC|=(1<<PORTC1);
	PORTC|=(1<<PORTC2);
	PORTC|=(1<<PORTC3);
	PORTC|=(1<<PORTC4);
	PORTC|=(1<<PORTC5);
	PORTD|=(1<<PORTD4);
	PORTD|=(1<<PORTD0);
	PORTD|=(1<<PORTD1);
	PORTD|=(1<<PORTD2);
	PORTD|=(1<<PORTD3);
	delay_500ms();
	PORTC&=~(1<<PORTC1);
	PORTC&=~(1<<PORTC2);
	PORTC&=~(1<<PORTC3);
	PORTC&=~(1<<PORTC4);
	PORTC&=~(1<<PORTC5);
	PORTD&=~(1<<PORTD4);
	PORTD&=~(1<<PORTD0);
	PORTD&=~(1<<PORTD1);
	PORTD&=~(1<<PORTD2);
	PORTD&=~(1<<PORTD3);
	delay_500ms();
	
}

void pattern_all ()
{
	together();
	alternate();
	half();
	half_delay(); // v2
	toCenter(); // v2
	forward();
	reverse();
	chaser();
	chase_fade(); // v2
	
}

void led_init()
{
	DDRC|=(1<<DDC1)|(1<<DDC2)|(1<<DDC3)|(1<<DDC4)|(1<<DDC5);
	DDRD|=(1<<DDD0)|(1<<DDD1)|(1<<DDD2)|(1<<DDD3)|(1<<DDD4);
	DDRB&=~(1<<DDB0);
	PORTB|=(1<<PORTB0); // pin b6 is input active low
}



void half_delay()  // added on version 2
{
	PORTC|=(1<<PORTC1);_delay_ms(500);
	PORTC&=~(1<<PORTC1);
	PORTC|=(1<<PORTC2);_delay_ms(400);
	PORTC&=~(1<<PORTC2);
	PORTC|=(1<<PORTC3);_delay_ms(300);
	PORTC&=~(1<<PORTC3);
	PORTC|=(1<<PORTC4);_delay_ms(200);
	PORTC&=~(1<<PORTC4);
	PORTC|=(1<<PORTC5);_delay_ms(100);
	PORTC&=~(1<<PORTC5);
	PORTD|=(1<<PORTD4);_delay_ms(100);
	PORTD&=~(1<<PORTD4);
	PORTD|=(1<<PORTD0);_delay_ms(200);
	PORTD&=~(1<<PORTD0);
	PORTD|=(1<<PORTD1);_delay_ms(300);
	PORTD&=~(1<<PORTD1);
	PORTD|=(1<<PORTD2);_delay_ms(400);
	PORTD&=~(1<<PORTD2);
	PORTD|=(1<<PORTD3);_delay_ms(500);
	PORTD&=~(1<<PORTD3);
	delay_500ms();
}

void chase_fade()  // added on version 2
{
	timer0_init();
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
	
	TIMSK0 &= ~(1 << OCIE0A);
	TCCR0B = 0;
	PORTC = 0;
	PORTD = 0;
}

void toCenter() // added on version 2
{
	PORTC|=(1<<PORTC1);
	PORTD|=(1<<PORTD3);
	_delay_ms(500);
	PORTC&=~(1<<PORTC1);
	PORTD&=~(1<<PORTD3);
	
	
	PORTC|=(1<<PORTC2);
	PORTD|=(1<<PORTD2);
	_delay_ms(400);
	PORTC&=~(1<<PORTC2);
	PORTD&=~(1<<PORTD2);
	
	PORTC|=(1<<PORTC3);
	PORTD|=(1<<PORTD1);
	_delay_ms(300);
	PORTC&=~(1<<PORTC3);
	PORTD&=~(1<<PORTD1);
	
	PORTC|=(1<<PORTC4);
	PORTD|=(1<<PORTD0);
	_delay_ms(200);
	PORTC&=~(1<<PORTC4);
	PORTD&=~(1<<PORTD0);
	
	PORTC|=(1<<PORTC5);
	PORTD|=(1<<PORTD4);
	_delay_ms(100);
	PORTD&=~(1<<PORTD4);
	PORTC&=~(1<<PORTC5);
	
	delay_500ms();
	
	
	PORTC|=(1<<PORTC5);
	PORTD|=(1<<PORTD4);
	_delay_ms(100);
	PORTD&=~(1<<PORTD4);
	PORTC&=~(1<<PORTC5);
	
	PORTC|=(1<<PORTC4);
	PORTD|=(1<<PORTD0);
	_delay_ms(200);
	PORTC&=~(1<<PORTC4);
	PORTD&=~(1<<PORTD0);
	
	PORTC|=(1<<PORTC3);
	PORTD|=(1<<PORTD1);
	_delay_ms(300);
	PORTC&=~(1<<PORTC3);
	PORTD&=~(1<<PORTD1);
	
	PORTC|=(1<<PORTC2);
	PORTD|=(1<<PORTD2);
	_delay_ms(400);
	PORTC&=~(1<<PORTC2);
	PORTD&=~(1<<PORTD2);
	
	PORTC|=(1<<PORTC1);
	PORTD|=(1<<PORTD3);
	_delay_ms(500);
	PORTC&=~(1<<PORTC1);
	PORTD&=~(1<<PORTD3);
}


int main(void)
{
	int state=0;
	led_init();
	while (1)
	{
		if (!(PINB&(1<<PINB0)))
		{
			_delay_ms(50);
			while(!(PINB&(1<<PINB0)));
			state++;
			if (state>10)state=0;
			switch (state)
			{
				case 1: together();break;
				case 2: alternate();break;
				case 3: half();break;
				case 4: half_delay();break; // added on version 2
				case 5: toCenter();break; // added on version 2
				case 6: forward();break;
				case 7: reverse();break;
				case 8: chaser();break;
				case 9: chase_fade(); break; // added on version 2
				case 10: pattern_all();break;
			}
		}
	}
}



