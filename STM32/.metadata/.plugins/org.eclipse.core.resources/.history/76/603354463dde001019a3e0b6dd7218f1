#ifndef STM32F446_GPIO_DRIVER_H
#define STM32F446_GPIO_DRIVER_H

#include <stdint.h>

// GPIO register definitions
typedef struct
{
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDR;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t LCKR;
    volatile uint32_t AFRL;
    volatile uint32_t AFRH;
} GPIO_RegDef_t;

// RCC register definitions
typedef struct
{
    volatile uint32_t CR;
    volatile uint32_t PLLCFGR;
    volatile uint32_t CFGR;
    volatile uint32_t CIR;
    volatile uint32_t AHB1RSTR;
    volatile uint32_t AHB2RSTR;
    volatile uint32_t AHB3RSTR;
    uint32_t RESERVED0;
    volatile uint32_t APB1RSTR;
    volatile uint32_t APB2RSTR;
    uint32_t RESERVED1[2];
    volatile uint32_t AHB1ENR;

    // included RCC only which required for led toggle
} RCC_RegDef_t;


//base addresses
#define GPIOA_BASEADDR   0x40020000U
#define RCC_BASEADDR     0x40023800U


// Pointers
#define GPIOA   ((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define RCC     ((RCC_RegDef_t*)RCC_BASEADDR)


//macros
#define ENABLE     1
#define DISABLE    0

#define GPIO_PIN_5 5

// API prototypes
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnOrDi);
void GPIO_Init_Output(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
void GPIO_TogglePin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

#endif
