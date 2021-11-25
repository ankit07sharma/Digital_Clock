#include"Header.h"
extern RTC m1;                           //We will use this structure varaible for reading RTC data


//This function will initialize the digital clock at once only after it's creation
void RTC_SET(u8 sec,u8 min,u8 hr,u8 day,u8 date,u8 month,u8 year)
{
	i2c_byte_write_frame(0xD0,0x0,sec);   //sec
	i2c_byte_write_frame(0xD0,0x1,min);   //min
	i2c_byte_write_frame(0xD0,0x2,hr);   //hr
	i2c_byte_write_frame(0xD0,0x3,day);   //day
	i2c_byte_write_frame(0xD0,0x4,date);   //date
	i2c_byte_write_frame(0xD0,0x5,month);   //month
	i2c_byte_write_frame(0xD0,0x6,year);   //year
}


//This function will print the RTC context like hour,minute etc on the LCD
void RTC_CONTEXT()
{
	lcd_cmd(0x89);
	lcd_string("Day-");
	m1.day=i2c_byte_read_frame(0xD0,0x03);
	switch(m1.day)
	{
		case 1:lcd_string("Sun");break;
		case 2:lcd_string("Mon");break;
		case 3:lcd_string("Tus");break;
		case 4:lcd_string("Wed");break;
		case 5:lcd_string("Thu");break;
		case 6:lcd_string("Fri");break;
		case 7:lcd_string("Sat");break;
	}
  lcd_cmd(0xc0);
	lcd_string("Date-");
	m1.date=i2c_byte_read_frame(0xD0,0x4);   //date
	m1.month=i2c_byte_read_frame(0xD0,0x5);   //month
	m1.year=i2c_byte_read_frame(0xD0,0x6);   //year
	lcd_data((m1.date/16)+48);
	lcd_data((m1.date%16)+48);
	lcd_data('/');
	lcd_data((m1.month/10)+48);
	lcd_data((m1.month%10)+48);
	lcd_data('/');
	lcd_data((m1.year/16)+48);
	lcd_data((m1.year%16)+48);
	
		lcd_cmd(0x80);
		m1.hr=i2c_byte_read_frame(0xD0,0x2);
		lcd_data((m1.hr/10)+48);
		lcd_data((m1.hr%10)+48);
		lcd_data(':');
		m1.min=i2c_byte_read_frame(0xD0,0x1);
		lcd_data(m1.min/16+48);
		lcd_data((m1.min%16)+48);
		lcd_data(':');
		m1.sec=i2c_byte_read_frame(0xD0,0x0);
		lcd_data((m1.sec/16)+48);
		lcd_data((m1.sec%16)+48);
}
