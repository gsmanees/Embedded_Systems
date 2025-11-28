/*
 * hcsr04.h
 *
 * Created: 28-11-2025 11.38.11 PM
 *  Author: anees
 */ 


#ifndef HCSR04_H_
#define HCSR04_H_

#define TRIG PB0
#define ECHO PB1

void hcsr04_EN_trigger(void);
void hcsr04_IO_Init(void);
float measure_distance(void);




#endif /* HCSR04_H_ */