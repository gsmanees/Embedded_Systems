/*
 * stm32f446xx_spi_driver.h
 *
 *  Created on: 14-Mar-2026
 *      Author: anees
 */

#ifndef INC_STM32F446XX_SPI_DRIVER_H_
#define INC_STM32F446XX_SPI_DRIVER_H_


#include "stm32f446xx.h"


/*
 * SPI Configuration structure
 */
typedef struct
{
	uint8_t SPI_DeviceMode;
	uint8_t SPI_BusConfig;
	uint8_t SPI_SclkSpeed;
	uint8_t SPI_DFF;
	uint8_t SPI_CPOL;
	uint8_t SPI_CPHA;
	uint8_t CPI_SSM;

}SPI_Config_t;


/*
 * SPI Handle structure
 */
typedef struct
{
	SPI_RegDef_t *pSPIx;
	SPI_Config_t SPIConfig;


}SPI_Handle_t;



#endif /* INC_STM32F446XX_SPI_DRIVER_H_ */
