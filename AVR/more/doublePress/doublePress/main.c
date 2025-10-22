/*
 * doublePress.c
 *
 * Created: 20-10-2025 9.16.05 PM
 * Author : anees
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int doublePress=0;


void while_check()
{
	_delay_ms(50); // debounce
	while (!(PIND&(1<<PIND2))); // hold program until button press process complete
}


void doublePress_check()
{
	// checking if there is a second press within 500ms
	for (int i=0; i<50; i++)
	{
		_delay_ms(10); // it delays the program for 500ms, and in every loop checks for a second press
		if (!(PIND&(1<<PIND2)))
		{
			_delay_ms(50); // debouce
			doublePress=1;// if second press occured within 500ms, the doublepress counter will become 1
		}
	}
}


void toggle_LED()
{
	PORTC^=(1<<PORTC2);
	doublePress=0; //reset counter
}


int main(void)
{
	DDRD&= ~(1<<DDD2);
	PORTD|=(1<<PORTD2);
	DDRC|=(1<<PORTC2);
	doublePress=0;
	
	while (1)
	{
		if (!(PIND&(1<<PIND2)))
		{	
			while_check();
			doublePress_check();
			if (doublePress)
			{
				toggle_LED();
			}
		}
	}
	

}