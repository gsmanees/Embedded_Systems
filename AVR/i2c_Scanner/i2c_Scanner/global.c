/*
 * global.c
 *
 * Created: 18-05-2026 6.15.41 AM
 *  Author: anees
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include "global.h"

uint8_t OLED_ADDR   = 0x78;
uint8_t BMP280_ADDR = 0x76;