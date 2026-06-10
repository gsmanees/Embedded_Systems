/*
 * DistanceTriggered_PWM.c
 *
 * Created: 10-06-2026 6.16.43 AM
 * Author : anees
 *
 * HC-SR04 distance based LED brightness control
 * PWM output : OCR0A (PD6)
 
 Distance triggered PWM

 #pwm
 #hcsr04

 Connections:

 HCSR04
 VCC --> 5v
 GND
 TRIG --> PB0
 EXHO --> PB1

 PWM pin - PD6, OCR0A used, LED connected to this pin

 Modular code and firmware uploaded to GitHub, link in bio
 */

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "hcsr04.h"

void PWM0_Init(void)
{
    DDRD |= (1 << PD6);          // OC0A output

    // Fast PWM, non-inverting mode
    TCCR0A = (1 << COM0A1) |
             (1 << WGM00)  |
             (1 << WGM01);

    // Prescaler = 8
    TCCR0B = (1 << CS01);

    OCR0A = 0;
}

int main(void)
{
    float distance;
    uint8_t duty;

    hcsr04_IO_Init();
    PWM0_Init();

    while (1)
    {
        hcsr04_EN_trigger();

        distance = 10*measure_distance();

      
        if(distance >= 15)
        {
            duty = 0;
        }
        else
        {
            duty = (uint8_t)(255.0 - ((distance - 5.0) * 255.0 / 45.0));
        }

        OCR0A = duty;

        _delay_ms(100);
    }
}