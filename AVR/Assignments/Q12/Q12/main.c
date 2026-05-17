/*
 * Q12.c
 *
 * Created: 17-05-2026 3.38.35 PM
 * Author : anees
 
 Objective: Write a program to show a 9-digit number on an LCD screen that increases 
 with a quick button press and resets to zero with a long press.
 
 Requirements: The system must use a 16x2 LCD and one push-button. On the screen, 
 the counter should start at 000000000. When you press and let go of the button quickly, 
 the count should go up by 1. If you hold the button down for 2 seconds or more, the 
 counter must clear and go back to 0. The program needs to use functions to check how 
 long the button is held and to update the number on the LCD screen.
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "lcd.h"

#define BUTTON PB0
unsigned long count=0;

void display_number(unsigned long num)
{
	char txt[10];
	sprintf(txt,"%09lu",num);  //Convert number into 9-digit string
	lcd_home();
	lcd_print(txt);
}

void check_button()
{
	if(!(PINB&(1<<BUTTON)))   // Check button pressed or  not
	{
		unsigned int time=0;
		_delay_ms(20);
		
		while(!(PINB&(1<<BUTTON))) //Measure how long button is pressed
		{
			_delay_ms(10);
			time+=10;
		}

		// press time calculation
		if(time>=2000)  //Long Press
		{
			count=0;
		}
		else
		{
			count++;   //Short Press
		}

		lcd_clear();
		display_number(count);
		_delay_ms(200);
	}
}

int main(void)
{
	DDRB&=~(1<<BUTTON);  // pb0 as input
	PORTB|=(1<<BUTTON);   // enabled internal pull up
	
	lcd_init();
	display_number(count);

	while(1)
	{
		check_button();
	}
}