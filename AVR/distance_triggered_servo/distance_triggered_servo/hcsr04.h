/*
 * hcsr04.h
 *
 * Created: 28-11-2025 11.38.11 PM
 *  Author: anees
 */ 


#ifndef HCSR04_H_
#define HCSR04_H_

#define TRIG PB0
#define ECHO PB2

#define HCSR04_PORT PORTB
#define HCSR04_PIN PINB

#define HCSR04_DDR DDRB


void hcsr04_EN_trigger(void);
void hcsr04_IO_Init(void);
float measure_distance(void);
void LED_ON(void);
void LED_OFF(void);
void LED_init(void);
void stop(void);




#endif /* HCSR04_H_ */