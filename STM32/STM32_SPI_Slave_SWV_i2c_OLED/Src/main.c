#include "stm32f446xx.h"          // STM32F4 device definitions
#include "stm32f446xx_gpio_driver.h" // GPIO driver
#include "stm32f446xx_spi_driver.h"  // SPI driver
#include "stm32f446xx_i2c_driver.h"  // I2C driver
#include "oled.h"                   // OLED functions
#include <stdio.h>
#include <stdint.h>

void SPI1_GPIO_Init(void)
{
    /* Enable GPIOA clock */
    RCC->AHB1ENR |= (1 << 0);

    /* PA4 NSS, PA5 SCK, PA6 MISO, PA7 MOSI */
    GPIOA->MODER &= ~(
        (3 << (4*2)) |
        (3 << (5*2)) |
        (3 << (6*2)) |
        (3 << (7*2))
    );

    GPIOA->MODER |= (
        (2 << (4*2)) |
        (2 << (5*2)) |
        (2 << (6*2)) |
        (2 << (7*2))
    );

    /* AF5 for SPI1 */
    GPIOA->AFR[0] &= ~(
        (0xF << (4*4)) |
        (0xF << (5*4)) |
        (0xF << (6*4)) |
        (0xF << (7*4))
    );

    GPIOA->AFR[0] |= (
        (5 << (4*4)) |
        (5 << (5*4)) |
        (5 << (6*4)) |
        (5 << (7*4))
    );

    GPIOA->OSPEEDR |= (
        (3 << (4*2)) |
        (3 << (5*2)) |
        (3 << (6*2)) |
        (3 << (7*2))
    );

    GPIOA->PUPDR &= ~(
        (3 << (4*2)) |
        (3 << (5*2)) |
        (3 << (6*2)) |
        (3 << (7*2))
    );
}

void SPI1_Init(void)
{
    /* Enable SPI1 clock */
    RCC->APB2ENR |= (1 << 12);

    SPI1->CR1 = 0;
    SPI1->CR2 = 0;

    SPI1->CR1 &= ~(1 << 2);   // Slave
    SPI1->CR1 &= ~(1 << 9);   // HW NSS
    SPI1->CR1 &= ~(1 << 11);  // 8-bit
    SPI1->CR1 &= ~(1 << 1);   // CPOL = 0
    SPI1->CR1 &= ~(1 << 0);   // CPHA = 0

    SPI1->CR1 |= (1 << 6);    // SPI Enable
}

int main(void) {

	I2C_Handle_t hi2c1;

	hi2c1.pI2Cx = I2C1;
	hi2c1.I2C_Config.ClockSpeed = 100000;
	hi2c1.I2C_Config.ACKControl = 1;
	I2C_Init(&hi2c1);

    SPI1_GPIO_Init();
    SPI1_Init();
    OLED_Init();

    printf("STM32 SPI1 SLAVE READY\r\n");

    OLED_Putc('A', 0, 0); // print 'A' at top-left

    while(1) {
        if (!(GPIOA->IDR & (1<<4))) { // NSS low
            if(SPI1->SR & (1<<0)) {
                uint8_t rx = SPI1->DR;
                printf("%c", rx);
                OLED_Putc(rx, 0, 1); // print received char at row 1
            }
        }
    }
}
