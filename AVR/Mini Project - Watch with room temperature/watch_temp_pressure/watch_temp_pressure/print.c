/*
 * print.c
 *
 * Created: 26-01-2026 1.18.16 AM
 *  Author: anees
 */ 


void printTimeDate(void)
{
			UART_printTime();
			UART_printDate();
			
			OLED_printTime();
			OLED_printDate();
}

void printTemperature(void)
{
			// bmp 280
			ctrl_meas();
			getRawTemp();
			realTemp();
			
			readCalib();
			getRawPressure();
			realPressure();
}