/*
 * bmp280.h
 *
 * Created: 02-11-2025 8.15.51 PM
 *  Author: anees
 */ 

#include <avr/io.h>

#ifndef BMP280_H_
#define BMP280_H_
void bmp280_configure(void);
uint32_t bmp280_readTempRegisters(void);
uint8_t bmp280_readChipID(void);



#endif /* BMP280_H_ */