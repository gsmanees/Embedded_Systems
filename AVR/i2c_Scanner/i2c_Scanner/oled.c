/*
 * oled.c
 *
 * Created: 18-05-2026 6.05.31 AM
 *  Author: anees
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "oled.h"
#include "i2c.h"
#include "global.h"

void OLED_Command(uint8_t cmd)
{
	I2C_Start();
	I2C_Write(OLED_ADDR);
	I2C_Write(0x00);
	I2C_Write(cmd);

	I2C_Stop();
}

void OLED_Data(uint8_t data)
{
	I2C_Start();
	I2C_Write(OLED_ADDR);
	I2C_Write(0x40);
	I2C_Write(data);
	I2C_Stop();
}

void OLED_Init(void)
{
	_delay_ms(100);

	OLED_Command(0xAE);
	OLED_Command(0xD5);
	OLED_Command(0x80);
	OLED_Command(0xA8);
	OLED_Command(0x3F);
	OLED_Command(0xD3);
	OLED_Command(0x00);
	OLED_Command(0x40);
	OLED_Command(0x8D);
	OLED_Command(0x14);
	OLED_Command(0x20);
	OLED_Command(0x00);
	OLED_Command(0xA1);
	OLED_Command(0xC8);
	OLED_Command(0xDA);
	OLED_Command(0x12);
	OLED_Command(0x81);
	OLED_Command(0xCF);
	OLED_Command(0xD9);
	OLED_Command(0xF1);
	OLED_Command(0xDB);
	OLED_Command(0x40);
	OLED_Command(0xA4);
	OLED_Command(0xA6);
	OLED_Command(0xAF);
}

void OLED_Clear(void)
{
	uint8_t page, col;

	for(page=0; page<8; page++)
	{
		OLED_Command(0xB0 + page);
		OLED_Command(0x00);
		OLED_Command(0x10);

		for(col=0; col<128; col++)
		{
			OLED_Data(0x00);
		}
	}
}

void OLED_SetCursor(uint8_t row, uint8_t col)
{
	OLED_Command(0xB0 + row);
	OLED_Command(0x00 + (col & 0x0F));
	OLED_Command(0x10 + ((col >> 4) & 0x0F));
}

void OLED_Char(char ch)
{
	uint8_t i;
	uint8_t font[5];

	/* SPACE */
	if(ch == ' ')
	{
		for(i=0;i<6;i++)
		{
			OLED_Data(0x00);
		}
		return;
	}

	/* DOT */
	if(ch == '.')
	{
		uint8_t dot[5]={0x00,0x60,0x60,0x00,0x00};

		for(i=0;i<5;i++)
		OLED_Data(dot[i]);

		OLED_Data(0x00);

		return;
	}

	/* COLON */
	if(ch == ':')
	{
		uint8_t colon[5]={0x00,0x36,0x36,0x00,0x00};

		for(i=0;i<5;i++)
		OLED_Data(colon[i]);

		OLED_Data(0x00);

		return;
	}

	/* MINUS */
	if(ch == '-')
	{
		uint8_t minus[5]={0x08,0x08,0x08,0x08,0x08};

		for(i=0;i<5;i++)
		OLED_Data(minus[i]);

		OLED_Data(0x00);

		return;
	}

	/* NUMBERS */
	if(ch >= '0' && ch <= '9')
	{
		const uint8_t numbers[10][5] =
		{
			{0x3E,0x51,0x49,0x45,0x3E},
			{0x00,0x42,0x7F,0x40,0x00},
			{0x42,0x61,0x51,0x49,0x46},
			{0x21,0x41,0x45,0x4B,0x31},
			{0x18,0x14,0x12,0x7F,0x10},
			{0x27,0x45,0x45,0x45,0x39},
			{0x3C,0x4A,0x49,0x49,0x30},
			{0x01,0x71,0x09,0x05,0x03},
			{0x36,0x49,0x49,0x49,0x36},
			{0x06,0x49,0x49,0x29,0x1E}
		};

		ch = ch - '0';

		for(i=0;i<5;i++)
		{
			OLED_Data(numbers[(uint8_t)ch][i]);
		}

		OLED_Data(0x00);

		return;
	}

	/* LETTERS */

	switch(ch)
	{
		/* LOWERCASE LETTERS */

		case 'a':
		font[0]=0x20; font[1]=0x54; font[2]=0x54; font[3]=0x54; font[4]=0x78;
		break;

		case 'b':
		font[0]=0x7F; font[1]=0x48; font[2]=0x44; font[3]=0x44; font[4]=0x38;
		break;

		case 'c':
		font[0]=0x38; font[1]=0x44; font[2]=0x44; font[3]=0x44; font[4]=0x20;
		break;

		case 'd':
		font[0]=0x38; font[1]=0x44; font[2]=0x44; font[3]=0x48; font[4]=0x7F;
		break;

		case 'e':
		font[0]=0x38; font[1]=0x54; font[2]=0x54; font[3]=0x54; font[4]=0x18;
		break;

		case 'f':
		font[0]=0x08; font[1]=0x7E; font[2]=0x09; font[3]=0x01; font[4]=0x02;
		break;

		case 'g':
		font[0]=0x08; font[1]=0x14; font[2]=0x54; font[3]=0x54; font[4]=0x3C;
		break;

		case 'h':
		font[0]=0x7F; font[1]=0x08; font[2]=0x04; font[3]=0x04; font[4]=0x78;
		break;

		case 'i':
		font[0]=0x00; font[1]=0x44; font[2]=0x7D; font[3]=0x40; font[4]=0x00;
		break;

		case 'j':
		font[0]=0x20; font[1]=0x40; font[2]=0x44; font[3]=0x3D; font[4]=0x00;
		break;

		case 'k':
		font[0]=0x7F; font[1]=0x10; font[2]=0x28; font[3]=0x44; font[4]=0x00;
		break;

		case 'l':
		font[0]=0x00; font[1]=0x41; font[2]=0x7F; font[3]=0x40; font[4]=0x00;
		break;

		case 'm':
		font[0]=0x7C; font[1]=0x04; font[2]=0x18; font[3]=0x04; font[4]=0x78;
		break;

		case 'n':
		font[0]=0x7C; font[1]=0x08; font[2]=0x04; font[3]=0x04; font[4]=0x78;
		break;

		case 'o':
		font[0]=0x38; font[1]=0x44; font[2]=0x44; font[3]=0x44; font[4]=0x38;
		break;

		case 'p':
		font[0]=0x7C; font[1]=0x14; font[2]=0x14; font[3]=0x14; font[4]=0x08;
		break;

		case 'q':
		font[0]=0x08; font[1]=0x14; font[2]=0x14; font[3]=0x18; font[4]=0x7C;
		break;

		case 'r':
		font[0]=0x7C; font[1]=0x08; font[2]=0x04; font[3]=0x04; font[4]=0x08;
		break;

		case 's':
		font[0]=0x48; font[1]=0x54; font[2]=0x54; font[3]=0x54; font[4]=0x20;
		break;

		case 't':
		font[0]=0x04; font[1]=0x3F; font[2]=0x44; font[3]=0x40; font[4]=0x20;
		break;

		case 'u':
		font[0]=0x3C; font[1]=0x40; font[2]=0x40; font[3]=0x20; font[4]=0x7C;
		break;

		case 'v':
		font[0]=0x1C; font[1]=0x20; font[2]=0x40; font[3]=0x20; font[4]=0x1C;
		break;

		case 'w':
		font[0]=0x3C; font[1]=0x40; font[2]=0x30; font[3]=0x40; font[4]=0x3C;
		break;

		case 'x':
		font[0]=0x44; font[1]=0x28; font[2]=0x10; font[3]=0x28; font[4]=0x44;
		break;

		case 'y':
		font[0]=0x0C; font[1]=0x50; font[2]=0x50; font[3]=0x50; font[4]=0x3C;
		break;

		case 'z':
		font[0]=0x44; font[1]=0x64; font[2]=0x54; font[3]=0x4C; font[4]=0x44;
		break;

		/* UPPERCASE LETTERS */

		case 'A':
		font[0]=0x7E; font[1]=0x11; font[2]=0x11; font[3]=0x11; font[4]=0x7E;
		break;

		case 'B':
		font[0]=0x7F; font[1]=0x49; font[2]=0x49; font[3]=0x49; font[4]=0x36;
		break;

		case 'C':
		font[0]=0x3E; font[1]=0x41; font[2]=0x41; font[3]=0x41; font[4]=0x22;
		break;

		/* continue your existing uppercase A-Z */
		
		/* CAPITAL P */
		case 'P':
		font[0]=0x7F;
		font[1]=0x09;
		font[2]=0x09;
		font[3]=0x09;
		font[4]=0x06;
		break;

		/* CAPITAL T */
		case 'T':
		font[0]=0x01;
		font[1]=0x01;
		font[2]=0x7F;
		font[3]=0x01;
		font[4]=0x01;
		break;

		default:
		font[0]=0x00;
		font[1]=0x00;
		font[2]=0x00;
		font[3]=0x00;
		font[4]=0x00;
		break;
	}
	for(i=0;i<5;i++)
	{
		OLED_Data(font[i]);
	}

	OLED_Data(0x00);
}

void OLED_String(char *str)
{
	while(*str)
	{
		OLED_Char(*str++);
	}
}