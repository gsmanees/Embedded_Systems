


/*
 * stm32f446xx_gpio_driver.h
 *
 * GPIO driver header file for STM32F446xx MCU
 */

#ifndef INC_STM32F446XX_GPIO_DRIVER_H_
#define INC_STM32F446XX_GPIO_DRIVER_H_

#include "stm32f446xx.h"


/*
 * This is a Configuration structure for a GPIO pin
 */
typedef struct
{
    uint8_t GPIO_PinNumber;             /*!< Possible values from @GPIO_PIN_NUMBERS */
    uint8_t GPIO_PinMode;               /*!< Possible values from @GPIO_PIN_MODES */
    uint8_t GPIO_PinSpeed;              /*!< Possible values from @GPIO_PIN_SPEED */
    uint8_t GPIO_PinPuPdControl;        /*!< Possible values from @GPIO_PIN_PUPD */
    uint8_t GPIO_PinOPType;             /*!< Possible values from @GPIO_PIN_OP_TYPE */
    uint8_t GPIO_PinAltFunMode;         /*!< Alternate function mode (AF0-AF15) */
} GPIO_PinConfig_t;


/*
 * This is a Handle structure for a GPIO pin
 */
typedef struct
{
    GPIO_RegDef_t *pGPIOx;              /*!< This holds the base address of the GPIO port to which the pin belongs */
    GPIO_PinConfig_t GPIO_PinConfig;    /*!< This holds GPIO pin configuration settings */
} GPIO_Handle_t;


/*
 * @GPIO_PIN_NUMBERS
 * GPIO pin numbers
 */
#define GPIO_PIN_NO_0                   0
#define GPIO_PIN_NO_1                   1
#define GPIO_PIN_NO_2                   2
#define GPIO_PIN_NO_3                   3
#define GPIO_PIN_NO_4                   4
#define GPIO_PIN_NO_5                   5
#define GPIO_PIN_NO_6                   6
#define GPIO_PIN_NO_7                   7
#define GPIO_PIN_NO_8                   8
#define GPIO_PIN_NO_9                   9
#define GPIO_PIN_NO_10                  10
#define GPIO_PIN_NO_11                  11
#define GPIO_PIN_NO_12                  12
#define GPIO_PIN_NO_13                  13
#define GPIO_PIN_NO_14                  14
#define GPIO_PIN_NO_15                  15


/*
 * @GPIO_PIN_MODES
 * GPIO pin possible modes
 */
#define GPIO_MODE_IN                    0   /*!< Input mode */
#define GPIO_MODE_OUT                   1   /*!< General purpose output mode */
#define GPIO_MODE_ALTFN                 2   /*!< Alternate function mode */
#define GPIO_MODE_ANALOG                3   /*!< Analog mode */
#define GPIO_MODE_IT_FT                 4   /*!< Interrupt falling edge trigger */
#define GPIO_MODE_IT_RT                 5   /*!< Interrupt rising edge trigger */
#define GPIO_MODE_IT_RFT                6   /*!< Interrupt rising and falling edge trigger */


/*
 * @GPIO_PIN_OP_TYPE
 * GPIO pin possible output types
 */
#define GPIO_OP_TYPE_PP                 0   /*!< Push-pull output */
#define GPIO_OP_TYPE_OD                 1   /*!< Open-drain output */


/*
 * @GPIO_PIN_SPEED
 * GPIO pin possible output speeds
 */
#define GPIO_SPEED_LOW                  0   /*!< Low speed */
#define GPIO_SPEED_MEDIUM               1   /*!< Medium speed */
#define GPIO_SPEED_FAST                 2   /*!< Fast speed */
#define GPIO_SPEED_HIGH                 3   /*!< High speed */


/*
 * @GPIO_PIN_PUPD
 * GPIO pin pull-up and pull-down configuration macros
 */
#define GPIO_NO_PUPD                    0   /*!< No pull-up, no pull-down */
#define GPIO_PIN_PU                     1   /*!< Pull-up */
#define GPIO_PIN_PD                     2   /*!< Pull-down */


/******************************************************************************************
 *                          APIs supported by this driver
 *          For more information about the APIs check the function definitions
 ******************************************************************************************/

/*
 * Peripheral Clock setup
 */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);

/*
 * Init and De-init
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

/*
 * Data read and write
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

/*
 * IRQ Configuration and ISR handling
 */
void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);
void GPIO_IRQHandling(uint8_t PinNumber);


#endif /* INC_STM32F446XX_GPIO_DRIVER_H_ */











//// GPIO base addresses {AHB1 bus}
//
//#define GPIOA_BASEADDR 0X40020000U
//#define GPIOB_BASEADDR 0x40020400U
//#define GPIOC_BASEADDR 0x40020800U
//#define GPIOD_BASEADDR 0x40020C00U
//#define GPIOE_BASEADDR 0x40021000U
//#define GPIOF_BASEADDR 0x40021400U
//#define GPIOG_BASEADDR 0x40021800U
//#define GPIOH_BASEADDR 0x40021C00U
//
//// GPIO Register structure
//
//typedef struct
//{
//    volatile uint32_t MODER;    // GPIO port mode register              (0x00)
//    volatile uint32_t OTYPER;   // GPIO port output type register       (0x04)
//    volatile uint32_t OSPEEDR;  // GPIO port output speed register      (0x08)
//    volatile uint32_t PUPDR;    // GPIO port pull-up/pull-down register (0x0C)
//    volatile uint32_t IDR;      // GPIO port input data register        (0x10)
//    volatile uint32_t ODR;      // GPIO port output data register       (0x14)
//    volatile uint32_t BSRR;     // GPIO port bit set/reset register     (0x18)
//    volatile uint32_t LCKR;     // GPIO port configuration lock register(0x1C)
//    volatile uint32_t AFRL;     // GPIO alternate function low register (0x20)
//    volatile uint32_t AFRH;     // GPIO alternate function high register(0x24)
//} GPIO_RegDef_t;
//
//
//// GPIO pointers
//
//#define GPIOA   ((GPIO_RegDef_t*)GPIOA_BASEADDR)
//#define GPIOB   ((GPIO_RegDef_t*)GPIOB_BASEADDR)
//#define GPIOC   ((GPIO_RegDef_t*)GPIOC_BASEADDR)
//#define GPIOD   ((GPIO_RegDef_t*)GPIOD_BASEADDR)
//#define GPIOE   ((GPIO_RegDef_t*)GPIOE_BASEADDR)
//#define GPIOF   ((GPIO_RegDef_t*)GPIOF_BASEADDR)
//#define GPIOG   ((GPIO_RegDef_t*)GPIOG_BASEADDR)
//#define GPIOH   ((GPIO_RegDef_t*)GPIOH_BASEADDR)
//
////-----------------------------------------------------------------------
//
//// 						RCC Register base address and register structure
//
//// RCC BASE ADDRESS
//#define RCC_BASEADDR 0X40023800U
//
//// RCC register structure
//
//typedef struct
//{
//    volatile uint32_t CR;            // RCC clock control register                    (0x00)
//    volatile uint32_t PLLCFGR;       // RCC PLL configuration register                (0x04)
//    volatile uint32_t CFGR;          // RCC clock configuration register              (0x08)
//    volatile uint32_t CIR;           // RCC clock interrupt register                  (0x0C)
//    volatile uint32_t AHB1RSTR;      // RCC AHB1 peripheral reset register            (0x10)
//    volatile uint32_t AHB2RSTR;      // RCC AHB2 peripheral reset register            (0x14)
//    volatile uint32_t AHB3RSTR;      // RCC AHB3 peripheral reset register            (0x18)
//    volatile uint32_t RESERVED0;     // Reserved                                      (0x1C)
//    volatile uint32_t APB1RSTR;      // RCC APB1 peripheral reset register            (0x20)
//    volatile uint32_t APB2RSTR;      // RCC APB2 peripheral reset register            (0x24)
//    volatile uint32_t RESERVED1[2];  // Reserved                                      (0x28-0x2C)
//    volatile uint32_t AHB1ENR;       // RCC AHB1 peripheral clock enable register     (0x30)
//    volatile uint32_t AHB2ENR;       // RCC AHB2 peripheral clock enable register     (0x34)
//    volatile uint32_t AHB3ENR;       // RCC AHB3 peripheral clock enable register     (0x38)
//    volatile uint32_t RESERVED2;     // Reserved                                      (0x3C)
//    volatile uint32_t APB1ENR;       // RCC APB1 peripheral clock enable register     (0x40)
//    volatile uint32_t APB2ENR;       // RCC APB2 peripheral clock enable register     (0x44)
//    volatile uint32_t RESERVED3[2];  // Reserved                                      (0x48-0x4C)
//    volatile uint32_t AHB1LPENR;     // RCC AHB1 peripheral clock enable in low power (0x50)
//    volatile uint32_t AHB2LPENR;     // RCC AHB2 peripheral clock enable in low power (0x54)
//    volatile uint32_t AHB3LPENR;     // RCC AHB3 peripheral clock enable in low power (0x58)
//    volatile uint32_t RESERVED4;     // Reserved                                      (0x5C)
//    volatile uint32_t APB1LPENR;     // RCC APB1 peripheral clock enable in low power (0x60)
//    volatile uint32_t APB2LPENR;     // RCC APB2 peripheral clock enable in low power (0x64)
//    volatile uint32_t RESERVED5[2];  // Reserved                                      (0x68-0x6C)
//    volatile uint32_t BDCR;          // RCC Backup domain control register            (0x70)
//    volatile uint32_t CSR;           // RCC clock control & status register           (0x74)
//    volatile uint32_t RESERVED6[2];  // Reserved                                      (0x78-0x7C)
//    volatile uint32_t SSCGR;         // RCC spread spectrum clock generation register (0x80)
//    volatile uint32_t PLLI2SCFGR;    // RCC PLLI2S configuration register             (0x84)
//    volatile uint32_t PLLSAICFGR;    // RCC PLLSAI configuration register             (0x88)
//    volatile uint32_t DCKCFGR;       // RCC Dedicated Clocks configuration register   (0x8C)
//    volatile uint32_t CKGATENR;      // RCC clocks gated enable register              (0x90)
//    volatile uint32_t DCKCFGR2;      // RCC Dedicated Clocks configuration register 2 (0x94)
//} RCC_RegDef_t;
//
//// RCC pointer
//#define RCC ((RCC_RegDef_t*)RCC_BASEADDR)
//
//// clock enable for GPIO
//#define GPIOA_CLK_EN() (RCC->AHB1ENR)|=(1<<0)
//#define GPIOB_CLK_EN() (RCC->AHB1ENR)|=(1<<1)
//#define GPIOC_CLK_EN() (RCC->AHB1ENR)|=(1<<2)
//#define GPIOD_CLK_EN() (RCC->AHB1ENR)|=(1<<3)
//#define GPIOE_CLK_EN() (RCC->AHB1ENR)|=(1<<4)
//#define GPIOF_CLK_EN() (RCC->AHB1ENR)|=(1<<5)
//#define GPIOG_CLK_EN() (RCC->AHB1ENR)|=(1<<6)
//#define GPIOH_CLK_EN() (RCC->AHB1ENR)|=(1<<7)
