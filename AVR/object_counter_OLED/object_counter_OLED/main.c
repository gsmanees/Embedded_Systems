/*
 * object_counter_OLED.c
 *
 * Created: 30-12-2025 9.23.16 PM
 * Author : anees
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <stdio.h>
#include "hcsr04.h"
#include "uart.h"
#include "oled.h"
#include "i2c.h"
#include "button.h"

// variable declarations
int obj_present=0;
volatile int obj_count=0;
float distance=0;
volatile uint8_t counter_run = 0;
char buffer[32];

// counting function
void count(void)
{
	hcsr04_EN_trigger();
	distance=10*measure_distance();

	if (distance<=10 && obj_present==0)
	{
		obj_count++;
		obj_present=1;
	}

	else if (distance>10)
	{
		obj_present=0;
	}
}

// printing function
void printCount(void)
{
	/* Bottom Left: START / STOP */
	OLED_SetCursor(7, 0);
	if (counter_run)
	OLED_String("  STOP ");
	else
	OLED_String("  START");

	/* Bottom Right: RESET */
	OLED_SetCursor(7, 90);
	OLED_String("RESET");
	
	//OLED printing
	OLED_SetCursor(0,25);
	OLED_String("Object Counter");
	OLED_SetCursor(3, 65);
	sprintf(buffer,"%2d", obj_count);
	OLED_String(buffer);
}

int main(void)
{
	// initializations
	Button_Init();
	I2C_Init();
	hcsr04_IO_Init();
	OLED_Init();
	OLED_Clear();
	
	while (1)
	{
		if (Button_Pressed(START_STOP_BTN))
		{
			counter_run ^= 1;
		}
		
		if (Button_Pressed(RESET_BTN))
		{
			counter_run = 0;
			obj_count=0;
		}
		
		if (counter_run)
		{
			count();
		}
		
		printCount();
	}
}


