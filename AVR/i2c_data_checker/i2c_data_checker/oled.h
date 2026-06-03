/*
 * oled.h
 *
 * Created: 03-06-2026 02:25:33 PM
 *  Author: anees
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

#ifndef OLED_H_
#define OLED_H_

void OLED_Command(uint8_t);
void OLED_Data(uint8_t);
void OLED_Init(void);





#endif /* OLED_H_ */