/*
 * oled.h
 *
 * Created: 28-12-2025 8.33.40 AM
 *  Author: anees
 */ 


#ifndef SSD1306_H
#define SSD1306_H

#include <stdint.h>

void OLED_Init(void);
void OLED_Command(uint8_t cmd);
void OLED_Data(uint8_t data);
void OLED_Clear(void);
void OLED_SetCursor(uint8_t page, uint8_t col);
void OLED_Char(char c);
void OLED_String(char *str);
void OLED_CharBig(char c);
void OLED_StringBig(char *str);
void OLED_DrawBigDigit(uint8_t page, uint8_t col, uint8_t digit);

#endif
