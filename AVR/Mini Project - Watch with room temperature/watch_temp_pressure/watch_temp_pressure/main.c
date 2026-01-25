/*
 * watch_temp_pressure.c
 *
 * Created: 25-01-2026 10.44.23 PM
 * Author : anees
 
  RTC connections
  VCC	5V
  SDA	ARDUINO SDA
  SCL	ARDUINO SCL
  
  OLED CONNECTIONS
  VCC	3.3V
  SCK	ARDUINO SCK
  SCL	ARDUINO SCL
 
 this watch shows time, date, atmospheric temperature and atmospheric pressure
 
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
#include "spi.h"
#include "bmp280.h"
#include "global.h"
#include "print.h"


int main(void)
{	
	TWI_Init();
	SPI_init();
	UART_Init();
	OLED_Init();
	OLED_Clear();

	/*	DS1307_StartClock(); */
	/*DS1307_SetTime(11, 37, 20);*/
	// SET DATE ONCE ONLY
	/*DS1307_SetDate(25, 01, 26);   */

	
	while (1)
	{

		DS1307_ReadTimeDate(&hh, &mm, &ss, &dd, &mon, &yy);
		printTimeDate();
		printTemperature();
		_delay_ms(1000);
	}
}






