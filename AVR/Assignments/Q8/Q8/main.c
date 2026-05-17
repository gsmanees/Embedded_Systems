/*
 * Q8.c
 *
 * Created: 17-05-2026 11.15.23 AM
 * Author : anees
 
 Objective: Write a program to control the brightness of an LED or the speed 
 of a small DC motor using the hardware PWM capability of Timer0.
 Requirements: The program must initialize Timer0 in Fast PWM mode with the 
 output directed to the OC0A pin (PORTD Pin 6). The system should start with a 25%
 duty cycle. A push-button connected to an input pin should be used to cycle the 
 duty cycle through four levels: 25%, 50%, 75%, and 100% OFF. Each time the 
 button is pressed, the program should update the Output Compare Register (OCR0A) 
 to the next level. The transition between speeds must be handled by a dedicated 
 function that updates the timer registers.
 */ 


#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

uint8_t level=0;

void setDutyCycle(uint8_t duty)
{

	OCR0A=duty;
}

int main(void)
{
	DDRD|=(1<<DDD6); // setting PD6 as output, OCROA is conntected to this pin
	DDRD&=~(1<<DDD2); // PD2 set as input
	PORTD|=(1<<PORTD2); // internal pull up on PD2 activated

	// timer configuration
	TCCR0A|=(1<<COM0A1);  // Non-inverting PWM
	TCCR0A|=(1<<WGM00)|(1<<WGM01); // Fast PWM mode
	TCCR0B|=(1<<CS01)|(1<<CS00); // Prescaler 64, which is 25% of duty cycle

	while(1)
	{
		if (!(PIND&(1<<PIND2))) // checking button press
		{
			
			_delay_ms(200); //small delay after button press
			level++;
			if(level>3)
			level=0;
			
			//Change PWM Duty Cycle 
			switch(level)
			{
				case 0:setDutyCycle(64); // 25%
				break;
				case 1:setDutyCycle(128); // 50%
				break;
				case 2:setDutyCycle(192);  // 75%
				break;
				case 3:setDutyCycle(255); // 100%
				break;				
			}
			while(!(PIND&(1<<PIND2)));
		}
	}
}