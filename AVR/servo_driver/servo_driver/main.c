/*
 * servo_driver.c
 *
 * Created: 09-01-2026 6.13.37 PM
 * Author : anees
 */ 



#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "servo.h"

int main(void)
{
	Servo_Init();

	while (1)
	{
		Servo_SetPulse(SERVO_MIN_PULSE);  // Closed
		_delay_ms(3000);

		Servo_SetPulse(SERVO_MID_PULSE);  // Center
		_delay_ms(3000);

		Servo_SetPulse(SERVO_MAX_PULSE);  // Open
		_delay_ms(3000);
	}
}


