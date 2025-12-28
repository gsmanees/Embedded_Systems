/*
 * oled.c
 *
 *  Created on: 27-Dec-2025
 *      Author: anees
 */


#include "oled.h"
#include "ssd1306_basic.h"

void OLED_Init(void) {
    SSD1306_Init();
    OLED_Clear();
}

void OLED_Clear(void) {
    for(uint16_t i=0;i<128*8;i++) {
        SSD1306_WriteData(0x00);
    }
}

void OLED_SetCursor(uint8_t x, uint8_t y) {
    // minimal: x = 0-127, y = 0-7
    SSD1306_WriteCommand(0xB0 + y);            // page
    SSD1306_WriteCommand(((x & 0xF0)>>4)|0x10); // column high
    SSD1306_WriteCommand(x & 0x0F);            // column low
}

void OLED_Putc(char ch, uint8_t x, uint8_t y) {
    OLED_SetCursor(x, y);
    SSD1306_Putc(ch, x, y);
}
