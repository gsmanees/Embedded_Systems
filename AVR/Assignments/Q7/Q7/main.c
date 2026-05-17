/*
 * Q7.c
 *
 * Created: 17-05-2026 10.23.24 AM
 * Author : anees
 
 Objective: Write a program that manages two independent timing tasks simultaneously 
 using the 16-bit Timer1 and the 8-bit Timer2.
 Requirements: The system must control two different LEDs. 
 Timer1 must be configured to toggle a "Status LED" on PORTB Pin 1 
 exactly every 2 seconds. Simultaneously, Timer2 must be configured to toggle 
 a "Heartbeat LED" on PORTB Pin 2 every 500 milliseconds. The program must use the 
 Compare Match interrupt for both timers to ensure high precision. Each LED's timing 
 logic must reside in its respective Interrupt Service Routine, allowing both sequences 
 to run independently without interfering with each other.
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint16_t count = 0;// for timer 2 to make 500ms

ISR(TIMER1_COMPA_vect)	// timer 1 ISR
{
    PORTB^=(1<<PORTB1);
}

ISR(TIMER2_COMPA_vect)	// timer 2 ISR
{
    count++;
    if(count>=500)   // 500ms
    {
        PORTB^=(1<<PORTB2);
        count = 0;
    }
}

int main(void)
{
    // setting LED pins as outputs 
    DDRB|=(1<<DDB1)|(1<<DDB2);
	
	// Timer 1 Configuration
    TCCR1B|=(1<<WGM12);     // CTC mode
    OCR1A=31249;              // 2 second delay
    TIMSK1|=(1<<OCIE1A);    // Enable interrupt
    TCCR1B|=(1<<CS12)|(1<<CS10); // Prescaler 1024

	// Timer 2 configuration
    TCCR2A|=(1<<WGM21);     // CTC mode
    OCR2A= 249;                // 1ms delay, from this we will make 500ms
    TIMSK2|=(1<<OCIE2A);    // Enable interrupt
    TCCR2B|=(1<<CS22);      // Prescaler 64
	
    sei();   // Enable global interrupts

    while (1)
    {
    }
}