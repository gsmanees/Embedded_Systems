/*
 * Atmostrack_CLI.c
 *
 * Created: 21-01-2026 6.39.21 AM
 * Author : anees
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "bmp280.h"
#include "spi.h"
#include "uart.h"
#include "global.h"
#include "cli.h"

// extern already declared on global.h
uint8_t idx = 0;
uint8_t cmd_ready = 0;
char cmd[32];

ISR(USART_RX_vect)
{
	char c = UDR0;
	if (c == '\r' || c == '\n')
	{
		cmd[idx] = '\0';
		idx = 0;
		cmd_ready = 1;
	}
	else if (idx < sizeof(cmd)-1)
	{
		cmd[idx++] = c;
	}
}


int main(void)
{
	UART_Init();
	SPI_init();
	sei();
	
	while (1)
	{
		if (!cmd_ready) continue;
		cmd_ready = 0;
		checkCMD();	
	}
}

