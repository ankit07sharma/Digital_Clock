# Digital_Clock
In this Project i had created a Digital clock using 8051 microcontroller, RTC, Alphanumeric LCD(16x2) and I2C protocol for interfacing and establishing a 
communication between RTC and microcontroller because our RTC is I2C compatible.

For I2C as we know in 8051 we don't have any inbuilt I2C pheripheral, that's why i used Bit and Banging method a write a separate file for it's field, so 
now we can choose any two pins for I2C communication.

I also write a logic for clock setting so user can change time, date etc according to it's convenience, for this i used two switches with external interrupt 0 and
1 (P3.2 & P3.3 pins in 8051 for int0 & int1) with their combination time can we changed.
