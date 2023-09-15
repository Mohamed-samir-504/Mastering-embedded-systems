


#ifndef I2C _DRIVER_H_
#define I2C _DRIVER_H_


#include <avr/io.h>
#define F_CPU 8000000

void I2C_Init(unsigned long SCL_Clock);
void I2C_Start(void);
void I2C_Write(unsigned char cByte);
void I2C_Stop();



#endif /* I2C _DRIVER_H_ */