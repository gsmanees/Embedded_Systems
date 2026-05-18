/*
 * i2c.h
 *
 * Created: 18-05-2026 6.02.10 AM
 *  Author: anees
 */ 


#include <avr/io.h>
#ifndef I2C_H_
#define I2C_H_

void I2C_Init(void);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_Write(uint8_t data);
uint8_t I2C_Read_ACK(void);
uint8_t I2C_Read_NACK(void);




#endif /* I2C_H_ */