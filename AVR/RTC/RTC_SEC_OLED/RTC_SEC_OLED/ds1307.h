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
void DS1307_ReadTime(uint8_t *hh, uint8_t *mm, uint8_t *ss);
uint8_t DEC_to_BCD(uint8_t dec);
void DS1307_SetTime(uint8_t hh, uint8_t mm, uint8_t ss);

#endif /* DS1307_H_ */