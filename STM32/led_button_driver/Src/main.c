

#include <stdint.h>
#include<stdio.h>
#include "stm32f446xx_gpio_driver.h"

#define HIGH 1
#define LOW 0
#define BTN_PRESSED LOW

void delay(void)
{
	for (uint32_t i=0; i<500000; i++);
}

int main(void)
{

	GPIO_Handle_t GpioLed;

	//this is led gpio configuration
	GpioLed.pGPIOx = GPIOA;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	GPIO_PeriClockControl(GPIOA,ENABLE);
	GPIO_Init(&GpioLed);

	GPIO_Handle_t button;
	button.pGPIOx = GPIOC;
	button.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	button.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	GPIO_PeriClockControl(GPIOC, ENABLE);
	GPIO_Init(&button);

	while(1)
	{
		if (GPIO_ReadFromInputPin(GPIOC, GPIO_PIN_NO_13) == LOW)
		{

			GPIO_ToggleOutputPin(GPIOA,GPIO_PIN_NO_5);
			printf("\nButton pressed");
			delay();
		}

	}
	return 0;
}


