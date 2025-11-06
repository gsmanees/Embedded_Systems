/*
 * Final_Environment_Project.c
 *
 * Created: 02-11-2025 3.36.13 PM
 * Author : anees
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"
#include "spi.h"
#include "bmp280.h"

int main(void)
{
	uint32_t rawTemp;
	uint32_t Chip_ID;

	UART_Init();
	spi_init();
	_delay_ms(10);               // Allow BMP280 to settle
	bmp280_configure();

	rawTemp = bmp280_readTempRegisters();

	while (1)
	{
		UART_TxString("Chip_ID: ");
		//UART_TxHex(bmp280_readChipID());
		Chip_ID=bmp280_readChipID();
		UART_TxHex(Chip_ID);
		UART_TxString("RawTemp: ");
		UART_TxNumber(rawTemp);
		UART_TxChar('\n');
		_delay_ms(500);
	}
}
