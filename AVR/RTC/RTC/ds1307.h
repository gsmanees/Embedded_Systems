/*
 * ds1307.h
 *
 * Created: 22-01-2026 7.25.08 AM
 *  Author: anees
 */ 
#include <stdint.h>

#ifndef DS1307_H_
#define DS1307_H_

uint8_t BCD_to_DEC(uint8_t bcd);
uint8_t DS1307_ReadSeconds(void);
void DS1307_StartClock(void);

#endif /* DS1307_H_ */