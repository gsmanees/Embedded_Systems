/*
 * stm32f446xx.h
 *
 *  Created on: 16-Jan-2026
 *      Author: anees
 */

#ifndef INC_STM32F446XX_H_
#define INC_STM32F446XX_H_



/*
 * steps to create board specific MCU header file
 * 		write macros for the following
 * 1. System memory/ flash memory base address
 * 2. SRAM 1 base address
 * 3. SRAM 2 base address
 * 4. SRAM base address 			- Same as that of SRAM1 base address
 * 5. Bus Peripheral base address 	- All buses starts here
 * 6. APB1 peripheral base address
 * 7. APB2 peripheral base address
 * 8. AHB1 peripheral base address
 * 9. AHB2 peripheral base address
 * 10.AHB3 peripheral base address
 *
 *
 *
 *
 */

// System memory/ flash memory base address
	#define FLASH_BASEADDR	0x1FFF0000U
	#define SRAM1_BASEADDR	0x20000000U
	#define SRAM2_BASEADDR	0x2001C000U
	#define SRAM_BASEADDR	SRAM1_BASEADDR

// All peripheral buses main base addresses

	#define PERIPH_BASEADDR		0x40000000U

	#define APB1_BASEADDR	PERIPH_BASEADDR
	#define APB2_BASEADDR	0x40010000U
	#define AHB1_BASEADDR	0x40020000U
	#define AHB2_BASEADDR	0x50000000U
	#define AHB3_BASEADDR	0x60000000U

// Next, we define peripheral base addresses of all GPIO
// which are on bus AHB1


//-----------------------------------AHB1 bus peripheral base address tart ---------------------------
	#define GPIO_BASEADDR	AHB1_BASEADDR

	#define GPIOA_BASEADDR	(GPIO_BASEADDR + 0X0000U)	// adding offset value
	#define GPIOB_BASEADDR	(GPIO_BASEADDR + 0X0400U)
	#define GPIOC_BASEADDR	(GPIO_BASEADDR + 0X0800U)
	#define GPIOD_BASEADDR	(GPIO_BASEADDR + 0X0C00U)
	#define GPIOE_BASEADDR	(GPIO_BASEADDR + 0X1000U)
	#define GPIOF_BASEADDR	(GPIO_BASEADDR + 0X1400U)
	#define GPIOG_BASEADDR	(GPIO_BASEADDR + 0X1800U)
	#define GPIOH_BASEADDR	(GPIO_BASEADDR + 0X1C00U)


	#define CRC_BASEADDR		(AHB1_BASEADDR + 0X3000)
	#define RCC_BASEADDR		(AHB1_BASEADDR + 0X3800)
	#define FLASH_IF_BASEADDR	(AHB1_BASEADDR + 0X3C00)
	#define BKP_SRAM_BASEADDR	(AHB1_BASEADDR + OX4000)
	#define DMA1_BASEADDR		(AHB1_BASEADDR + 0X6000)
	#define DMA2_BASEADDR		(AHB1_BASEADDR + 0X6400)
	#define USB_OTG_HS_BASEADDR	(0x40040000U)




// -------------------------AHB2 peripheral base addresses start ----------------------------------

#define USB_OTG_FS_BASEADDR		(AHB2_BASEADDR + 0X000)
#define DCMI_BASEADDR			(AHB2_BASEADDR + 0X50000)



// -----------------------APB1 bus peripheral base address start ---------------------------------------------

#define TIM2_BASEADDR		(APB1_BASEADDR + 0X0000)
#define TIM3_BASEADDR		(APB1_BASEADDR + 0X0400)
#define TIM4_BASEADDR		(APB1_BASEADDR + 0X0800)
#define TIM5_BASEADDR		(APB1_BASEADDR + 0X0C00)
#define TIM6_BASEADDR		(APB1_BASEADDR + 0X1000)
#define TIM7_BASEADDR		(APB1_BASEADDR + 0X1400)
#define TIM12_BASEADDR		(APB1_BASEADDR + 0X1800)
#define TIM13_BASEADDR		(APB1_BASEADDR + 0X1C00)
#define TIM14_BASEADDR		(APB1_BASEADDR + 0X2000)

#define RTC_BKP_BASEADDR	(APB1_BASEADDR + 0X2800)

#define WWDG_BASEADDR		(APB1_BASEADDR + 0X2C00)
#define IWDG_BASEADDR		(APB1_BASEADDR + 0X3000)

#define SPI2_BASEADDR		(APB1_BASEADDR + 0X3800)
#define SPI3_BASEADDR		(APB1_BASEADDR + 0X3C00)

#define SPDIF_RX_BASEADDR	(APB1_BASEADDR + 0X4000)

#define USART2_BASEADDR		(APB1_BASEADDR + 0X4400)
#define USART3_BASEADDR		(APB1_BASEADDR + 0X4800)
#define UART4_BASEADDR		(APB1_BASEADDR + 0X4C00)
#define UART5_BASEADDR		(APB1_BASEADDR + 0X5000)

#define I2C1_BASEADDR		(APB1_BASEADDR + 0X5400)
#define I2C2_BASEADDR		(APB1_BASEADDR + 0X5800)
#define I2C3_BASEADDR		(APB1_BASEADDR + 0X5C00)

#define CAN1_BASEADDR		(APB1_BASEADDR + 0X6400)
#define CAN2_BASEADDR		(APB1_BASEADDR + 0X6800)

#define HDMI_CEC_BASEADDR	(APB1_BASEADDR + 0X6C00)
#define PWR_BASEADDR		(APB1_BASEADDR + 0X7000)

#define DAC_BASEADDR		(APB1_BASEADDR + 0X7400)


//--------------------APB2 peripheral base addresses start-----------------------------------
#define TIM1_BASEADDR		(APB2_BASEADDR + 0X0000)
#define TIM8_BASEADDR		(APB2_BASEADDR + 0X0400)

#define USART1_BASEADDR		(APB2_BASEADDR + 0X1000)
#define USART6_BASEADDR		(APB2_BASEADDR + 0X1400)

#define ADC1_BASEADDR		(APB2_BASEADDR + 0X2000)
#define ADC2_BASEADDR		(APB2_BASEADDR + 0X2100)
#define ADC3_BASEADDR		(APB2_BASEADDR + 0X2200)
#define ADC_COMMON_BASEADDR	(APB2_BASEADDR + 0X2300)

#define SDMMC_BASEADDR		(APB2_BASEADDR + 0X2C00)

#define SPI1_BASEADDR		(APB2_BASEADDR + 0X3000)
#define SPI4_BASEADDR		(APB2_BASEADDR + 0X3400)

#define SYSCFG_BASEADDR		(APB2_BASEADDR + 0X3800)
#define EXTI_BASEADDR		(APB2_BASEADDR + 0X3C00)

#define TIM9_BASEADDR		(APB2_BASEADDR + 0X4000)
#define TIM10_BASEADDR		(APB2_BASEADDR + 0X4400)
#define TIM11_BASEADDR		(APB2_BASEADDR + 0X4800)

#define SAI1_BASEADDR		(APB2_BASEADDR + 0X5800)
#define SAI2_BASEADDR		(APB2_BASEADDR + 0X5C00)



// ======================= Peripheral Register definition Structures START =======================

	#define vo volatile

// ---------------------- GPIO register definition structure ----------------------

	typedef struct
	{
		vo uint32_t MODER;
		vo uint32_t OTYPER;
		vo uint32_t OSPEEDER;
		vo uint32_t PUPDR;
		vo uint32_t IDR;
		vo uint32_t ODR;
		vo uint32_t BSRR;
		vo uint32_t LCKR;
		vo uint32_t AFR[2]; // AFRL and ARFH

	}GPIO_RegDef_t;


//--------------------------- RCC Register definition Structure --------------------------------

typedef struct
{
	vo uint32_t CR;
	vo uint32_t PLLCFGR;
	vo uint32_t CFGR;
	vo uint32_t CIR;
	vo uint32_t AHB1RSTR;
	vo uint32_t AHB2RSTR;
	vo uint32_t AHB3RSTR;
	vo uint32_t Reserved1;
	vo uint32_t APB1RSTR;
	vo uint32_t APB2RSTR;
	vo uint32_t Reserved2;
	vo uint32_t Reserved3;
	vo uint32_t AHB1ENR;
	vo uint32_t AHB2ENR;
	vo uint32_t AHB3ENR;
	vo uint32_t Reserved4;
	vo uint32_t APB1ENR;
	vo uint32_t APB2ENR;
	vo uint32_t Reserved5;
	vo uint32_t Reserved6;
	vo uint32_t AHB1LPENR;
	vo uint32_t AHB2LPENR;
	vo uint32_t AHB3LPENR;
	vo uint32_t Reserved7;
	vo uint32_t APB1LPENR;
	vo uint32_t APB2LPENR;
	vo uint32_t Reserved8;
	vo uint32_t Reserved9;
	vo uint32_t BDCR;
	vo uint32_t CSR;
	vo uint32_t Reserved10;
	vo uint32_t Reserved11;
	vo uint32_t SSCGR;
	vo uint32_t PLLI2SCFGR;
	vo uint32_t PLLSAICFGR;
	vo uint32_t DCKCFGR;
	vo uint32_t CKGATENR;
	vo uint32_t DCKCFGR2;

}RCC_Regdef_t;


// -------------------------- I2C Register Structure definition -----------------------------------------


typedef struct
{
	vo uint32_t CR1;
	vo uint32_t CR2;
	vo uint32_t OAR1;
	vo uint32_t OAR2;
	vo uint32_t DR;
	vo uint32_t SR1;
	vo uint32_t SR2;
	vo uint32_t CCR;
	vo uint32_t TRISE;
	vo uint32_t FLTR;

}I2C_regdef_t;



// ----------------------------------- SPI register definition Structure ------------------------------

typedef struct
{
	vo uint32_t CR1;
	vo uint32_t CR2;
	vo uint32_t SR;
	vo uint32_t DR;
	vo uint32_t CRCPR;
	vo uint32_t RXCRCR;
	vo uint32_t TXCRCR;
	vo uint32_t I2SCFGR;
	vo uint32_t I2SPR;

}SPI_RegDef_t;


// -------------------------------- USART Register structure --------------------------------------

typedef struct
{
	vo uint32_t SR;
	vo uint32_t DR;
	vo uint32_t BRR;
	vo uint32_t CR1;
	vo uint32_t CR2;
	vo uint32_t CR3;
	vo uint32_t GTPR;

}USART_RegDef_t;


// ---------------------------- CAN register structure ------------------------------
typedef struct
{
	vo uint32_t MCR;
	vo uint32_t MSR;
	vo uint32_t TSR;
	vo uint32_t RF0R;
	vo uint32_t RF1R;
	vo uint32_t IER;
	vo uint32_t ESR;
	vo uint32_t BTR;
	vo uint32_t TI0R;
	vo uint32_t TDT0R;
	vo uint32_t TDL0R;
	vo uint32_t TDH0R;
	vo uint32_t TI1R;
	vo uint32_t TDT1R;
	vo uint32_t TDL1R;
	vo uint32_t TDH1R;
	vo uint32_t TI2R;
	vo uint32_t TDT2R;
	vo uint32_t TDL2R;
	vo uint32_t TDH2R;
	vo uint32_t RI0R;
	vo uint32_t RDT0R;
	vo uint32_t RDL0R;
	vo uint32_t RDH0R;
	vo uint32_t RI1R;
	vo uint32_t RDT1R;
	vo uint32_t RDL1R;
	vo uint32_t RDH1R;
	vo uint32_t RESERVED1;
	vo uint32_t RESERVED2;
	vo uint32_t FS1R;
	vo uint32_t RESERVED3;
	vo uint32_t FFA1R;
	vo uint32_t FA1R;
	vo uint32_t F0R1;
	vo uint32_t F0R2;
	vo uint32_t F1R1;
	vo uint32_t F1R2;
	vo uint32_t F27R1;
	vo uint32_t F27R2;
}CAN_RegDef_t;


// ============================== Peripheral pointers ====================================================

// GPIO pointers
#define GPIOA   ((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB   ((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC   ((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD   ((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE   ((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF   ((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG   ((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH   ((GPIO_RegDef_t*)GPIOH_BASEADDR)

// RCC pointer
#define RCC ((RCC_RegDef_t*)RCC_BASEADDR)

// I2C Pointers
#define I2C1 ((I2C_RegDef_t*)I2C1_BASEADDR)
#define I2C2 ((I2C_RegDef_t*)I2C2_BASEADDR)
#define I2C3 ((I2C_RegDef_t*)I2C3_BASEADDR)

// SPI pointers
#define SPI1 ((SPI_RegDef_t*)SPI1_BASEADDR)
#define SPI2 ((SPI_RegDef_t*)SPI2_BASEADDR)
#define SPI3 ((SPI_RegDef_t*)SPI3_BASEADDR)
#define SPI4 ((SPI_RegDef_t*)SPI4_BASEADDR)

// USART pointers
#define USART1 ((USART_RegDef_t*)USART1_BASEADDR)
#define USART2 ((USART_RegDef_t*)USART1_BASEADDR)
#define USART3 ((USART_RegDef_t*)USART1_BASEADDR)
#define USART4 ((USART_RegDef_t*)USART1_BASEADDR)
#define USART5 ((USART_RegDef_t*)USART1_BASEADDR)
#define USART6 ((USART_RegDef_t*)USART1_BASEADDR)

// CAN Pointers
#define CAN1 ((CAN_RegDef_t*)CAN1_BASEADDR)
#define CAN2 ((CAN_RegDef_t*)CAN2_BASEADDR)


// =========================== Clock Enable MAcros =============================================

// GPIO clock enable macros
#define GPIOA_CLK_EN() (RCC->AHB1ENR)|=(1<<0)
#define GPIOB_CLK_EN() (RCC->AHB1ENR)|=(1<<1)
#define GPIOC_CLK_EN() (RCC->AHB1ENR)|=(1<<2)
#define GPIOD_CLK_EN() (RCC->AHB1ENR)|=(1<<3)
#define GPIOE_CLK_EN() (RCC->AHB1ENR)|=(1<<4)
#define GPIOF_CLK_EN() (RCC->AHB1ENR)|=(1<<5)
#define GPIOG_CLK_EN() (RCC->AHB1ENR)|=(1<<6)
#define GPIOH_CLK_EN() (RCC->AHB1ENR)|=(1<<7)


// I2C clock enable macros
#define I2C1_EN() (RCC->APB1ENR|=(1<<21))
#define I2C2_EN() (RCC->APB1ENR|=(1<<22))
#define I2C3_EN() (RCC->APB1ENR|=(1<<23))


// SPI Clock Enable Macros
#define SPI1_EN() (RCC->APB2ENR|=(1<<12))
#define SPI2_EN() (RCC->APB1ENR|=(1<<14))
#define SPI3_EN() (RCC->APB1ENR|=(1<<15))
#define SPI4_EN() (RCC->APB2ENR|=(1<<13))


// USART Clock Enable Macros
#define USART1_EN() (RCC->APB2ENR|=(1<<4))
#define USART2_EN() (RCC->APB1ENR|=(1<<17))
#define USART3_EN() (RCC->APB1ENR|=(1<<18))
#define USART4_EN() (RCC->APB1ENR|=(1<<19))
#define USART5_EN() (RCC->APB1ENR|=(1<<20))
#define USART6_EN() (RCC->APB2ENR|=(1<<4))

// CAN Clock Enable Macros
#define CAN1_EN() (RCC->APB1ENR|=(1<<25))
#define CAN2_EN() (RCC->APB1ENR|=(1<<26))










#endif /* INC_STM32F446XX_H_ */
