/*
 * Q11.c
 *
 * Created: 17-05-2026 2.21.07 PM
 * Author : anees
 
 Write a program to control the angular position of a servo motor based on the analog 
 input received from a potentiometer.
 Requirements: The system must interface a potentiometer with ADC Channel 0 and a 
 servo motor with the OC1A pin (PORTB Pin 1). The program must configure Timer1 in 
 16-bit Phase Correct PWM mode to generate the 50Hz signal required for servo operation. 
 A dedicated function should read the 10-bit analog value from the potentiometer and map 
 it to the corresponding pulse width required to move the servo from 0 to 180 degrees. 
 The motor position must update in real-time as the potentiometer is turned.
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

/* ---------- ADC Initialization ---------- */
void ADC_Init()
{
    ADMUX=(1<<REFS0); // AVCC reference, ADC0 selecte
	// Enable ADC, Prescaler = 128
    ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
}


uint16_t ADC_Read()
{
    ADCSRA|=(1<<ADSC); // Start conversion
    while(ADCSRA&(1<<ADSC)); // Wait until complete
    return ADC;
}

// timer 1 pwm inititlisation
void Servo_PWM_Init()
{
    DDRB|=(1<<PB1); // OC1A as output
    TCCR1A=(1<<COM1A1)|(1<<WGM11);
    TCCR1B=(1<<WGM13)|(1<<CS11); // Prescaler = 8
    ICR1=20000; // 50Hz PWM
    OCR1A=1500; // Initial center position
}

int main(void)
{
    uint16_t adc_value;
    uint16_t pulse_width;

    ADC_Init();
    Servo_PWM_Init();

    while (1)
    {
        // Read potentiometer
        adc_value=ADC_Read();
        pulse_width=1000+((uint32_t)adc_value*1000)/1023;
        // Update servo position
        OCR1A=pulse_width;
        _delay_ms(10);
    }
}

