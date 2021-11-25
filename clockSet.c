#include"Header.h"
#include<reg51.h>
u8 countp,t;
void en_int1();                           //Prototype for enable external interput 1 function  
void hr_set();                            //prototype for hr_set function
void min_set();                           //prototype for min_set function
void sec_set();                           //prototype for sec_set function
void day_set();                           //prototype for day_set function
void date_set();                          //prototype for date_set function
void month_set();                         //prototype for month_set function
void year_set();                          //prototype for year_set function


//This subotine will enable the ext. interrupt 1 and increments the countp
void isr_int0()interrupt 0
{
	countp++;
	en_int1();
}

//This subrotine will call the function according to countp value
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

//This function will enables the external interrupt 0
void en_int0()
{
	IE|=(1<<7);
	IE|=(1<<0);
	IT0=1;
}

//This function will enables the external interrupt 1
void en_int1()
{
	IE|=(1<<7);
	IE|=(1<<2);
	IT1=0;
}
//This function will increments the hour by one
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

//This function will increments the min by one
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

//This function will increments the second by one
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
	
//This function will change the day with next day 
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

//This function will increments the date by one
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

//This function will increments the month by one
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

//This function will increments the year by one
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



	



	
