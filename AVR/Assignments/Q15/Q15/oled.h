/*
 * oled.h
 *
 * Created: 18-05-2026 6.05.18 AM
 *  Author: anees
 */ 

#include <avr/io.h>
#ifndef OLED_H_
#define OLED_H_

void OLED_Command(uint8_t cmd);
void OLED_Data(uint8_t data);
void OLED_Init(void);
void OLED_Clear(void);
void OLED_SetCursor(uint8_t row, uint8_t col);
void OLED_Char(char ch);
void OLED_String(char *str);



#endif /* OLED_H_ */