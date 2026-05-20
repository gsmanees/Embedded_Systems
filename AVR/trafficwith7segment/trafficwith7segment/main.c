/*
 * trafficwith7segment.c
 *
 * Created: 20-05-2026 6.57.53 AM
 * Author : anees
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>

// 7 SEGMENT DATA (COMMON CATHODE)
unsigned char digits[10] =
{
	0x3F, // 0
	0x06, // 1
	0x5B, // 2
	0x4F, // 3
	0x66, // 4
	0x6D, // 5
	0x7D, // 6
	0x07, // 7
	0x7F, // 8
	0x6F  // 9
};

// 1 SECOND DELAY USING TIMER0
void delay_1s()
{
	int i;
	for(i=0; i<61; i++)
	{
		TCNT0=0;
		TCCR0A=0;
		TCCR0B=(1<<CS00)|(1<<CS02);  // Prescaler = 1024
		TIFR0 |= (1<<TOV0);  // Clear overflow flag	
		while(!(TIFR0 & (1<<TOV0)));  // Wait for overflow
		TCCR0B = 0;  // Stop timer
	}
}

// COUNTDOWN FUNCTION
void countdown(int sec)
{
	int i;
	for(i=sec; i>=0; i--)
	{
		// Display number on 7 segment
		PORTD = digits[i];
		delay_1s();
	}
}

// MAIN PROGRAM
int main(void)
{
	// LED definitions
	#define GreenLED PORTB5
	#define OrangeLED PORTB4
	#define RedLED PORTB3

	// LED pins output
	DDRB|=(1<<DDB5)|(1<<DDB4)|(1<<DDB3);

	// 7 segment pins output
	// PD0-PD6 used for a,b,c,d,e,f,g
	DDRD=0x7F;

	while(1)
	{
		// GREEN 
		PORTB |= (1<<GreenLED);
		countdown(9);
		PORTB &= ~(1<<GreenLED);
		
		// ORANGE
		PORTB|=(1<<OrangeLED);
		countdown(3);
		PORTB&=~(1<<OrangeLED);

		// RED 
		PORTB|=(1<<RedLED);
		countdown(9);
		PORTB&=~(1<<RedLED);
	}
}

