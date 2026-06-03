
/*
 * uart.c
 *
 * Created: 03-06-2026 011:22:19 AM
 *  Author: anees
 */ 



#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "i2c.h"
#include "oled.h"
#include "uart.h"

int main(void)
{
	char buffer[32];
	uint8_t index = 0;

	UART_Init();

	I2C_Init();

	OLED_Init();

	while (1)
	{
		char rx = UART_RxChar();

		UART_TxChar(rx);      // Echo back to terminal

		if ((rx == '\r') || (rx == '\n'))
		{
			UART_TxChar('\r');
			UART_TxChar('\n');

			for (uint8_t i = 0; i < index; i++)
			{
				OLED_Data(buffer[i]);

				_delay_ms(1000);   // 1 second gap for DSO viewing
			}

			index = 0;
		}
		else
		{
			if (index < sizeof(buffer) - 1)
			{
				buffer[index++] = rx;
			}
		}
	}
}