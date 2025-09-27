/*
 * modular_delay.c
 *
 * Created: 26-09-2025 8.27.57 PM
 * Author : anees
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include "sreejith.h"

int main(void)
{
    DDRB|=(1<<DDB5);
    while (1) 
    {
		PORTB^=(1<<PORTB5);
		anees(1000);
    }
}

