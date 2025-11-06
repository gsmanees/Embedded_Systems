/*
 * spi.c
 *
 * Created: 29-10-2025 8.42.41 PM
 * Author : anees
 

 SPI Serial Peripheral Interface
 MOSI - Master Out Slave In
 MISO - Master In Slave Out
 SCK - Serial Clock
 SS / CS - Slave Select / Chip Select
 */ 


#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


#define SS_DDR DDB2 // SS_DDR DEFINED AS DDB2
#define MOSI_DDR DDB3  // MOSI_DDR DEFINED AS DDB3
#define MISO_DDR DDB4 // MISO_DDR DEFINED AS DDB4
#define SCK_DDR DDB5 // SCK_DDR DEFINED AS DDB5
#define LED_DDR DDD3 // led ddr

#define SS_PORT PORTB2 // SS_PORT DEFINED AS PORTB2
#define MOSI_PORT PORTB3 // MOSI_PORT DEFINED AS PORTB3
#define MISO_PORT PORTB4 // MISO_PORT DEFINED AS PORTB4
#define SCK_PORT PORTB5 // SCK_PORT DEFINED AS PORTB5
#define LED_PORT PORTD3 // LED PORT DEFINED 


int main(void)
{
	uint8_t Chip_ID;
	// Setting data directions for SPI lines 
	// SS --> output, MOSI --> output, MISO --> input, SCK --> output
	DDRB|=(1<<SS_DDR)|(1<<MOSI_DDR)|(1<<SCK_DDR);
	DDRB&=~(1<<MISO_DDR);
	
	// making LED port as output
	DDRD|=(1<<LED_DDR);
    
	// Enabling SPI & Configure it as Master 
	SPCR|=(1<<SPE)|(1<<MSTR)|(1<<SPR0);
	SPCR&=~(1<<CPOL);
	SPCR&=~(1<<CPHA);
	
	//_delay_ms(100);
	// making SS_PORT as LOW --> to start communication from master to slave
	PORTB&=~(1<<SS_PORT); 
	
	// loading SPDR with BMP280 internal register (0xd0) address and ORing with 0x80 to make MSB as 1 for Reading 
	// if MSB is 0 --> writing, if MSB is 1 --> for reading 
	
	SPDR=0xD0|0x80; // set as for reading 
	while(!(SPSR&(1<<SPIF))); // waiting until communication finishes, when transfer complete it will be set to 1
	
	// the garbage value inside the slave is now in SPDR, we are just reading it to another dummy variable to make  SPIF clear
	(void)SPDR; // now SPIF is cleared 
	
	// making SS as high to stop transfer 
	//PORTB|=(1<<SS_PORT);  // now communication finished 
	
	//_delay_ms(100);
	// making SS as low for another communication
	//PORTB&=~(1<<SS_PORT); 
	SPDR=0x00; // we are just sending any data to slave; to get the value inside slave register back to SPDR 
	while(!(SPSR&(1<<SPIF))); // waiting until transfer complete 
	Chip_ID=SPDR; // now value inside SPDR is copied to another variable Chip_ID, now SPIF is cleared 
	PORTB|=(1<<SS_PORT); // making SS line as high, stop SPI
	//_delay_ms(100);
	// LED code 
	
	
	 
    while (1) 
    {
		if (Chip_ID==0x58)
		{
			PORTD|=(1<<LED_PORT);
		}
		
		else
		{
			PORTD&=~(1<<LED_PORT);
		}
    }
}

