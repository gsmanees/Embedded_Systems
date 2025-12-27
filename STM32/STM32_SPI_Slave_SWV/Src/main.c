#include "stm32f446xx.h"
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

int main(void)
{
    SPI1_GPIO_Init();
    SPI1_Init();

    printf("STM32 SPI1 SLAVE READY\r\n");

    while (1)
    {
        /* Wait for NSS LOW */
        if (!(GPIOA->IDR & (1 << 4)))
        {
            /* Clear OVR safely */
            volatile uint8_t temp;
            temp = SPI1->DR;
            temp = SPI1->SR;

            while (!(GPIOA->IDR & (1 << 4)))
            {
                if (SPI1->SR & (1 << 0))   // RXNE
                {
                    uint8_t rx = SPI1->DR;
                    printf("%c", rx);
                }
            }
        }
    }
}
