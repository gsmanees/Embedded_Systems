/*
 * servo.c
 *
 * Created: 09-01-2026 6.14.59 PM
 *  Author: anees
 */ 

#include "servo.h"
#include <avr/io.h>

/*
 * Servo Driver
 * PWM: Timer1
 * Mode: Fast PWM (Mode 14)
 * Frequency: 50 Hz
 * Output Pin: PB1 (OC1A)
 */

void Servo_Init(void)
{
    // Set OC1A (PB1) as output
    DDRB |= (1 << PB1);

    // Fast PWM, Mode 14, non-inverting
    TCCR1A = (1 << COM1A1) | (1 << WGM11);
    TCCR1B = (1 << WGM13)  | (1 << WGM12) | (1 << CS11); // Prescaler 8

    ICR1 = 39999;               // 20 ms period (50 Hz)
    OCR1A = SERVO_MID_PULSE;    // Safe default
}

void Servo_SetPulse(uint16_t pulse)
{
    // Clamp pulse width
    if (pulse < SERVO_MIN_PULSE)
        pulse = SERVO_MIN_PULSE;
    else if (pulse > SERVO_MAX_PULSE)
        pulse = SERVO_MAX_PULSE;

    OCR1A = pulse;
}
