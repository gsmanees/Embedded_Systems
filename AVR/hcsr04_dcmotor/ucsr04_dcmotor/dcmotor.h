/*
 * dcmotor.h
 *
 * Created: 04-12-2025 7.07.12 AM
 *  Author: anees
 */ 

#ifndef DCMOTOR_H_
#define DCMOTOR_H_

#define motor_P PORTB4
#define motor_N PORTB5
void motor_init(void);
void motorON(void);
void motorOFF(void);

#endif /* DCMOTOR_H_ */


