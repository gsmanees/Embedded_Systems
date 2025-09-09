/*
 * pd3_switch_ActiveLOW.c
 *
 * Created: 09-09-2025 7.06.16 AM
 * Author : anees
 
  Write a program to Turn on an LED Connected to PD3 pin of an ATMEGA 328 when a switch connected to PC0 is pressed(show active high and low connections in the switch). Simulate in SiumulIDE.
  here i have written program for Switch Active LOW
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>


int main(void)
{
	DDRC = 0b00000000;
	PORTC = 0b00000001; // Enabled internal pull up for C0
	
	DDRD = 0b00001000;
	
    while (1) 
    {
		if (PINC == 0b00000000)
		PORTD = 0b00001000;
		else
		PORTD = 0b00000000;
    }
}

