/*
 * i2c.h
 *
 * Created: 22-01-2026 7.22.25 AM
 *  Author: anees
 */ 
#include <avr/io.h>

#ifndef I2C_H_
#define I2C_H_

void TWI_Init(void);
void TWI_Start(void);
void TWI_Stop(void);
void TWI_Write(uint8_t data);
uint8_t TWI_Read_NACK(void);
uint8_t TWI_Read_ACK(void);

#endif /* I2C_H_ */