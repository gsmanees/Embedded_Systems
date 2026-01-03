/*
 * cmd.c
 *
 * Created: 02-01-2026 10.32.19 PM
 *  Author: anees
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

void checkCMD(void)
{

	if (strcmp(cmd, "green led on") == 0)
	{
		GreenLED_On();
		UART_TxString("GREEN LED ON\r\n");
	}
	else if (strcmp(cmd, "green led off") == 0)
	{
		GreenLED_Off();
		UART_TxString("GREEN LED OFF\r\n");
	}
	
	else if (strcmp(cmd,"red led on")==0)
	{
		RedLED_on();
		UART_TxString("RED LED ON\r\n");
	}
	
	else if (strcmp(cmd,"red led off")==0)
	{
		RedLED_off();
		UART_TxString("RED LED OFF\r\n");
	}
	
	else if (strcmp(cmd,"both led on")==0)
	{
		RedLED_on();
		GreenLED_On();
		UART_TxString("Both LEDs are ON !\r\n");
	}
	
	else if (strcmp(cmd,"both led off")==0)
	{
		RedLED_off();
		GreenLED_Off();
		UART_TxString("Both LEDs are OFF !\r\n");
	}
	
	else if (strcmp(cmd,"dance")==0)
	{
		dance();
		UART_TxString("Dancing !\r\n");
	}
	
	else if (strcmp(cmd,"stop")==0)
	{
		bothLED_off();
		UART_TxString("Both LEDs are OFF !\r\n");
	}
	
	
	else if (strcmp(cmd,"help")==0)
	{
		menu();
	}
	
	else if (strcmp(cmd,"toggle red")==0)
	{
		toggleRed();
		UART_TxString("Red LED toggling !\r\n");
	}
	
	else if (strcmp(cmd,"toggle green")==0)
	{
		toggleGreen();
		UART_TxString("Green LED toggling !\r\n");
	}
	
	else
	{
		UART_TxString("Use: on | off\r\n");
	}

	UART_TxString("> ");
}


void menu(void)
{
	UART_TxString("UART CLI Help Menu\r\n");
	UART_TxString("red led on --> to make RED LED ON\r\n");
	UART_TxString("red led off --> to make RED LED OFF\r\n");
	UART_TxString("green led on --> to make GREEN LED ON\r\n");
	UART_TxString("green led off --> to make GREEN LED OFF\r\n");
	UART_TxString("both led on --> to make both LEDs ON\r\n");
	UART_TxString("both led off --> to make both LEDs OFF\r\n");
	UART_TxString("dance --> to dance both LEDs \r\n");
	UART_TxString("toggle red --> to toggle red led \r\n");
	UART_TxString("toggle green --> to togggle green led\r\n");
	UART_TxString("stop --> to stop the dancing & current task and return to start \r\n");
}