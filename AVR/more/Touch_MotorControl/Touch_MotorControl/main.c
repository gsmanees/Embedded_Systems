/*
 * Touch_MotorControl.c
 *
 * Created: 05-11-2025 8.27.01 PM
 * Author : anees
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include "uart.h"
#include "nextion.h"



int main(void)
{
	DDRB|=(1<<DDB5); // motor port
	UART_Init(103);
	uint8_t h1, h2, cmd;
    
        while (1)
        {
	        h1 = UART_Read(); // Wait for first byte
	        if (h1 == 0x55)
	        {
		        h2 = UART_Read();
		        if (h2 == 0xAA)
		        {
			        cmd = UART_Read(); // 3rd byte = command
			        if (cmd == 0x01)
			        {
				        // Send back text to display
				        Nextion_SendString("t0.txt=\"Motor ON!\"");
						PORTB|=(1<<PORTB5);
						
			        }
					else if (cmd == 0x02)
					{
						 // Send back text to display
						 Nextion_SendString("t0.txt=\"Motor OFF!\"");
						 PORTB&=~(1<<PORTB5);
					}
		        }
	        }
        }
        
}

					
					
					
					

