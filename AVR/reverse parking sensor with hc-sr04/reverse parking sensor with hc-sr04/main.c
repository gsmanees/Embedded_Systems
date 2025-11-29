/*
 * reverse parking sensor with hc-sr04.c
 *
 * Created: 30-11-2025 12.06.22 AM
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
	float distance=0;
	hcsr04_IO_Init();
	UART_Init();
	lcd_init();
	LED_init();
	while (1)
	{
		hcsr04_EN_trigger();
		distance=10*measure_distance();
		
		if (distance<=10)
		{
			red_LED();
			stop();
			_delay_ms(500);
			
		}
		else if (distance>10)
		{
			green_LED();
		}
		
		
		// uart print
		UART_TxString("\nDistance: ");
		UART_TxFloat(distance, 2);UART_TxString(" cm");
		
		
		//lcd printing
		lcd_clear();
		lcd_set_cursor(0,0);
		lcd_print("Distance: ");
		lcd_set_cursor(1,0);
		lcd_print_float(distance, 2);lcd_print(" cm");
		_delay_ms(500);
		
		
		
	}
}

