/*
 * HC_SR04_Object_Counter.c
 *
 * Created: 22-12-2025 8.17.24 PM
 * Author : anees
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "hcsr04.h"
#include "lcd.h"
#include "uart.h"


int main(void)
{
	int obj_present=0;
	int obj_count=0;
	float distance=0;
	hcsr04_IO_Init();
	UART_Init();
	lcd_init();
	LED_init();
	
	while (1)
	{
		hcsr04_EN_trigger();
		distance=10*measure_distance();
		
		if (distance<=10 && obj_present==0)
		{
			red_LED();
			_delay_ms(500);
			obj_count++;
			obj_present=1;
			
		}
		
		else if (distance>10)
		{
			green_LED();
			obj_present=0;
		}
		
	
		// uart print
		UART_TxString("\nCount:");
		UART_TxNumber(obj_count);
		
		
		//lcd printing
		lcd_clear();
		lcd_set_cursor(0,0);
		lcd_print("Count: ");
		lcd_set_cursor(1,0);
		lcd_print_uint16(obj_count);
		_delay_ms(500);
	}
}

