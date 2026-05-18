/*
 * command.c
 *
 * Created: 17-05-2026 6.07.30 PM
 *  Author: anees
 */ 

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "command.h"
#include "uart.h"
#include "pwm.h"

void Process_Command(char *cmd)
{
	int value;
	if(strcmp(cmd, "ON")==0)
	{
		PWM_SetBrightness(100);
		UART_TxString("LED is now ON\r\n");
	}

	else if(strcmp(cmd, "OFF")==0)
	{
		PWM_SetBrightness(0);
		UART_TxString("LED is now OFF\r\n");
	}

	else
	{
		value = atoi(cmd);
		if(value>=0&&value<=100)
		{
			PWM_SetBrightness(value);
			char msg[40];
			sprintf(msg,"Brightness set to %d%%\r\n",value);
			UART_TxString(msg);
		}
		else
		{
			UART_TxString("Invalid Command\r\n");
		}
	}
}