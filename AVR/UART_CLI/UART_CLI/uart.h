/*
 * uart.h
 *
 * Created: 02-01-2026 9.50.24 PM
 *  Author: anees
 */ 


#ifndef UART_H_
#define UART_H_

void UART_Init(void);
void UART_TxChar(char);
void UART_TxString(const char *);



#endif /* UART_H_ */