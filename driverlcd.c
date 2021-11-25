// This file consist of LCD 8-bit mode functions and a delayms function


#include<reg51.h>
#include"Header.h"

sbit RS=P3^5;
sbit RW=P3^6;
sbit EN=P3^7;

//This function will create software delay in milisecond
void delayms(u16 a)
{
	u8 i;
	for(;a>0;a--)
	{
		i=250;
		while(i--);
		i=247;
		while(i--);
	}

}

//This fuction will transmit one byte data to lcd
void lcd_data(u8 a)
{
	P2=a;
	RW=0;
	RS=1;
	EN=1;
	delayms(2);
	EN=0;
}

//This fuction will transmit one byte command to lcd
void lcd_cmd(u8 a)
{
	P2=a;
	RW=0;
	RS=0;
	EN=1;
	delayms(2);
	EN=0;
}

//This function will seetups the LCD for use
void lcd_init()
{
	lcd_cmd(0x02);
	lcd_cmd(0x38);
	lcd_cmd(0x0E);
	lcd_cmd(0x01);
}

//This function will transmit string to LCD
void lcd_string(u8 *s)
{
	while(*s!='\0')
	{
		lcd_data(*s);
		s++;
	}
}
