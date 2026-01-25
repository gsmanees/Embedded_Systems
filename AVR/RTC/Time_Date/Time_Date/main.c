/*
 * Time_Date.c
 *
 * Created: 25-01-2026 6.10.14 PM
 * Author : anees
 
 RTC connections 
 VCC	5V
 SDA	ARDUINO SDA 
 SCL	ARDUINO SCL
 
 OLED CONNECTIONS
 VCC	3.3V
 SCK	ARDUINO SCK
 SCL	ARDUINO SCL
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
	
	uint8_t hh, mm, ss, dd, mon, yy;

	UART_Init();
	TWI_Init();
	OLED_Init();
	OLED_Clear();

	/*UART_TxString("DS1307 TEST\r\n");*/
	/*	DS1307_StartClock(); */
	/*DS1307_SetTime(11, 37, 20);*/
	// SET DATE ONCE ONLY
	/*DS1307_SetDate(25, 01, 26);   */

	
	while (1)
	{
		// 		sec_raw = DS1307_ReadSeconds();
		// 		sec = BCD_to_DEC(sec_raw & 0x7F); // mask CH bi

		DS1307_ReadTimeDate(&hh, &mm, &ss, &dd, &mon, &yy);
		
		UART_TxNumber(hh);
		UART_TxString(":");
		UART_TxNumber(mm);
		UART_TxString(":");
		UART_TxNumber(ss);
		
		UART_TxString("\r\n");
		
		UART_TxNumber(dd);
		UART_TxString(":");
		UART_TxNumber(mon);
		UART_TxString(":");
		UART_TxNumber(yy);
		UART_TxString("\r\n");
		
		
		// OLED printing
		OLED_SetCursor(3, 25);
		OLED_PrintTime(hh, mm, ss); // SSD1306, address: 0x3c
		
		
		// date printing 
		OLED_SetCursor(5, 25);
		OLED_PrintDate(dd, mon, yy);
		
		_delay_ms(1000);
	}
}




