//This function consists of read and write I2C frame which are created using I2C fields

#include"Header.h"

//This function will allow master to write one byte to slave on a specific memory location
void i2c_byte_write_frame(u8 sa,u8 mem,u8 d)
{
	bit ret;
	i2c_start();
	i2c_write(sa);
  ret=i2c_ack();
	if(ret==1)
		goto end;
	i2c_write(mem);
	 ret=i2c_ack();
	if(ret==1)
		goto end;
	i2c_write(d);
	 ret=i2c_ack();
	if(ret==1)
		goto end;
	end: 
	i2c_stop();
}

//This function will allow master to read one byte from a specific memory location in slave
u8 i2c_byte_read_frame(u8 sa,u8 mem)
{
	bit ret;
	u8 temp;
	i2c_start();
	i2c_write(sa);
	 ret=i2c_ack();
	if(ret==1)
		goto end;
	i2c_write(mem);
	 ret=i2c_ack();
	if(ret==1)
		goto end;
	i2c_start();
	i2c_write(sa|1);                   //with read bit 
 	 ret=i2c_ack();
	if(ret==1)
		goto end;
	temp=i2c_read();
  i2c_noack();
	end:
	i2c_stop();
	return temp;
}
