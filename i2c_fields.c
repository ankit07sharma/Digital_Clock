//This function consist of all I2C fields which will be used in creating read and write frame for I2C, because we don't have a inbuilt pheripheral I2C hardware in
//8051

#include<reg51.h>
#include<intrins.h>

sbit SDA=P1^0;
sbit SCL=P1^1;

//This function will create a start condition on I2C bus
void i2c_start()
{
	SCL=1;          //idle condition  optional
  SDA=1;   	//idle condition   optional


  SCL=1;
	SDA=1;         //SDA will become high to low when SCL is high
	SDA=0;
}

//This function will create a stop condition on I2C bus
void i2c_stop()
	
{
	SCL=0;
	SDA=0;
	SCL=1;         //SDA become low to high when SCL is high
	SDA=1;
}

//This function will allow master to write one byte data to I2C bus
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

//This function will allow master to read one byte data from I2C bus
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

//This function will receive acknowledgement from slave after receving one byte
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

//This function will allow master to give no acknowledgement after master will read one byte from I2C bus

void i2c_noack()
{
	SCL=0;
	SDA=1;
	SCL=1;
}

	
