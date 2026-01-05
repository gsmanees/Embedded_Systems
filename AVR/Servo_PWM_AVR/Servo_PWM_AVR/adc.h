/*
 * adc.h
 *
 * Created: 05-01-2026 6.17.47 AM
 *  Author: anees
 */ 


#ifndef ADC_H_
#define ADC_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
void ADC_Init(void);
uint16_t ADC_Read(uint8_t);

#endif /* ADC_H_ */