/*
 * led_multiPattern_pushButton.c
 *
 * Created: 04-10-2025 9.59.21 AM
 * Author : anees
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

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
	forward();
	reverse();
	chaser();
	
}

void led_init()
{
	DDRC|=(1<<DDC1)|(1<<DDC2)|(1<<DDC3)|(1<<DDC4)|(1<<DDC5);
	DDRD|=(1<<DDD0)|(1<<DDD1)|(1<<DDD2)|(1<<DDD3)|(1<<DDD4);
	DDRB&=~(1<<DDB0);
	PORTB|=(1<<PORTB0); // pin b6 is input active low
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
		if (state>7)state=0;
		switch (state)
		{
		case 1: together();break;
		case 2: alternate();break;
		case 3: half();break;
		case 4: forward();break;
		case 5: reverse();break;
		case 6: chaser();break;
		case 7: pattern_all();break;
		}
		}
    }
}

