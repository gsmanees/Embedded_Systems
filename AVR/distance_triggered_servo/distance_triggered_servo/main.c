/*
 * distance_triggered_servo.c
 *
 * Created: 14-01-2026 7.19.56 AM
 * Author : anees
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "hcsr04.h"
#include "servo.h"

int main(void)
{
	float distance=0;
	hcsr04_IO_Init();
	LED_init();
	Servo_Init();
	while (1)
	{
		hcsr04_EN_trigger();
		distance=10*measure_distance();
		
		if (distance<=10)
		{
			Servo_SetPulse(SERVO_MAX_PULSE);
			LED_ON();
			_delay_ms(2000);
		}
		else if (distance>10)
		{
			LED_OFF();
			Servo_SetPulse(SERVO_MIN_PULSE);
		}
	}
}


