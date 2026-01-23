/*
 * RTC_SEC_OLED.c
 *
 * Created: 22-01-2026 9.20.13 AM
 * Author : anees
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include <string.h>
#include "i2c.h"
#include "uart.h"
#include "ds1307.h"
#include "oled.h"


int main(void)
{
	
	uint8_t hh, mm, ss;

	UART_Init();
	TWI_Init();
	OLED_Init();
	OLED_Clear();

	UART_TxString("DS1307 TEST\r\n");
	/*	DS1307_StartClock(); */
	/*DS1307_SetTime(11, 37, 20);*/
	
	while (1)
	{
// 		sec_raw = DS1307_ReadSeconds();
// 		sec = BCD_to_DEC(sec_raw & 0x7F); // mask CH bit

		DS1307_ReadTime(&hh, &mm, &ss); // DS1307, address: 0x68


		
		UART_TxNumber(hh); 
		UART_TxString(":");
		UART_TxNumber(mm);
		UART_TxString(":");
		UART_TxNumber(ss);
	
		UART_TxString("\r\n");
		
		// OLED printing 
		OLED_SetCursor(3, 25);
		OLED_PrintTime(hh, mm, ss); // SSD1306, address: 0x3c
	
		

		_delay_ms(1000);
	}
}




