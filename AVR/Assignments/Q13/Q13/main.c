/*
 * Q13.c
 *
 * Created: 17-05-2026 6.01.14 PM
 * Author : anees
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include "uart.h"
#include "pwm.h"
#include "command.h"

int main(void)
{
	char buffer[20];
	uint8_t index = 0;

	UART_Init();
	PWM_Init();

	UART_TxString("System Ready\r\n");
	UART_TxString("ON: to make LED ON\r\n");
	UART_TxString("OFF: To make LED OFF\r\n");
	UART_TxString("Any value between 0-100: To set LED brightness\r\n");

	while(1)
	{
		char ch=UART_RxChar();
		if(ch=='\r'||ch=='\n')   // check command end
		{
			buffer[index]='\0';
			Process_Command(buffer);
			index=0;
		}
		else
		{
			if(index<sizeof(buffer)-1)
			{
				buffer[index++]=ch;
			}
		}
	}
}