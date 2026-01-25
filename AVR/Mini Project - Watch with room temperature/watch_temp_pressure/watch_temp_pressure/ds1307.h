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
void DS1307_ReadTimeDate(uint8_t *hh, uint8_t *mm, uint8_t *ss,
uint8_t *dd, uint8_t *mon, uint8_t *yy);
void DS1307_SetDate(uint8_t dd, uint8_t mm, uint8_t yy);
void OLED_PrintCharLarge(char c);
void OLED_Print2DigitLarge(uint8_t value);
void OLED_PrintTimeLarge(uint8_t hh, uint8_t mm, uint8_t ss);
void OLED_PrintChar2x_Safe(char c);
void OLED_Print2Digit2x(uint8_t val);
void OLED_PrintTime2x(uint8_t hh, uint8_t mm);

#endif /* DS1307_H_ */