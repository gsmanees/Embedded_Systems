/*
 * toggleLED.c
 *
 * Created: 10-09-2025 6.05.06 AM
 * Author : anees
 
 Toggle LED with one switch

 PD0 switch, PC5 LED.

 First press ? LED ON, second press ? LED OFF, third press ? LED ON, etc.

 (Hint: You’ll need to detect edge of button press and use a variable to store state).
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    DDRD = 0b00000000;
	PORTD = 0b00000001;
	DDRC = 0b00100000;
	
	// unsigned, 8-bit integer
	uint8_t ledState = 0;
	uint8_t prevButtonState = 1;
	
	
    while (1) 
    {
		uint8_t currentButtonState = (PIND & 0b00000001)?1:0;
		if (prevButtonState == 1 && currentButtonState == 0)
		{
			ledState = !ledState;
		}
		if (ledState)
			PORTC = 0b00100000;
		else
			PORTC = 0b00000000;
	
	prevButtonState = currentButtonState;
	_delay_ms(50);		
    }
}

