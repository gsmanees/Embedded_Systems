/*
 * RTC.c
 *
 * Created: 21-01-2026 11.41.49 PM
 * Author : anees
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include "i2c.h"
#include "uart.h"
#include "ds1307.h"


int main(void)
{
	uint8_t sec_raw, sec;

	UART_Init();
	TWI_Init();

	UART_TxString("DS1307 TEST\r\n");
/*	DS1307_StartClock(); */
	while (1)
	{
		sec_raw = DS1307_ReadSeconds();
		sec = BCD_to_DEC(sec_raw & 0x7F); // mask CH bit

		UART_TxString("SEC: ");
		UART_TxNumber(sec);
		UART_TxString("\r\n");

		_delay_ms(1000);
	}
}


