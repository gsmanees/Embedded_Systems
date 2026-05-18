/*
 * Q15.c
 *
 * Created: 17-05-2026 7.40.15 PM
 * Author : anees
 
 Objective: Write a program to read temperature data and pressure from a BMP280 sensor and 
 display the real-time value on an OLED screen.
 
 Requirements: The system must use the I2C protocol to communicate with both the BMP280 sensor and 
 a 128x64 OLED display. The program should first initialize
 both devices on the I2C bus. It must then read the raw temperature data from the BMP280, 
 convert it into Celsius, and format the result as a string. Finally, the program must clear 
 the OLED screen and display the current temperature in a readable format. The sensor reading and 
 display updating should happen every 2 seconds.
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <stdint.h>
#include "i2c.h"
#include "oled.h"
#include "bmp280.h"

char tempBuffer[20];
char pressBuffer[20];

int main(void)
{
	float temperature;
	float pressure;

	I2C_Init();
	OLED_Init();
	OLED_Clear();
	BMP280_Init();

	while(1)
	{
		temperature = BMP280_ReadTemperature();
		pressure = BMP280_ReadPressure();
		dtostrf(temperature,5,2,tempBuffer);  // formatting Temperature value as string 
		dtostrf(pressure,6,2,pressBuffer);  // formatting pressure value as string 
		
		// Temperature printing
		OLED_SetCursor(2,4);
		OLED_String("Temperature:");
		OLED_SetCursor(3,4);
		OLED_String(tempBuffer);
		OLED_String(" C");
		
		// Pressure printing 
		OLED_SetCursor(6,4);
		OLED_String("Pressure:");
		OLED_SetCursor(7,4);
		OLED_String(pressBuffer);
		OLED_String(" hPa");

		_delay_ms(2000);  // OLED values updates every 2 seconds
	}
}