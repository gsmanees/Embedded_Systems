/*
 * spi.h
 *
 *  Created on: 25-Jun-2026
 *      Author: anees
 */

#include "stm32f446xx.h"
#include "stm32f446xx_gpio_driver.h"
#include "stm32f446xx_spi_driver.h"
#ifndef INC_SPI_H_
#define INC_SPI_H_

void BMP280_SPI_GPIOInits(void);
void BMP280_SPI_Init(void);
uint8_t SPI_Transfer(uint8_t data);
void BMP280_WriteRegister(uint8_t reg, uint8_t value);
void BMP280_ReadRegisters(uint8_t reg, uint8_t *buffer, uint8_t len);

#endif /* INC_SPI_H_ */
