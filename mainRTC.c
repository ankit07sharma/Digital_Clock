#include"Header.h"
RTC m1;
void main()
{

	en_int0();
	lcd_init();
	RTC_SET(0x00,0x30,0x0A,0x05,0x25,0x0B,0x21);
while(1)
{
	RTC_CONTEXT();
	}
}
		