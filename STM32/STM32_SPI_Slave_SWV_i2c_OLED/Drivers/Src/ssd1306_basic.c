/*
 * ssd1306_basic.c
 *
 *  Created on: 27-Dec-2025
 *      Author: anees
 */


#include "ssd1306_basic.h"

// Screen buffer
uint8_t SSD1306_Buffer[SSD1306_WIDTH * SSD1306_HEIGHT / 8];

// Example 5x7 font
const uint8_t Font5x7[] = {
    // Add your font bytes here (ASCII 32..127)
};

// Low-level I2C send (adapted to your driver)
void SSD1306_WriteCommand(uint8_t cmd)
{
    uint8_t buf[2];
    buf[0] = 0x00;  // Co = 0, D/C# = 0
    buf[1] = cmd;
    I2C_Master_Transmit(&hi2c1, SSD1306_ADDRESS, buf, 2);
}

void SSD1306_WriteData(uint8_t* data, uint16_t size)
{
    uint8_t buf[size + 1];
    buf[0] = 0x40; // Co = 0, D/C# = 1
    for(uint16_t i = 0; i < size; i++)
        buf[i+1] = data[i];
    I2C_Master_Transmit(&hi2c1, SSD1306_ADDRESS, buf, size + 1);
}

void SSD1306_UpdateScreen(void)
{
    for(uint8_t page = 0; page < 8; page++)
    {
        SSD1306_WriteCommand(0xB0 + page); // Set page
        SSD1306_WriteCommand(0x00);        // Set lower column
        SSD1306_WriteCommand(0x10);        // Set higher column
        SSD1306_WriteData(&SSD1306_Buffer[SSD1306_WIDTH * page], SSD1306_WIDTH);
    }
}

void SSD1306_Init(void)
{
    // Initialize hi2c1 before calling this
    SSD1306_WriteCommand(0xAE); // Display off
    SSD1306_WriteCommand(0x20); // Set Memory Addressing Mode
    SSD1306_WriteCommand(0x00); // Horizontal
    SSD1306_WriteCommand(0xB0); // Page Start Address
    SSD1306_WriteCommand(0xC8); // COM Output Scan Direction
    SSD1306_WriteCommand(0x00); // Low column start
    SSD1306_WriteCommand(0x10); // High column start
    SSD1306_WriteCommand(0x40); // Start line
    SSD1306_WriteCommand(0x81); // Contrast
    SSD1306_WriteCommand(0xFF);
    SSD1306_WriteCommand(0xA1); // Segment remap
    SSD1306_WriteCommand(0xA6); // Normal display
    SSD1306_WriteCommand(0xA8); // Multiplex
    SSD1306_WriteCommand(0x3F);
    SSD1306_WriteCommand(0xA4); // Display all on resume
    SSD1306_WriteCommand(0xD3); // Display offset
    SSD1306_WriteCommand(0x00);
    SSD1306_WriteCommand(0xD5); // Display clock divide
    SSD1306_WriteCommand(0xF0);
    SSD1306_WriteCommand(0xD9); // Pre-charge
    SSD1306_WriteCommand(0x22);
    SSD1306_WriteCommand(0xDA); // COM pins
    SSD1306_WriteCommand(0x12);
    SSD1306_WriteCommand(0xDB); // Vcomh
    SSD1306_WriteCommand(0x20);
    SSD1306_WriteCommand(0x8D); // Charge pump
    SSD1306_WriteCommand(0x14);
    SSD1306_WriteCommand(0xAF); // Display on

    // Clear buffer
    for(int i = 0; i < sizeof(SSD1306_Buffer); i++)
        SSD1306_Buffer[i] = 0x00;

    SSD1306_UpdateScreen();
}

// Simple Putc function
void SSD1306_Putc(char c, uint8_t x, uint8_t y)
{
    if(c < 32 || c > 127) return;
    uint8_t i, j;
    for(i = 0; i < 5; i++)
    {
        uint8_t line = Font5x7[(c - 32) * 5 + i];
        for(j = 0; j < 8; j++)
        {
            if(line & 0x01)
                SSD1306_Buffer[x + (y * 128) + j * 128 + i] = 1;
            line >>= 1;
        }
    }
    SSD1306_UpdateScreen();
}
