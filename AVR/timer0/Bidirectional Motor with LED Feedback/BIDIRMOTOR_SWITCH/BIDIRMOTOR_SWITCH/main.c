/*
 * BIDIRMOTOR_SWITCH.c
 *
 * Created: 23-09-2025 8.48.10 AM
 * Author : anees
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>

void delay_500ms_normal()
{
	int i;
	int count=30;
	for (i=0; i<count; i++)
	{
		TCNT0=0;
		TCCR0A=0; // timer 0 normal delay used
		TCCR0B|=(1<<CS00)|(1<<CS02); // pre scalar 1024 used
		TIFR0|=(1<<TOV0); // flag cleared
		while (!(TIFR0&(1<<TOV0)));
	}
}

void motor_right()
{
	int i;
	// B2 = RIGHT LED, B5 = LEFT LED
	PORTB|=(1<<PORTB2)|(1<<PORTB4); //
	PORTB&=~(PORTB3);
	PORTB&=~(1<<PORTB5);
	
	for (i=0; i<5; i++)
	{
		PORTB|=(1<<PORTB2);
		delay_500ms_normal();
		PORTB&=~(1<<PORTB2);
		delay_500ms_normal();
	}
}

void motor_left()
{
	int i;
	//delay_1s_ctc();
	PORTB|=(1<<PORTB3)|(1<<PORTB5);
	PORTB&=~(1<<PORTB2);
	for (i=0; i<5; i++)
	{
		PORTB|=(1<<PORTB5);
		delay_500ms_normal();
		PORTB&=~(1<<PORTB5);
		delay_500ms_normal();
	}
}

void motor_stop()
{
	PORTB&=0;
	delay_500ms_normal();
}

int main(void) 
{
	DDRB|=(1<<DDB5)|(1<<DDB4)|(1<<DDB3)|(1<<DDB2);
	DDRD&=~(1<<DDD0);
	PORTD|=(1<<PORTD0); 
	
	while (1)
	{
		if (!PIND&(1<<PIND0))
		{
			motor_right();
			motor_stop();
			motor_left();
			motor_stop();
		}
		
		
		
		
	}
}


