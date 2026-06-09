/*
 * ReverseCarParking_OLED.c
 *
 * Created: 09-06-2026 10.20.08 PM
 * Author : anees
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#include "hcsr04.h"
#include "uart.h"
#include "i2c.h"
#include "oled.h"

int main(void)
{
	float distance = 0;
	char buffer[15];

	hcsr04_IO_Init();
	LED_init();

	UART_Init();

	I2C_Init();
	OLED_Init();

	while (1)
	{
		hcsr04_EN_trigger();
		distance = 10*measure_distance();

		// UART Output
		UART_TxString("\nDistance: ");
		UART_TxFloat(distance, 2);
		UART_TxString(" cm");

		OLED_Clear();

		if(distance <= 7)
		{
			red_LED();

			OLED_SetCursor(2,35);
			OLED_String("WARNING!");

			OLED_SetCursor(4,30);
			OLED_String("TOO CLOSE");

			OLED_SetCursor(6,25);
			OLED_String("DIST:");

			dtostrf(distance, 5, 2, buffer);
			OLED_String(buffer);
			OLED_String("cm");
		}
		else
		{
			green_LED();

			OLED_SetCursor(2,35);
			OLED_String("DISTANCE");

			dtostrf(distance, 5, 2, buffer);

			OLED_SetCursor(4,35);
			OLED_String(buffer);

			OLED_SetCursor(4,75);
			OLED_String("cm");
		}

		_delay_ms(500);
	}
}