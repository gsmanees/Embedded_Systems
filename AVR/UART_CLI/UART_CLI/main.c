/*
 * UART_CLI.c
 *
 * Created: 02-01-2026 6.43.33 AM
 * Author : anees
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h>
#include <util/delay.h>
#include "uart.h"
#include "led.h"
#include "global.h"
#include "cmd.h"

// extern already declared on global.h
uint8_t idx = 0;
uint8_t cmd_ready = 0;
uint8_t danceFlag = 0;
char cmd[16];


ISR(USART_RX_vect)
{
	char c = UDR0;

	if (c == '\r' || c == '\n')
	{
		cmd[idx] = '\0';
		idx = 0;
		cmd_ready = 1;
		danceFlag=1;
	}
	else if (idx < sizeof(cmd)-1)
	{
		cmd[idx++] = c;
	}
}

int main(void)
{
	LED_Init();
	UART_Init();
	sei();

	UART_TxString("LED CLI Ready\r\n> ");

	while (1)
	{
		if (!cmd_ready) continue;
		cmd_ready = 0;
		checkCMD();
	}
}


