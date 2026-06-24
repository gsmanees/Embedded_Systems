# STM32F446RE - LED Toggle Using Push Button (Register-Level Driver)

## Overview

This project demonstrates how to interface a push button and an LED using a custom GPIO driver on the STM32F446RE microcontroller.

When the user presses the push button connected to **PC13**, the LED connected to **PA5** toggles its state (ON/OFF).

The project is developed using:

* STM32F446RE Nucleo Board
* Bare-Metal Programming
* Custom GPIO Driver
* STM32CubeIDE

---

## Hardware Connections

| Component   | STM32 Pin |
| ----------- | --------- |
| LED         | PA5       |
| Push Button | PC13      |

### Board Mapping

* PA5 → On-board User LED (LD2)
* PC13 → On-board User Button (B1)

---

## Project Structure

```text
Project
│
├── main.c
├── stm32f446xx.h
├── stm32f446xx_gpio_driver.h
├── stm32f446xx_gpio_driver.c
└── README.md
```

---

## Working Principle

1. Configure PA5 as GPIO Output.
2. Configure PC13 as GPIO Input.
3. Continuously monitor the button state.
4. When the button is pressed:

   * Wait until the button is released.
   * Toggle the LED state.

This provides a simple software debouncing mechanism.

---

## Source Code Logic

### LED Configuration

```c
led_h.pGPIOx = GPIOA;
led_h.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
led_h.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
```

### Button Configuration

```c
button_h.pGPIOx = GPIOC;
button_h.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
button_h.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
```

### Button Press Detection

```c
if(GPIO_ReadFromInputPin(GPIOC, GPIO_PIN_NO_13)==0)
{
    while(GPIO_ReadFromInputPin(GPIOC, GPIO_PIN_NO_13)==0)
        delay();

    GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_5);
}
```

---

## Software Debouncing

Mechanical push buttons generate multiple transitions when pressed or released.

To avoid false triggering, a simple delay is used:

```c
void delay(void)
{
    for(uint32_t i=0;i<50000;i++);
}
```

This method is suitable for learning and simple applications.

---

## Build and Flash

### Step 1

Open the project in STM32CubeIDE.

### Step 2

Build the project:

```text
Project → Build Project
```

### Step 3

Connect the STM32F446RE board via USB.

### Step 4

Flash the firmware:

```text
Run → Debug
```

or

```text
Run → Run
```

---

## Expected Output

| Button State | LED State |
| ------------ | --------- |
| Press 1      | ON        |
| Press 2      | OFF       |
| Press 3      | ON        |
| Press 4      | OFF       |

The LED toggles every time the button is pressed and released.

---

## Learning Outcomes

After completing this project, you will understand:

* GPIO Clock Configuration
* GPIO Input Mode
* GPIO Output Mode
* Reading Digital Inputs
* Writing Digital Outputs
* LED Control
* Button Interfacing
* Software Debouncing
* STM32 Register-Level Driver Development

