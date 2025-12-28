/*
 * oled_i2c.c
 *
 * Created: 28-12-2025 8.30.32 AM
 * Author : anees
 */ 


#include "i2c.h"
#include "oled.h"

int main(void)
{
	I2C_Init();
	OLED_Init();
	OLED_Clear();
	
	OLED_SetCursor(1,0);
	OLED_String("    OLED I2C driver");
	OLED_SetCursor(2,0);
	OLED_String("       ________");
	OLED_SetCursor(4,0);
	OLED_String("     Developed by ");
	OLED_SetCursor(6,0);
	OLED_String("    Anees Kokadan");

	while (1);
}


