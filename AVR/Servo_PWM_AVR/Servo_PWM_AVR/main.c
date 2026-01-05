/*
 * Servo_PWM_AVR.c
 *
 * Created: 04-01-2026 10.05.03 PM
 * Author : anees
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "adc.h"
#include "servo.h"

int main(void)
{
	uint16_t adc_value;
	uint16_t servo_pulse;

	ADC_Init();
	Servo_Init();

	while (1)
	{
		adc_value = ADC_Read(0);           // Read potentiometer

		// Map ADC (0–1023) to servo pulse (2000–4000)
		servo_pulse = 2000 + ((uint32_t)adc_value * 2000) / 1023;

		OCR1A = servo_pulse;               // Update servo position

		_delay_ms(20);                     // Smooth movement
	}
}

