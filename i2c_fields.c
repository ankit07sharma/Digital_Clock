#include<reg51.h>
#include<intrins.h>
sbit SDA=P1^0;
sbit SCL=P1^1;
void i2c_start()
{
	SCL=1;          //idle condition  optional
  SDA=1;   	//idle condition   optional


  SCL=1;
	SDA=1;         //SDA will become high to low when SCL is high
	SDA=0;
}
void i2c_stop()
	
{
	SCL=0;
	SDA=0;
	SCL=1;         //SDA become low to high when SCL is high
	SDA=1;
}
void i2c_write(unsigned char d)
{
char i;
	for(i=7;i>=0;i--)
	{
		SCL=0;
		SDA=(d>>i)&1;
		SCL=1;
	}
}
unsigned char i2c_read()
{
	char i;
	unsigned char temp=0;
	for(i=7;i>=0;i--)
	{
		SCL=1;
		if(SDA==1)
			temp|=(1<<i);
		SCL=0;
	}
	return temp;
}
bit i2c_ack()
{
	SCL=0;
	SDA=1;	//compalsary
	SCL=1;
	_nop_();     //delay 1 microsecond
	_nop_();
	_nop_();
	_nop_();
	if(SDA==0)
	{
		SCL=0;
	return 0;
	}
	else{
		SCL=0;
		return 1;
	}
	
}
void i2c_noack()
{
	SCL=0;
	SDA=1;
	SCL=1;
}
//bit i2c_ack1()
//{ SDA=0;
//  SCL=0;
//	_nop_();     //delay 1 microsecond
//	_nop_();
//	_nop_();
//	_nop_();
//    	//compalsary
//	SCL=1;

//	if(SDA==0)
//	{
//		SCL=0;
//	return 0;
//	}
//	else{
//		SCL=0;
//		return 1;
//	}
//}
//	

	