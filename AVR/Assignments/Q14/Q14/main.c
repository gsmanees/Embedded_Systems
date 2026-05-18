/*
 * Q14.c
 *
 * Created: 17-05-2026 7.32.27 PM
 * Author : anees
 
 Objective: Write a program to regulate the rotational speed of a DC motor 
 by mapping an analog input signal to a Pulse Width Modulation (PWM) output.
 Requirements: The system must interface a potentiometer with ADC Channel 0 
 and a DC motor via a motor driver connected to the OC0A pin (PORTD Pin 6). 
 The program must configure Timer0 in Fast PWM mode to drive the motor. 
 A dedicated function should be used to read the 10-bit analog value from the 
 potentiometer and scale it to an 8-bit value suitable for the Output Compare 
 Register (OCR0A). The motor speed must respond linearly to the potentiometer position, 
 reaching maximum speed at the highest voltage input and stopping at the lowest.
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>

void ADC_Init()
{
    ADMUX=(1<<REFS0);   // AVCC as reference voltage
    ADCSRA=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0); // Prescaler = 128
}

uint16_t ADC_Read(uint8_t channel)
{
    channel&=0x07;            // Select channel 0-7
    ADMUX=(ADMUX&0xF8)|channel;
    ADCSRA|=(1<<ADSC);        // Start conversion
    while(ADCSRA&(1<<ADSC)); // Wait until conversion complete
    return ADC;
}

void PWM_Init()
{
    DDRD|=(1<<PD6); // Set PD6 (OC0A) as output
    TCCR0A=(1<<COM0A1)|(1<<WGM01)|(1<<WGM00); // Fast PWM Mode, Non-Inverting Mode
    TCCR0B=(1<<CS01)|(1 << CS00);  // Prescaler = 64
    OCR0A=0; // Initial duty cycle = 0%
}

int main(void)
{
    uint16_t adc_value;
    uint8_t pwm_value;

    ADC_Init();
    PWM_Init();

    while (1)
    {
        adc_value=ADC_Read(0);    // Read 10-bit ADC value (0-1023)
        pwm_value=adc_value / 4;  // Scale 10-bit ADC to 8-bit PWM
        OCR0A = pwm_value;       // Update PWM duty cycle
    }
}

