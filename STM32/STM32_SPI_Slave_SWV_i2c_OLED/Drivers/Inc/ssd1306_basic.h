/*
 * ssd1306_basic.h
 *
 *  Created on: 27-Dec-2025
 *      Author: anees
 */

#ifndef SSD1306_BASIC_H
#define SSD1306_BASIC_H

#include "stm32f446xx_i2c_driver.h"
#include <stdint.h>

#define SSD1306_ADDRESS 0x3C

// External I2C handle
extern I2C_Handle_t hi2c1;

// Screen buffer
#define SSD1306_WIDTH 128
#define SSD1306_HEIGHT 64
extern uint8_t SSD1306_Buffer[SSD1306_WIDTH * SSD1306_HEIGHT / 8];

// Function prototypes
void SSD1306_WriteCommand(uint8_t cmd);
void SSD1306_WriteData(uint8_t* data, uint16_t size);
void SSD1306_Init(void);
void SSD1306_UpdateScreen(void);
void SSD1306_Putc(char c, uint8_t x, uint8_t y);

// Optional: simple font
extern const uint8_t Font5x7[];

#endif
