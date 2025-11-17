/*
 * uart.h
 *
 * Created: 15-11-2025 7.00.16 AM
 *  Author: anees
 */ 


#ifndef UART_H_
#define UART_H_

#include <avr/io.h>
#include <stdlib.h>

#define F_CPU 16000000UL
#define BAUDRATE 9600
#define UBRR_VALUE ((F_CPU / (16UL * BAUDRATE)) - 1)

// === Function Prototypes ===
void UART_Init(void);
void UART_TxChar(char data);
void UART_TxString(const char *str);
void UART_TxHex(uint8_t value);
void UART_TxNumber(uint32_t num);

#endif