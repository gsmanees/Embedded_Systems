/*
 * uart.h
 *
 * Created: 03-06-2026 02:22:02 PM
 *  Author: anees
 */ 


#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

#ifndef UART_H_
#define UART_H_

void UART_Init(void);
char UART_RxChar(void);
void UART_TxChar(char);



#endif /* UART_H_ */