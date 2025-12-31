/*
 * button.h
 *
 * Created: 28-12-2025 4.37.29 PM
 *  Author: anees
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <stdint.h>
#ifndef BUTTON_H_
#define BUTTON_H_

void Button_Init(void);
uint8_t Button_Pressed(uint8_t pin);
/* ---------------- Pin Definitions ---------------- */
#define START_STOP_BTN   PD2
#define RESET_BTN        PD3



#endif /* BUTTON_H_ */