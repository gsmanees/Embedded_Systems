/*
 * cli.h
 *
 * Created: 21-01-2026 6.48.25 AM
 *  Author: anees
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "bmp280.h"
#include "spi.h"
#include "uart.h"
#include "global.h"


#ifndef CLI_H_
#define CLI_H_

void menu(void);
void checkCMD();



#endif /* CLI_H_ */