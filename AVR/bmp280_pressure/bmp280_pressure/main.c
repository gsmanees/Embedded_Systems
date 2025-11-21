/*
 * bmp280_pressure.c
 *
 * Created: 18-11-2025 10.26.07 PM
 * Author : anees
 
 Pressure measurement by bmp280
 
 Quick overview (steps)
 Configure BMP280 (control and config registers) — set pressure oversampling, temp oversampling and mode.
 Read raw pressure ADC (20 bits: PRESS_MSB, PRESS_LSB, PRESS_XLSB).
 Use the temperature routine to compute t_fine first (pressure compensation requires it).
 Apply the pressure compensation algorithm from the datasheet using calibration params dig_P1 .. dig_P9.
 Result is pressure in Pa (Pascal). Convert to hPa by dividing by 100 if you want millibar units.

 Important registers (addresses)
 Chip ID: 0xD0 (should read 0x58)
 Calibration start: 0x88 (read all calibration params here: dig_T1..dig_T3, dig_P1..dig_P9)
 Pressure raw registers: 0xF7 (MSB), 0xF8 (LSB), 0xF9 (XLSB)
 Temperature raw registers: 0xFA..0xFC (you already use these)
 Control: 0xF4 — bits: [7:5] osrs_t, [4:2] osrs_p, [1:0] mode
 Config: 0xF5 — standby, filter, spi3w_en

 Recommended settings
 osrs_t = x1 (temperature oversampling) — you already have this.
 osrs_p = x4 or x8 for stable pressure (higher oversampling ? better noise performance, slower).
 mode = normal (or forced if you only want single readings).
 config: set filter as needed (e.g., filter = 4) and standby to a suitable ms in normal mode
 Pressure compensation algorithm (concept)
 Read raw adc_P (20-bit).
 Use t_fine from temp compensation (must calculate first).
 Apply 64-bit integer math exactly as Bosch shows to prevent overflow and retain precision.
 Final value p is in Pa (Q24.8 format in many references; dividing by 256 yields Pa in their integer math, 
 so final convert accordingly).
 
 
 
 
 
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "bmp280.h"
#include "spi.h"
#include "uart.h"
#include "lcd.h"

int main(void)
{
	SPI_init();
	UART_Init();
	lcd_init();

    
    while (1) 
    {
		
		
		ctrl_meas();
		//getChip_ID();
		//getMSB();getLSB();getxLSB();
		//get_dig_T1();get_dig_T2();get_dig_T3();
		
		getRawTemp();
		
		AtmosTrack(); // print brand name
		realTemp();
		
		readCalib();
		getRawPressure();
		realPressure();
	
		_delay_ms(1000);
		
    }
}

