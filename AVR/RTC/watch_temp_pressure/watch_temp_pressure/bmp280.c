/*
 * bmp280.c
 *
 * Created: 15-11-2025 7.40.24 AM
 *  Author: anees
 */ 

#define F_CPU 16000000UL
#include "bmp280.h"
#include <util/delay.h>
#include <avr/io.h>
#include "uart.h"
#include "spi.h"
#include "i2c.h"
#include "oled.h"
#include <string.h>
#include <stdio.h>

char buffer1[32];
char buffer2[32];

uint32_t MSB;
uint32_t LSB;
uint32_t xLSB;
uint32_t rawTemp=0;
uint16_t dig_T1;
int16_t dig_T2, dig_T3; // if used uint instead of int, twmperature reading will be slightly high 
								// for 30 it will show 37
						
int16_t dig_T1_lsb, dig_T1_msb;
uint16_t dig_T3_lsb, dig_T3_msb;
uint16_t dig_T2_msb, dig_T2_lsb;
float rawTemp_float, var1, var2, T, t_fine;


uint32_t msb_p, lsb_p, xlsb_p, rawPressure=0;

uint16_t dig_P1;
int16_t dig_P2, dig_P3,dig_P4,dig_P5,dig_P6,dig_P7,dig_P8,dig_P9;
int16_t dig_P1_msb, dig_P2_msb, dig_P3_msb,dig_P4_msb,dig_P5_msb,dig_P6_msb,dig_P7_msb,dig_P8_msb,dig_P9_msb;
int16_t dig_P1_lsb, dig_P2_lsb, dig_P3_lsb,dig_P4_lsb,dig_P5_lsb,dig_P6_lsb,dig_P7_lsb,dig_P8_lsb,dig_P9_lsb;


void AtmosTrack(void)
{
	UART_TxString("\nAtmosTrack by Anees Kokadan v2.0");
	
	OLED_SetCursor(0, 20);
	OLED_String("AtmosTrack v2.0");
	OLED_SetCursor(1,15);
	OLED_String("By Anees Kokadan");
	_delay_ms(1000);
}

void getChip_ID(void)
{
	uint8_t Chip_ID;
	// first reading chip ID
	PORTB&=~(1<<CS); // CS select
	
	// we need to read the register of chip ID which is 0xD0
	// to read a resister we need to OR the register address with MSB1 (ie; OR with 80)
	SPDR=0xD0|0x80;
	while(!(SPSR&(1<<SPIF)));
	(void)SPDR; // getting garbage from bmp280 chip id register
	
	SPDR=0x00; // sending any value to get chip ID from bmp280
	while(!(SPSR&(1<<SPIF)));
	Chip_ID=SPDR;
	// now we need to deselect CS, if not deselected, chip ID will not get, instead we will get 0x00
	// after de selecting CS, we will get chip id as 0x58 as per data sheet
	PORTB|=(1<<CS); // communication stops while we de select CS
	
	
	UART_TxString("Chip ID: ");
	UART_TxHex(Chip_ID);
	
	
}

void getMSB(void)
{
	
	PORTB&=~(1<<CS); // making CS as LOW to start communication
	SPDR=0xFA|80; // MSB is stored on 0xFA register, ORed with 80 to start read operation from the register
	while(!(SPSR&(1<<SPIF))); // wait until communication complete 
	(void)SPDR; // it will reply the dummy value inside 0xFA
	SPDR=0x00; // writing any value to get the exact value stored on 0xFA register, whioch is MSB
	while(!(SPSR&(1<<SPIF)));
	MSB=SPDR;
	
	PORTB|=(1<<CS); //making CS HIGH for stopping communication
	/*
	UART_TxString("MSB: ");
	UART_TxNumber(MSB);
	UART_TxString("\r\n");
	*/
	
}


void getLSB(void)
{
	
	PORTB&=~(1<<CS); // making CS as LOW to start communication
	SPDR=0xFB|80; // LSB is stored on 0xFB register, ORed with 80 to start read operation from the register
	
	while(!(SPSR&(1<<SPIF))); // wait until communication complete
	(void)SPDR; // it will reply the dummy value inside 0xFB
	SPDR=0x00; // writing any value to get the exact value stored on 0xFB register, which is LSB
	while(!(SPSR&(1<<SPIF)));
	LSB=SPDR;
	PORTB|=(1<<CS); //making CS HIGH for stopping communication
	/*
	UART_TxString("LSB: ");
	UART_TxNumber(LSB);
	UART_TxString("\r\n");
	*/
}

void getxLSB(void)
{
	
	PORTB&=~(1<<CS); // making CS as LOW to start communication
	SPDR=0xFC|80; // xLSB is stored on 0xFc register, ORed with 80 to start read operation from the register
	
	while(!(SPSR&(1<<SPIF))); // wait until communication complete
	(void)SPDR; // it will reply the dummy value inside 0xFC
	SPDR=0x00; // writing any value to get the exact value stored on 0xFC register, which is xLSB
	while(!(SPSR&(1<<SPIF)));
	xLSB=SPDR;
	PORTB|=(1<<CS); //making CS HIGH for stopping communication
	/*
	UART_TxString("xLSB: ");
	UART_TxNumber(xLSB);
	UART_TxString("\r\n");
	*/
}

void getRawTemp(void)
{
	getMSB();
	getLSB();
	getxLSB();
	rawTemp=(uint32_t)(MSB<<12)|(uint32_t)(LSB<<4)|(uint32_t)(xLSB>>4);
	/*
	UART_TxString("Raw Temp: ");
	UART_TxNumber(rawTemp);
	UART_TxString("\r\n");
	*/
}


// Get Temperature Compensation values 
/*
Constant	Address (LSB)	Address (MSB)	Data type	Bits	Example value
dig_T1		0x88			0x89			uint16_t	16		27504
dig_T2		0x8A			0x8B			uint16_t	16		26435
dig_T3		0x8C			0x8D			uint16_t	16		-1000

*/

// finding dig_T1
void get_dig_T1(void)
{
	
	PORTB&=~(1<<CS); // start communication
	
	SPDR=0x88|0x80;
	while(!(SPSR&(1<<SPIF)));
	(void)SPDR;
	
	SPDR=0x00;
	while(!(SPSR&(1<<SPIF)));
	dig_T1_lsb=SPDR;
	
	SPDR=0x00;
	while(!(SPSR&(1<<SPIF)));
	dig_T1_msb=SPDR;
	
	PORTB|=(1<<CS); // stop communication
	
	// combine msb and lsb to get 16 bit dig_T1 value 
	dig_T1=(int16_t)(dig_T1_msb<<8)|(int16_t)(dig_T1_lsb);
	
	UART_TxString("dig_T1: ");
	UART_TxNumber(dig_T1);
	UART_TxString("\r\n");
	
}



// finding dig_T2
void get_dig_T2(void)
{
	
	PORTB&=~(1<<CS);// start
	
	SPDR=0x8A|0x80;
	while(!(SPSR&(1<<SPIF)));
	(void)SPDR;
	
	SPDR=0x00;
	while(!(SPSR&(1<<SPIF)));
	dig_T2_lsb=SPDR;
	
	SPDR=0x00;
	while(!(SPSR&(1<<SPIF)));
	dig_T2_msb=SPDR;
	
	PORTB|=(1<<CS); // stop
	
	// combine msb and lsb to get 16 bit dig_T2 value 
	dig_T2=(int16_t)(dig_T2_msb<<8)|(int16_t)(dig_T2_lsb);
	
	UART_TxString("dig_T2: ");
	UART_TxNumber(dig_T2);
	UART_TxString("\r\n");
	
}


// finding dig_T3
void get_dig_T3(void)
{
	
	PORTB&=~(1<<CS);  // start
	
	SPDR=0x8C|0x80;
	while(!(SPSR&(1<<SPIF)));
	(void)SPDR;
	
	SPDR=0x00;
	while(!(SPSR&(1<<SPIF)));
	dig_T3_lsb=SPDR;
	
	SPDR=0x00;
	while(!(SPSR&(1<<SPIF)));
	dig_T3_msb=SPDR;
	
	PORTB|=(1<<CS);  // stop
	
	// combine msb and lsb to get 16 bit dig_T3 value 
	dig_T3=(int16_t)(dig_T3_msb<<8)|(int16_t)(dig_T3_lsb);
	
	UART_TxString("dig_T3: ");
	UART_TxNumber(dig_T3);
	UART_TxString("\r\n");
	
}


void ctrl_meas(void)
{
	uint16_t ctrl_meas;
	// ctrl_meas register is 0xF4, we need to write 0x27 to this register 
	PORTB&=~(1<<CS);
	// configure reg for writing, ie we need to AND with 7F
	
	SPDR=0xF4 & 0x7F; // ctrl_meas writing mode
	while(!(SPSR&(1<<SPIF)));
	(void)SPDR;
	
	SPDR=0x27;
	while(!(SPSR&(1<<SPIF)));
	(void)SPDR;
	PORTB|=(1<<CS);
	
	// check ctrl_meas
	PORTB&=~(1<<CS);
	SPDR=0xF4|0x80; // ctrl_meas reading mode 
	while(!(SPSR&(1<<SPIF)));
	(void)SPDR;
	
	SPDR=0x00;
	while(!(SPSR&(1<<SPIF)));
	ctrl_meas=SPDR;
	PORTB|=(1<<CS);
	/*
	UART_TxString("\nctrl_meas: ");
	UART_TxHex(ctrl_meas);
	*/
	
	
}

void realTemp(void)
{
	// T = t_fine / 5120.0
	// t_fine = var1+var2
	// var1= ( (rawTemp_float/16384.0) - (dig_T1/1024.0) )* dig_T2
	// var2 =  ((rawTemp_float/131072.0) - (dig_T2/8192.0))* dig_T3
	
	
	 rawTemp_float = (float) rawTemp;
	 var1=(((rawTemp_float/16384.0f)-((float)dig_T1/1024.0f))*(float)dig_T2);
	 var2 =  ((rawTemp_float/131072.0f) - (dig_T2/8192.0f))* dig_T3;
	 /*var2 = (((rawTemp_float/131072.0f) - ((float)dig_T1/8192.0f)) *
	 ((rawTemp_float/131072.0f) - ((float)dig_T1/8192.0f))) *
	 (float)dig_T3;*/
;

	 t_fine = var1+var2;
	 T = t_fine/5120.0f;
	 UART_TxString("\nReal time room temperature: ");
	 UART_TxFloat(T, 2);
	 UART_TxString(" C\n");
	
	 
	 OLED_SetCursor(5,31);

	 OLED_PrintFloat_2Decimal(T);

	 OLED_String(" C"); // for C	 
}


void getRawPressure(void)
{
	ctrl_meas();
	PORTB&=~(1<<CS); // start communication, here using burst mode (continous SPI transactions)
	//reading pressure msb
	// Pressure raw registers: 0xF7 (MSB), 0xF8 (LSB), 0xF9 (XLSB)
	SPDR=0xF7|0x80; // msb configured for reading 
	while(!(SPSR&(1<<SPIF)));
	(void)SPDR; // dummy 1
	

	
	SPDR=0x00;
	while(!(SPSR&(1<<SPIF)));
	msb_p=SPDR;
	
	SPDR=0x00;
	while(!(SPSR&(1<<SPIF)));
	lsb_p=SPDR;
	
	SPDR=0x00;
	while(!(SPSR&(1<<SPIF)));
	xlsb_p=SPDR;
	
	PORTB|=(1<<CS); // stop communication
	
	rawPressure=((uint32_t)(msb_p<<12))|((uint32_t)(lsb_p<<4))|((uint32_t)(xlsb_p>>4));
	/*
	UART_TxString("\nmsb_p: "); UART_TxNumber(msb_p);
	UART_TxString("\nlsb_p: "); UART_TxNumber(lsb_p);
	UART_TxString("\nxlsb_p: "); UART_TxNumber(xlsb_p);
	
	UART_TxString("\nRaw Pressure: ");
	UART_TxNumber(rawPressure);
	//UART_TxString("\r\n");
	*/
}

void readCalib(void)
{
	/*
	| Register Address | Bytes | Parameter  | Type       |
	| ---------------- | ----- | ---------- | ---------- |
	| 0x88 / 0x89      | 2     | **dig_T1** | `uint16_t` |
	| 0x8A / 0x8B      | 2     | **dig_T2** | `int16_t`  |
	| 0x8C / 0x8D      | 2     | **dig_T3** | `int16_t`  |
	| 0x8E / 0x8F      | 2     | **dig_P1** | `uint16_t` |
	| 0x90 / 0x91      | 2     | **dig_P2** | `int16_t`  |
	| 0x92 / 0x93      | 2     | **dig_P3** | `int16_t`  |
	| 0x94 / 0x95      | 2     | **dig_P4** | `int16_t`  |
	| 0x96 / 0x97      | 2     |            |            |

	
	*/
	
	
	
	PORTB&=~(1<<CS); //start communication
	SPDR=0x88|0x80; // to read first calib value, ie; dig_T1
	while(!(SPSR&(1<<SPIF)));
	(void)SPDR; // getting garbage
	
	// temperature calibtation constants 
	
	SPDR=0x00;
	while(!(SPSR&(1<<SPIF)));
	dig_T1_lsb=SPDR;
	
	SPDR=0x00;
	while(!(SPSR&(1<<SPIF)));
	dig_T1_msb=SPDR;
	
	SPDR=0x00;
	while(!(SPSR&(1<<SPIF)));
	dig_T2_lsb=SPDR;
	
	SPDR=0x00;
	while(!(SPSR&(1<<SPIF)));
	dig_T2_msb=SPDR;
	
	SPDR=0x00;
	while(!(SPSR&(1<<SPIF)));
	dig_T3_lsb=SPDR;
	
	SPDR=0x00;
	while(!(SPSR&(1<<SPIF)));
	dig_T3_msb=SPDR;
	
	// Reading pressure calibration constants
	SPDR=0x00;
	while(!(SPSR&(1<<SPIF)));
	dig_P1_lsb=SPDR;
	
	SPDR=0x00;
	while(!(SPSR&(1<<SPIF)));
	dig_P1_msb=SPDR;
	
	SPDR=0x00;
	while(!(SPSR&(1<<SPIF)));
	dig_P2_lsb=SPDR;
	
	SPDR=0x00;
	while(!(SPSR&(1<<SPIF)));
	dig_P2_msb=SPDR;
	
	SPDR=0x00;
	while(!(SPSR&(1<<SPIF)));
	dig_P3_lsb=SPDR;
	
	SPDR=0x00;
	while(!(SPSR&(1<<SPIF)));
	dig_P3_msb=SPDR;
	
	SPDR=0x00;
	while(!(SPSR&(1<<SPIF)));
	dig_P4_lsb=SPDR;
	
	SPDR=0x00;
	while(!(SPSR&(1<<SPIF)));
	dig_P4_msb=SPDR;
	
	SPDR=0x00;
	while(!(SPSR&(1<<SPIF)));
	dig_P5_lsb=SPDR;
	
	SPDR=0x00;
	while(!(SPSR&(1<<SPIF)));
	dig_P5_msb=SPDR;
	
	SPDR=0x00;
	while(!(SPSR&(1<<SPIF)));
	dig_P6_lsb=SPDR;
	
	SPDR=0x00;
	while(!(SPSR&(1<<SPIF)));
	dig_P6_msb=SPDR;
	
	SPDR=0x00;
	while(!(SPSR&(1<<SPIF)));
	dig_P7_lsb=SPDR;
	
	SPDR=0x00;
	while(!(SPSR&(1<<SPIF)));
	dig_P7_msb=SPDR;
	
	SPDR=0x00;
	while(!(SPSR&(1<<SPIF)));
	dig_P8_lsb=SPDR;
	
	SPDR=0x00;
	while(!(SPSR&(1<<SPIF)));
	dig_P8_msb=SPDR;
	
	SPDR=0x00;
	while(!(SPSR&(1<<SPIF)));
	dig_P9_lsb=SPDR;
	
	SPDR=0x00;
	while(!(SPSR&(1<<SPIF)));
	dig_P9_msb=SPDR;
	
	
	// combining msb and lsb for dig_p1 to dig_p9 to get the actual reg value 
	
	dig_T1=(int16_t)(dig_T1_msb<<8)|(int16_t)dig_T1_lsb;
	dig_T2=(int16_t)(dig_T2_msb<<8)|(int16_t)dig_T2_lsb;
	dig_T3=(int16_t)(dig_T3_msb<<8)|(int16_t)dig_T3_lsb;
	
	dig_P1=(int16_t)(dig_P1_msb<<8)|(int16_t)dig_P1_lsb;
	dig_P2=(int16_t)(dig_P2_msb<<8)|(int16_t)dig_P2_lsb;
	dig_P3=(int16_t)(dig_P3_msb<<8)|(int16_t)dig_P3_lsb;
	dig_P4=(int16_t)(dig_P4_msb<<8)|(int16_t)dig_P4_lsb;
	dig_P5=(int16_t)(dig_P5_msb<<8)|(int16_t)dig_P5_lsb;
	dig_P6=(int16_t)(dig_P6_msb<<8)|(int16_t)dig_P6_lsb;
	dig_P7=(int16_t)(dig_P7_msb<<8)|(int16_t)dig_P7_lsb;
	dig_P8=(int16_t)(dig_P8_msb<<8)|(int16_t)dig_P8_lsb;
	dig_P9=(int16_t)(dig_P9_msb<<8)|(int16_t)dig_P9_lsb;
	
	/*
	
	UART_TxString("\ndig_T1: ");
	UART_TxNumber(dig_T1);
	UART_TxString("\r\n");
	
	UART_TxString("dig_T2: ");
	UART_TxNumber(dig_T2);
	UART_TxString("\r\n");
	
	UART_TxString("dig_T3: ");
	UART_TxNumber(dig_T3);
	UART_TxString("\r\n");
	
	UART_TxString("dig_P1: ");
	UART_TxNumber(dig_P1);
	UART_TxString("\r\n");
	
	UART_TxString("dig_P2: ");
	UART_TxNumber(dig_P2);
	UART_TxString("\r\n");
	
	UART_TxString("dig_P3: ");
	UART_TxNumber(dig_P3);
	UART_TxString("\r\n");
	
	UART_TxString("dig_P4: ");
	UART_TxNumber(dig_P4);
	UART_TxString("\r\n");
	
	UART_TxString("dig_P5: ");
	UART_TxNumber(dig_P5);
	UART_TxString("\r\n");
	
	UART_TxString("dig_P6: ");
	UART_TxNumber(dig_P6);
	UART_TxString("\r\n");
	
	UART_TxString("dig_P7: ");
	UART_TxNumber(dig_P7);
	UART_TxString("\r\n");
	
	UART_TxString("dig_P8: ");
	UART_TxNumber(dig_P8);
	UART_TxString("\r\n");
	
	UART_TxString("dig_P9: ");
	UART_TxNumber(dig_P9);
	UART_TxString("\r\n");
	*/
}

void realPressure(void)
{
	float var1=0, var2=0, p=0;
	var1=((double)t_fine)/2.0-64000.0;
	var2=var1*var2*((double)dig_P6)/32768.0;
	var2=var2*var1*((double)dig_P5)*2.0;
	var2=((var2/4.0)+((double)dig_P4)*65536.0);
	var1=(((double)dig_P3)*var1*var1/524288.0+((double)dig_P2)*var1)/524288.0;
	var1=(1.0+var1/32768.0)*((double)dig_P1);
	p=1048576.0-(double)rawPressure;
	p=(p-(var2/4096.0))*6250.0/var1;
	var1=((double)dig_P9)*p*p/2147483648.0;
	var2=p*((double)dig_P8)/32768.0;
	p=p+(var1+var2+((double)dig_P7))/16.0;
	p=p/100;
	UART_TxString("\nAtm. Pressure: ");
	UART_TxFloat(p, 2);UART_TxString(" hPa");
	UART_TxString("\n");
	
/*	OLED_SetCursor(7, 35);*/
	//OLED_String(" Atm. Pressure:");
// 	OLED_SetCursor(7, 0);
// 	sprintf(buffer2, " %.2f", p);
//  	OLED_String(buffer2);
//  	OLED_String(" hPa");

	OLED_SetCursor(7,20);
	OLED_PrintFloat_2Decimal(p);
	OLED_String(" hPa");

	
}