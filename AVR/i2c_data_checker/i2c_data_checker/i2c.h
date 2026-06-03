/*
 * i2c.h
 *
 * Created: 03-06-2026 02:23:54 PM
 *  Author: anees
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

#ifndef I2C_H_
#define I2C_H_

void I2C_Init(void);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_Write(uint8_t);




#endif /* I2C_H_ */