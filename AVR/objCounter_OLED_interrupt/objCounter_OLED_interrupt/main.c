/*
 * objCounter_OLED_interrupt.c
 *
 * Created: 31-12-2025 9.24.05 PM
 * Author : anees
 
 hcsr04 connections
 TRIG--> PB0
 ECHO --> PB1
 VCC --> 5V
 
 buttons connections
 STRT/STOP --> PD2
 RESET --> PD3
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

// global variables declarations 
volatile uint16_t sys_tick = 0;
volatile uint8_t count_flag = 0;
volatile uint8_t display_flag = 0;

int obj_present = 0;
volatile int obj_count = 0;
float distance = 0;
volatile uint8_t counter_run = 0;
char buffer[32];


// Timer0 ISR (scheduler only)
ISR(TIMER0_OVF_vect)
{
	sys_tick++; 
	// increment every 1ms
	// timer0 pre scalar is 64

	//Object detection every 50 ms
	if (sys_tick % 50 == 0)
	{
		count_flag = 1;
	}

	//OLED update every 200 ms
	if (sys_tick % 200 == 0)
	{
		display_flag = 1;
	}
}

// Object counting function
void count(void)
{
	hcsr04_EN_trigger();
	distance = 10 * measure_distance();

	if (distance <= 10 && obj_present == 0)
	{
		obj_count++;
		obj_present = 1;
	}
	else if (distance > 10)
	{
		obj_present = 0;
	}
}

//OLED printing function
void printCount(void)
{
	OLED_SetCursor(7, 0);
	if (counter_run)
	OLED_String("  STOP ");
	else
	OLED_String("  START");

	OLED_SetCursor(7, 90);
	OLED_String("RESET");

	OLED_SetCursor(0, 25);
	OLED_String("Object Counter");

	OLED_SetCursor(3, 65);
	sprintf(buffer, "%2d", obj_count);
	OLED_String(buffer);
}

// main function
int main(void)
{
	Button_Init();
	I2C_Init();
	hcsr04_IO_Init();
	OLED_Init();
	OLED_Clear();
	Timer0_Init();

	sei(); // global interrupts enabled

	while (1)
	{
		// Button handling
		if (Button_Pressed(START_STOP_BTN))
		{
			counter_run ^= 1;
		}

		if (Button_Pressed(RESET_BTN))
		{
			counter_run = 0;
			obj_count = 0;
		}

		// Object counting task as per ISR flag
		if (count_flag && counter_run)
		{
			count_flag = 0;
			count();
		}

		// Display printing task as per ISR flag
		if (display_flag)
		{
			display_flag = 0;
			printCount();
		}
	}
}
