/*
 * adc.c
 *
 * Created: 13-10-2025 8.50.04 PM
 *  Author: anees
 */ 

#include "adc.h"

void adc_init()
{
	ADMUX|=(1<<REFS0)|(0<<REFS1);
	 // ADLAR =0
	 ADMUX|=(0<<MUX3)|(0<<MUX2)|(0<<MUX1)|(0<<MUX0);
	 ADSRA|=(1<<)
	
	
}