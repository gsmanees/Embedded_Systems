/*
 * adc.c
 *
 * Created: 05-01-2026 6.17.58 AM
 *  Author: anees
 */ 

#include "adc.h"

void ADC_Init(void)
{
	ADMUX  = (1 << REFS0);                 // AVcc reference
	ADCSRA = (1 << ADEN)  |                // Enable ADC
	(1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // Prescaler 128
}

uint16_t ADC_Read(uint8_t channel)
{
	channel &= 0x07;                       // ADC0–ADC7
	ADMUX = (ADMUX & 0xF8) | channel;

	ADCSRA |= (1 << ADSC);                 // Start conversion
	while (ADCSRA & (1 << ADSC));           // Wait

	return ADC;
}