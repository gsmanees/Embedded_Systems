# STM32F446RE LED Toggle Using Push Button

## Overview

This project demonstrates basic GPIO input and output control on the STM32F446RE microcontroller using custom bare-metal GPIO drivers.

A user push button connected to **PC13** is used to toggle an LED connected to **PA5**. Each valid button press changes the LED state and prints a debug message through the configured terminal interface.

---

## Hardware Used

* STM32F446RE Nucleo Board
* On-board User Button (PC13)
* On-board LED (PA5)
* STM32CubeIDE
* Custom GPIO Driver Library

---

## Pin Configuration

| Peripheral | GPIO Port | Pin  |
| ---------- | --------- | ---- |
| LED        | GPIOA     | PA5  |
| Button     | GPIOC     | PC13 |

---

## Project Structure

```
Project
│
├── main.c
├── stm32f446xx.h
├── stm32f446xx_gpio_driver.h
└── stm32f446xx_gpio_driver.c
```

---

## Working Principle

1. Configure PA5 as GPIO Output.
2. Configure PC13 as GPIO Input.
3. Continuously monitor the button state.
4. When the button is pressed:

   * Wait until the button is released.
   * Apply a small software delay for debouncing.
   * Toggle the LED state.
   * Print "Button pressed" through the terminal.

---

## Code Flow

```text
Initialize GPIOA (LED)
        │
Initialize GPIOC (Button)
        │
Enable Peripheral Clocks
        │
      Loop
        │
Read PC13
        │
Button Pressed?
   Yes ─────► Wait Release
                 │
              Delay
                 │
            Toggle LED
                 │
          Print Message
```

---

## Build and Flash

1. Open the project in STM32CubeIDE.
2. Build the project.

```bash
Project → Build Project
```

3. Connect the STM32F446RE board via USB.
4. Flash the firmware.

```bash
Run → Debug
```

or

```bash
Run → Run
```

---

## Expected Output

### LED State

| Button Press | LED State |
| ------------ | --------- |
| 1st Press    | ON        |
| 2nd Press    | OFF       |
| 3rd Press    | ON        |
| 4th Press    | OFF       |

### Serial Terminal

```text
Button pressed
Button pressed
Button pressed
```

---

## Note

The current implementation uses a simple software delay for switch debouncing:

```c
void delay(void)
{
    for(uint32_t i = 0; i < 50000; i++);
}
```


---

## Future Improvements

* External Interrupt (EXTI) based button handling
* Hardware debouncing
* UART logging
* Multiple LEDs
* RTOS integration
* Low-power mode support
