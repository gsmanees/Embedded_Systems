/*
 * bmp280.h
 *
 * Created: 18-05-2026 6.08.16 AM
 *  Author: anees
 */ 

#include <avr/io.h>

#ifndef BMP280_H_
#define BMP280_H_

void BMP280_Write(uint8_t reg, uint8_t value);
uint16_t BMP280_Read16_LE(uint8_t reg);
int32_t BMP280_Read24(uint8_t reg);
void BMP280_Init(void);
float BMP280_ReadTemperature(void);
float BMP280_ReadPressure(void);




#endif /* BMP280_H_ */