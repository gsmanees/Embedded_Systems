/*
 * timer.h
 *
 * Created: 28-12-2025 4.40.18 PM
 *  Author: anees
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#ifndef TIMER_H_
#define TIMER_H_

void Timer0_Init(void);

#endif /* TIMER_H_ */