/*
 * pwm_motor.c
 *
 * Created: 02-10-2025 6.40.32 AM
 * Author : anees
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>



int main(void)
{
	int state=0;
	DDRD&=~(1<<DDD0);// pin d0 as input
	PORTD|=(1<<PORTD0); // internal pull up
	
    DDRC|=(1<<DDC0)|(1<<DDC1); // set pc0 and pc1 as output
	PORTC|=(1<<PORTC1)|(0<<PORTC0); // set pc1 as logic 1 and pc0 as logic 0
	DDRD|=(1<<DDD6); // make pwm pin pd6 as output
	TCCR0A|=(1<<WGM00)|(1<<WGM01); // fast pwm
	TCCR0B|=(1<<CS00)|(1<<CS02); // pre scalar 1024
	TCCR0A|=(1<<COM0A1); // non inverting selected 
	OCR0A=0;
    while (1) 
    {
		if (!(PIND&(1<<PIND0)))
		{
			_delay_ms(50);
			while(!(PIND & (1<<PIND0))); // wait for release
			
			state++;
			if(state > 3) state = 0;   // cycle back
	
		switch (state)
		{
			case 0: OCR0A=0;   break;
			case 1: OCR0A=85;  break;
			case 2: OCR0A=170; break; 
			case 3: OCR0A=255; break;
		}
		
    }
	}
}

