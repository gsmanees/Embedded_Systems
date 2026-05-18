/*
 * pwm.h
 *
 * Created: 17-05-2026 6.06.19 PM
 *  Author: anees
 */ 


#ifndef PWM_H_
#define PWM_H_

#include <avr/io.h>

void PWM_Init(void);
void PWM_SetBrightness(uint8_t percent);


#endif /* PWM_H_ */