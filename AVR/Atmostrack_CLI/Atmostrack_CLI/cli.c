/*
 * cli.c
 *
 * Created: 21-01-2026 6.48.40 AM
 *  Author: anees
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h>
#include <util/delay.h>
#include "uart.h"
#include "global.h"
#include "cli.h"
#include "spi.h"
#include "bmp280.h"


void checkCMD()
{
	if (strcmp(cmd, "read temperature") == 0)
	{
		ctrl_meas();
		getRawTemp();
		readCalib();
		realTemp();
		getRawPressure();
	}
	
	else if (strcmp(cmd, "read pressure") == 0)
	{
		ctrl_meas();
		getRawTemp();
		readCalib();
		getRawPressure();
		realPressure();
	}
	
	else
	{
		UART_TxString("\nEnter valid command");
	}
}