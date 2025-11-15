/*
 * bmp280_temp_practice1.c
 *
 * Created: 13-11-2025 6.22.59 AM
 * Author : anees
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "spi.h"
#include "uart.h"
#include "bmp280.h"


int main(void)
{
	
	// SPI initialization
	SPI_init();
	
	// UART initialization
	UART_Init();
    
    while (1) 
    {
		getChip_ID(); // calling function to read chip ID, which is inside bmp.h
    }
}

