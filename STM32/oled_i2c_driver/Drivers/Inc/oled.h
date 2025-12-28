#ifndef OLED_SIMPLE_H
#define OLED_SIMPLE_H

#include "stm32f446xx.h"
#include "stm32f446xx_i2c_driver.h"

/* Fixed OLED address */
#define OLED_ADDR   0x3C

/* Simple APIs */
void OLED_Init(I2C_Handle_t *pI2CHandle);
void OLED_Clear(I2C_Handle_t *pI2CHandle);
void OLED_PrintChar(I2C_Handle_t *pI2CHandle, char c);
void OLED_PrintString(I2C_Handle_t *pI2CHandle, char *str);

#endif
