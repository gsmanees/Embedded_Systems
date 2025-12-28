/*
 * stopWatch_i2c_OLED.c
 *
 * Created: 28-12-2025 2.01.07 PM
 * Author : anees
 */ 

#define F_CPU 16000000UL
#include "oled.h"
#include "i2c.h"
#include "button.h"
#include "timer.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>

/* ---------------- Global Variables ---------------- */
volatile uint16_t ms = 0;
volatile uint8_t sec = 0;
volatile uint8_t min = 0;

volatile uint8_t stopwatch_run = 0;   // 0 = STOP, 1 = RUN


/* ---------------- Timer0 ISR ---------------- */
ISR(TIMER0_OVF_vect)
{
	if (stopwatch_run)
	{
		ms++;

		if (ms >= 1000)
		{
			ms = 0;
			sec++;

			if (sec >= 60)
			{
				sec = 0;
				min++;
			}
		}
	}
}

/* ---------------- Main ---------------- */
int main(void)
{
	char buffer[16];
	I2C_Init();
	Button_Init();
	Timer0_Init();
	sei(); 
	OLED_Init();
	OLED_Clear();

	while (1)
	{
		/* START / STOP button */
		if (Button_Pressed(START_STOP_BTN))
		{
			stopwatch_run ^= 1;   // Toggle
		}

		/* RESET button */
		if (Button_Pressed(RESET_BTN))
		{
			stopwatch_run = 0;
			ms = 0;
			sec = 0;
			min = 0;
		}

		/* Display Time */
		OLED_SetCursor(0, 35);
		OLED_String("Stop Watch ");
		OLED_SetCursor(3, 35);
		sprintf(buffer,"%02d:%02d:%03d", min, sec, ms);
		OLED_String(buffer);

		/* Bottom Left: START / STOP */
		OLED_SetCursor(7, 0);
		if (stopwatch_run)
		OLED_String("  STOP ");
		else
		OLED_String("  START");

		/* Bottom Right: RESET */
		OLED_SetCursor(7, 90);
		OLED_String("RESET");

		_delay_ms(50);   // Display refresh delay
	}
}


