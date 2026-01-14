/*
 * servo.h
 *
 * Created: 09-01-2026 6.14.47 PM
 *  Author: anees
 */ 


#ifndef SERVO_H
#define SERVO_H

#include <stdint.h>

/* Servo configuration (can be tuned per project) */
#define SERVO_MIN_PULSE   2000   // ~1 ms
#define SERVO_MID_PULSE   3000   // ~1.5 ms
#define SERVO_MAX_PULSE   4000   // ~2 ms

/* Public APIs */
void Servo_Init(void);
void Servo_SetPulse(uint16_t pulse);

#endif
