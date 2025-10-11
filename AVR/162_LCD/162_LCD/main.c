/*
 * 162_LCD.c
 *
 * Created: 10-10-2025 7.49.30 PM
 * Author : anees
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"

int main(void)
{
	lcd_init();
	lcd_set_cursor(0, 0);
	lcd_print("Hello LCD");

	lcd_set_cursor(1, 0);
	lcd_print("It works! ");

	// small demo: print a number
	//lcd_print_uint16(1234);

	while (1)
	{
		

	}
}


