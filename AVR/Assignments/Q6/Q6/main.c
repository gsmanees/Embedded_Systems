/*
 * Q6.c
 *
 * Created: 17-05-2026 5.50.43 AM
 * Author : anees
 
 Objective: Write a program to manage a traffic light sequence that includes 
 a high-priority interrupt designed to trigger a state change only after the 
 current light cycle completes its minimum safe duration.
 
 Requirements: The system must control three LEDs (Green, Orange, and Red) 
 connected to PORTB. Under normal operation, the program should cycle through 
 the Green (10s), Orange (3s), and Red (10s) states in a continuous loop. 
 An emergency push-button must be interfaced with the External Interrupt 0 (INT0) pin. 
 When the button is pressed, the program should set a flag within the Interrupt Service 
 Routine (ISR) rather than jumping states immediately. The main program logic must check 
 this flag at the end of the current light's duration. If the flag is set, the system must 
 then prioritize the Green light for a set duration before clearing the flag and resuming 
 the normal cycle.
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

/*
Circuit connection details:
Green LED --> PB5
Orange LED --> PB4
Red LED --> PB3
Emergency LED --> PB2

Button --> PD2, for INT0
*/

volatile uint8_t emergency_flag=0;

void delay_10s()
{
	int i;
	int count=610;
	for (i=0; i<count; i++)
	{
		TCNT0=0;
		TCCR0A=0;
		TCCR0B|=(1<<CS00)|(1<<CS02); // prescalar 1024
		TIFR0|=(1<<TOV0);
		while (!(TIFR0&(1<<TOV0)));
	}
}

void delay_3s()
{
	int i;
	int count=183;
	for (i=0; i<count; i++)
	{
		TCNT0=0;
		TCCR0A=0;
		TCCR0B|=(1<<CS00)|(1<<CS02); // prescalar 1024
		TIFR0|=(1<<TOV0);
		while (!(TIFR0&(1<<TOV0)));
	}
}

ISR(INT0_vect)
{
	emergency_flag=1;
}

void emergeny_green()
{
	/*
	To identify the emergency situation easily I have added an additional LED on PB2
	by this, if ISR executed and flag set=1, this LED also becomes ON, so we can easily 
	identify the ISR has been successsfully executed 
	
	*/
	emergency_flag=0;
	PORTB|=(1<<PORTB2);
	PORTB|=(1<<PORTB5);
	delay_3s();
	PORTB&=~(1<<PORTB2);
	PORTB&=~(1<<PORTB5);
}

int main(void)
{
    #define GreenLED PORTB5
    #define OrangeLED PORTB4
    #define RedLED PORTB3
	#define button PORTD2
		
	DDRB|=(1<<GreenLED)|(1<<OrangeLED)|(1<<RedLED)|(1<<DDB2);	// set direction for LED as output
	DDRD&=~(1<<button);	// button pin as input, int0 pin
	PORTD|=(1<<button);						// enabled internal pullup
		
	EIMSK|=(1<<INT0);	// int0 enabled 
	// interrupt on falling edge 
	EICRA|=(1<<ISC01);
	EICRA&=~(1<<ISC00);
	sei(); // global interrupts enabled 
		
    while (1) 
    {
		PORTB|=(1<<GreenLED); //Green
		delay_10s();
		
		PORTB&=~(1<<GreenLED);
		if (emergency_flag)
		{
			emergeny_green();
		}
		
		PORTB|=(1<<OrangeLED); // orange
		delay_3s();
		PORTB&=~(1<<OrangeLED);
		
		if (emergency_flag)
		{
			emergeny_green();
		}
		
		PORTB|=(1<<RedLED);		// red LED
		delay_10s();
		PORTB&=~(1<<RedLED);
		
		if (emergency_flag)
		{
			emergeny_green();
		}
	}
}

