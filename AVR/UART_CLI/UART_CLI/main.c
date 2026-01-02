/*
 * UART_CLI.c
 *
 * Created: 02-01-2026 6.43.33 AM
 * Author : anees
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h>
#include <util/delay.h>


/* -------- CLI -------- */
char cmd[16];
uint8_t idx = 0;
uint8_t cmd_ready = 0;
uint8_t danceFlag=0;
/* -------- UART -------- */
void UART_Init(void)
{
	uint16_t ubrr = 103;               // 9600 baud @16MHz
	UBRR0H = ubrr >> 8;
	UBRR0L = ubrr;

	UCSR0B = (1<<RXEN0) | (1<<TXEN0) | (1<<RXCIE0);
	UCSR0C = (1<<UCSZ01) | (1<<UCSZ00);
}

void UART_TxChar(char c)
{
	while (!(UCSR0A & (1<<UDRE0)));
	UDR0 = c;
}

void UART_TxString(const char *s)
{
	while (*s) UART_TxChar(*s++);
}

/* -------- LED -------- */
void LED_Init(void)
	{
		DDRB |= (1<<PORTB5);
		DDRB|=(1<<PORTB4);
	}

void GreenLED_On(void)  
	{ 
		PORTB |=  (1<<PORTB5); 
	}
void GreenLED_Off(void) 
	{ 
		PORTB &= ~(1<<PORTB5); 
	}
	
void RedLED_on(void)
{
	PORTB|=(1<<PORTB4);
}

void RedLED_off(void)
{
	PORTB&=~(1<<PORTB4);
}

void bothLED_on(void)
{
	RedLED_on();
	GreenLED_On();
}

void bothLED_off()
{
	RedLED_off();
	GreenLED_Off();
}

void dance(void)
{
	while (strcmp(cmd,"dance")==0)
	{
		RedLED_on();
		GreenLED_Off();
		_delay_ms(500);
		RedLED_off();
		GreenLED_On();
		_delay_ms(500);
	}
}

void stop(void)
{
	bothLED_off();
}


ISR(USART_RX_vect)
{
	char c = UDR0;

	if (c == '\r' || c == '\n')
	{
		cmd[idx] = '\0';
		idx = 0;
		cmd_ready = 1;
		danceFlag=1;
	}
	else if (idx < sizeof(cmd)-1)
	{
		cmd[idx++] = c;
	}
}

int main(void)
{
	LED_Init();
	UART_Init();
	sei();

	UART_TxString("LED CLI Ready\r\n> ");

	while (1)
	{
		if (!cmd_ready) continue;
		cmd_ready = 0;

		if (strcmp(cmd, "green led on") == 0)
		{
			GreenLED_On();
			UART_TxString("GREEN LED ON\r\n");
		}
		else if (strcmp(cmd, "green led off") == 0)
		{
			GreenLED_Off();
			UART_TxString("GREEN LED OFF\r\n");
		}
		
		else if (strcmp(cmd,"red led on")==0)
		{
			RedLED_on();
			UART_TxString("RED LED ON\r\n");
		}
		
		else if (strcmp(cmd,"red led off")==0)
		{
			RedLED_off();
			UART_TxString("RED LED OFF\r\n");
		}
		
		else if (strcmp(cmd,"both led on")==0)
		{
			RedLED_on();
			GreenLED_On();
			UART_TxString("Both LEDs are ON !\r\n");
		}
		
		else if (strcmp(cmd,"both led off")==0)
		{
			RedLED_off();
			GreenLED_Off();
			UART_TxString("Both LEDs are OFF !\r\n");
			
		}
		
		else if (strcmp(cmd,"dance")==0)
		{
			dance();
			UART_TxString("Dancing !\r\n");
		}
		
		else if (strcmp(cmd,"stop")==0)
		{
			bothLED_off();
		}
		
		
		else if (strcmp(cmd,"help")==0)
		{
			UART_TxString("UART CLI Help Menu\r\n");
			UART_TxString("red led on --> to make RED LED ON\r\n");
			UART_TxString("red led off --> to make RED LED OFF\r\n");
			UART_TxString("green led on --> to make GREEN LED ON\r\n");
			UART_TxString("green led off --> to make GREEN LED OFF\r\n");
			UART_TxString("both led on --> to make both LEDs ON\r\n");
			UART_TxString("both led off --> to make both LEDs OFF\r\n");
			UART_TxString("dance --> to dance both LEDs \r\n");
			UART_TxString("stop --> to stop the dancing & current task and return to start \r\n");
			
		}
		
		else
		{
			UART_TxString("Use: on | off\r\n");
		}

		UART_TxString("> ");
	}
}


