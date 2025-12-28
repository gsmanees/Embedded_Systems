/*
 * oled.h
 *
 *  Created on: 27-Dec-2025
 *      Author: anees
 */

#ifndef OLED_H
#define OLED_H

#include <stdint.h>

void OLED_Init(void);
void OLED_Clear(void);
void OLED_SetCursor(uint8_t x, uint8_t y);
void OLED_Putc(char ch, uint8_t x, uint8_t y);

#endif

