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
void OLED_PrintBigNumber(uint8_t page, uint8_t col, uint16_t number);
void OLED_DrawPixel(uint8_t, uint8_t, uint8_t);
void OLED_DisplayCount(uint8_t page, uint8_t col, uint16_t count);
void OLED_DisplayCount_Font11x18(uint8_t startPage, uint8_t col, uint16_t count);
void OLED_PrintFont11x18_Digit(uint8_t page, uint8_t col, uint8_t digit);
void OLED_PrintChar(char c);
void OLED_Print2Digit(uint8_t num);
void OLED_PrintTime(uint8_t hh, uint8_t mm, uint8_t ss);
void OLED_PrintDate(uint8_t dd, uint8_t mm, uint8_t yy);

#endif
