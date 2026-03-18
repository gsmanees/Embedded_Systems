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


// peripheral clock
void SPI_PeriClockControl(SPI_RegDef_t *pSPIx, uint8_t EnorDi);

// init and de init
void SPI_Init(SPI_Handle_t *pSPIHandle);
void SPI_DeInit(SPI_RegDef_t *pSPIx);

void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t Len);
void SPI_ReceiveData(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t Len);




#endif /* INC_STM32F446XX_SPI_DRIVER_H_ */
