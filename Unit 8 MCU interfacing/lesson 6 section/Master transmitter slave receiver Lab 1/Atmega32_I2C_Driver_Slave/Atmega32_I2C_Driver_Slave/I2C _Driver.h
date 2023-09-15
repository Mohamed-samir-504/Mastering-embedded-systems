


#ifndef I2C _DRIVER_H_
#define I2C _DRIVER_H_


#include <avr/io.h>
#define F_CPU 8000000

void I2C_Set_Address(unsigned char addr);
unsigned char I2C_Read(unsigned char ack);



#endif /* I2C _DRIVER_H_ */