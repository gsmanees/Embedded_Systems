/*
 * blink5LEDs_modular.c
 *
 * Created: 29-09-2025 6.16.16 AM
 * Author : anees
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include "gpio.h"
#include "delay.h"




int main(void)
{
    init_pins();
    while (1) 
    {
		output_pins();
		delay_2s();
		PORTB&=0;
		delay_2s();
    }
}

