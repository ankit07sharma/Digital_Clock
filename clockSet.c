#include"Header.h"
#include<reg51.h>
u8 countp,t;
void en_int1();
void hr_set();
void min_set();
void sec_set();
void day_set();
void date_set();
void month_set();
void year_set();
void isr_int0()interrupt 0
{
	countp++;
	en_int1();
}
void isr_int1()interrupt 2
{
	if(countp==1)
		hr_set();
	else if(countp==2)
		min_set();
	else if(countp==3)
		sec_set();
	else if(countp==4)
		day_set();
	else if(countp==5)
		date_set();
	else if(countp==6)
		month_set();
	else if(countp==7)
		year_set();
	else
		countp=0;
}
void en_int0()
{
	IE|=(1<<7);
	IE|=(1<<0);
	IT0=1;
}
void en_int1()
{
	IE|=(1<<7);
	IE|=(1<<2);
	IT1=0;
}
void hr_set()
{
	countp=0;
	t=i2c_byte_read_frame(0xD0,0x02);
	if(t>22)
		t=0;
	else
		t++;
	i2c_byte_write_frame(0xD0,0x02,t);
}
void min_set()
{
	countp=0;
	t=i2c_byte_read_frame(0xD0,0x01);
	if(t>58)
		t=0;
	else
		t++;
	i2c_byte_write_frame(0xD0,0x01,t);
}
void sec_set()
{
	countp=0;
	t=i2c_byte_read_frame(0xD0,0x00);
	if(t>58)
		t=0;
	else
		t++;
	i2c_byte_write_frame(0xD0,0x0,t);
}
	
void day_set()
{
	countp=0;
	t=i2c_byte_read_frame(0xD0,0x03);
	if(t>6)
		t=1;
	else
		t++;
	i2c_byte_write_frame(0xD0,0x03,t);
}
void date_set()
{
	countp=0;
	t=i2c_byte_read_frame(0xD0,0x04);
	if(t>29)
		t=0;
	else
		t++;
	i2c_byte_write_frame(0xD0,0x04,t);
}
void month_set()
{
	countp=0;
	t=i2c_byte_read_frame(0xD0,0x05);
	if(t>11)
		t=1;
	else
		t++;
	i2c_byte_write_frame(0xD0,0x05,t);
}
void year_set()
{
	countp=0;
	t=i2c_byte_read_frame(0xD0,0x06);
	if(t>98)
		t=0;
	else
		t++;
	i2c_byte_write_frame(0xD0,0x06,t);
}



	



	