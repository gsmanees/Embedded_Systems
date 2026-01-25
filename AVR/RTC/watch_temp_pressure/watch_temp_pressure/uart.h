/*
 * uart.h
 *
 * Created: 22-01-2026 7.21.16 AM
 *  Author: anees
 */ 
#include <stdint.h>
#include "global.h"

#ifndef UART_H_
#define UART_H_

void UART_Init(void);
void UART_TxChar(char c);
void UART_TxString(const char *s);
void UART_TxNumber(uint8_t num);
void UART_TxFloat(float value, uint8_t decimalPlaces);
void UART_printTime(void);
void UART_printDate(void);

#endif /* UART_H_ */