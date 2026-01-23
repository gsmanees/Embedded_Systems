/*
 * uart.h
 *
 * Created: 22-01-2026 7.21.16 AM
 *  Author: anees
 */ 
#include <stdint.h>

#ifndef UART_H_
#define UART_H_

void UART_Init(void);
void UART_TxChar(char c);
void UART_TxString(const char *s);
void UART_TxNumber(uint8_t num);

#endif /* UART_H_ */