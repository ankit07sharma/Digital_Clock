#include<reg51.h>
#include"Header.h"

sbit RS=P3^5;
sbit RW=P3^6;
sbit EN=P3^7;
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
void lcd_data(u8 a)
{
	P2=a;
	RW=0;
	RS=1;
	EN=1;
	delayms(2);
	EN=0;
}
void lcd_cmd(u8 a)
{
	P2=a;
	RW=0;
	RS=0;
	EN=1;
	delayms(2);
	EN=0;
}
	
void lcd_init()
{
	lcd_cmd(0x02);
	lcd_cmd(0x38);
	lcd_cmd(0x0E);
	lcd_cmd(0x01);
}
void lcd_string(u8 *s)
{
	while(*s!='\0')
	{
		lcd_data(*s);
		s++;
	}
}
