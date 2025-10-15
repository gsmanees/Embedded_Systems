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
	lcd_set_cursor(0, 2);
	lcd_print("Anees Kokadan");

	lcd_set_cursor(1, 6);
	//lcd_print("3.14");
	
	_delay_ms(1000);
	//lcd_clear();
	//lcd_set_cursor(0,0);
	
	

	// small demo: print a number
	//lcd_print_uint16(1532);
	lcd_clear();
	lcd_set_cursor(0,0);
	lcd_print("Float: ");
	lcd_set_cursor(1,0);
	lcd_print_float(12.345, 3);

	while (1)
	{
		

	}
}


