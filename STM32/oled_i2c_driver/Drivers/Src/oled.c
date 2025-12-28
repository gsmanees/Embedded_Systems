/*
 * oled.c
 *
 *  Created on: 28-Dec-2025
 *      Author: anees
 */


#include "oled.h"

/* Very small font (only numbers & few chars) */
static const uint8_t font5x7[][5] =
{
    {0x3E,0x51,0x49,0x45,0x3E}, // 0
    {0x00,0x42,0x7F,0x40,0x00}, // 1
    {0x42,0x61,0x51,0x49,0x46}, // 2
};

/* Send one command */
static void OLED_Command(I2C_Handle_t *pI2CHandle, uint8_t cmd)
{
    uint8_t data[2];
    data[0] = 0x00;   // Command mode
    data[1] = cmd;

    I2C_MasterSendData(pI2CHandle, data, 2, OLED_ADDR, I2C_DISABLE_SR);
}

/* Send display data */
static void OLED_Data(I2C_Handle_t *pI2CHandle, uint8_t data)
{
    uint8_t buf[2];
    buf[0] = 0x40;   // Data mode
    buf[1] = data;

    I2C_MasterSendData(pI2CHandle, buf, 2, OLED_ADDR, I2C_DISABLE_SR);
}

void OLED_Init(I2C_Handle_t *pI2CHandle)
{
    for (volatile int i = 0; i < 100000; i++);

    OLED_Command(pI2CHandle, 0xAE); // Display OFF
    OLED_Command(pI2CHandle, 0xA8); OLED_Command(pI2CHandle, 0x3F);
    OLED_Command(pI2CHandle, 0xD3); OLED_Command(pI2CHandle, 0x00);
    OLED_Command(pI2CHandle, 0x40);
    OLED_Command(pI2CHandle, 0xA1);
    OLED_Command(pI2CHandle, 0xC8);
    OLED_Command(pI2CHandle, 0xDA); OLED_Command(pI2CHandle, 0x12);
    OLED_Command(pI2CHandle, 0x81); OLED_Command(pI2CHandle, 0x7F);
    OLED_Command(pI2CHandle, 0xA4);
    OLED_Command(pI2CHandle, 0xA6);
    OLED_Command(pI2CHandle, 0xD5); OLED_Command(pI2CHandle, 0x80);
    OLED_Command(pI2CHandle, 0x8D); OLED_Command(pI2CHandle, 0x14);
    OLED_Command(pI2CHandle, 0xAF); // Display ON
}

void OLED_Clear(I2C_Handle_t *pI2CHandle)
{
    for (int page = 0; page < 8; page++)
    {
        OLED_Command(pI2CHandle, 0xB0 + page);
        OLED_Command(pI2CHandle, 0x00);
        OLED_Command(pI2CHandle, 0x10);

        for (int col = 0; col < 128; col++)
        {
            OLED_Data(pI2CHandle, 0x00);
        }
    }
}

void OLED_PrintChar(I2C_Handle_t *pI2CHandle, char c)
{
    if (c < '0' || c > '2') return;

    for (int i = 0; i < 5; i++)
    {
        OLED_Data(pI2CHandle, font5x7[c - '0'][i]);
    }
    OLED_Data(pI2CHandle, 0x00);
}

void OLED_PrintString(I2C_Handle_t *pI2CHandle, char *str)
{
    while (*str)
    {
        OLED_PrintChar(pI2CHandle, *str++);
    }
}
