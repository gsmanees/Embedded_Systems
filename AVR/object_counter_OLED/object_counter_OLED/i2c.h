/*
 * i2c.h
 *
 * Created: 28-12-2025 8.31.26 AM
 *  Author: anees
 */ 


#ifndef I2C_H
#define I2C_H

#include <avr/io.h>

void I2C_Init(void);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_Write(uint8_t data);

#endif
