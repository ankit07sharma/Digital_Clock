typedef unsigned char u8;
typedef  char s8;
typedef unsigned int  u16;
typedef  int  s16;

typedef struct rtc
{
	u8 sec,min, hr,day,date,month,year;
}RTC;

extern void delayms(u16);


extern void lcd_string(u8 *);
extern void lcd_data(u8 );
extern void lcd_cmd(u8);
extern void lcd_init();

extern void i2c_start();
extern void i2c_stop();
extern void i2c_write(u8);
extern unsigned char i2c_read();
extern bit i2c_ack();
extern u8 i2c_byte_read_frame(u8,u8);
extern void i2c_byte_write_frame(u8,u8,u8);
extern void i2c_noack();
extern void en_int0();




void RTC_SET(u8,u8,u8,u8,u8,u8,u8);
void RTC_CONTEXT();