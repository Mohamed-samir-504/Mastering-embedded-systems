
#ifndef INC_STM32F103C6_I2C_DRIVER_H_
#define INC_STM32F103C6_I2C_DRIVER_H_

#include "STM32F103x6.h"
#include "STM32F103C6_GPIO_driver.h"
#include "STM32F103C6_RCC_driver.h"


struct S_I2C_SLAVE_DEVICE_ADDRESS{

	uint16_t	Enable_Dual_Add;
	uint16_t	Primary_Slave_Add;
	uint16_t	Secondary_Slave_Add;
	uint32_t	Addressing_Slave_Mode; 	//@ref I2C_ADD_SLAVE_MODE

};

typedef enum
{
	WITH_STOP,
	WITHOUT_STOP
}Stop_Condition;


typedef enum
{
	START,
	REPEATEDSTART
}Repeated_Start;

typedef enum{
	I2C_EV_STOP,
	I2C_ERROR_AF,
	I2C_EV_ADDR_MATCHED,
	I2C_EV_DATA_REQ,    //the app layer should send the data (I2C_SlaveSendData) in this state
	I2C_EV_DATA_REC     //the app layer should read the data (I2C_SlaveReceiveData) in this state
}SLAVE_STATE;

typedef enum{
	Disable = 0,
	Enable = 1
}FunctionalState;


typedef enum
{
	I2C_BUSY,
	EV5,
	EV6,
	MASTER_BYTE_TRANSMITTING = (uint32_t)(0x00070080),    // TRA, BUSY, MSL and TXE flags
	EV8,
	EV8_2,
	EV7
}Status;


typedef enum{
	RESET,
	SET
}Flag_Status;

typedef enum{
	Transmit = 0,
	Receive = 1
}I2C_Direction;

typedef struct{

	uint32_t                            Clock_Speed;      //  @ref I2C_CLOCK_SPEED

	uint32_t	                        Stretch_Mode;     // @ref I2C_STRETCH_MODE

	uint32_t	                        I2C_Mode;         //@ref I2C_MODE

	struct S_I2C_SLAVE_DEVICE_ADDRESS   Slave_Address;

	uint32_t                            ACK_Control;   //@ref I2C_ACK_CONTROL

	void(*P_IRQ_Callback)(SLAVE_STATE state);

}I2C_config;





//=================================================================================
//Macros Configuration References
//=================================================================================


//@ref I2C_CLOCK_SPEED

#define	I2C_CLCK_SM_50K		    50000U
#define	I2C_CLCK_SM_100K	    100000U
#define	I2C_CLCK_FM_200K	    200000U
#define	I2C_CLCK_FM_400K	    400000U


// @ref I2C_STRETCH_MODE
#define	I2C_STRECH_ENABLE		(uint32_t)(0)
#define	I2C_STRECH_DISABLE		I2C_CR1_NOSTRETCH   //(1<<7)


//@ref I2C_MODE
#define	I2C_MODE_I2C		    (uint32_t)(0)
#define	I2C_MODE_SMBUS		    I2C_CR1_SMBUS


//@ref I2C_ADD_SLAVE_MODE
#define	I2C_7BIT_ADD_SLAVE_MODE			(uint32_t)(0)
#define	I2C_10BIT_ADD_SLAVE_MODE		(uint16_t)(1<<15)


//@ref I2C_ACK_CONTROL
#define	I2C_ACK_ENABLE		I2C_CR1_ACK
#define	I2C_ACK_DISABLE		(uint32_t)(0)



//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
// APIS Supported by "MCAL I2C DRIVER"
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-

void MCAL_I2C_Init(I2C_TypeDef *I2Cx ,I2C_config *I2C_cfg );
void MCAL_I2C_DeInit(I2C_TypeDef *I2Cx );
void MCAL_I2C_GPIO_Set_Pins(I2C_TypeDef *I2Cx );

//Master polling mechanism
void MCAL_I2C_MASTER_TX(I2C_TypeDef *I2Cx , uint16_t ADDRESS , uint8_t* PTXBUFFER , uint32_t DATALEN , Stop_Condition STOP , Repeated_Start START);
void MCAL_I2C_MASTER_RX(I2C_TypeDef *I2Cx , uint16_t ADDRESS , uint8_t* PRXBUFFER , uint32_t DATALEN , Stop_Condition STOP , Repeated_Start START);

//Slave interrupt mechanism
//void MCAL_I2C_SLAVE_TX(I2C_TypeDef *I2Cx ,uint8_t DATA);
//uint8_t MCAL_I2C_SLAVE_RX(I2C_TypeDef *I2Cx );


//Generic
void I2C_GENERATE_START(I2C_TypeDef* I2Cx , FunctionalState Newstate, Repeated_Start START);
void I2C_GENERATE_STOP(I2C_TypeDef* I2Cx, FunctionalState NewState);
Flag_Status I2C_GET_FLAG_STATUS( I2C_TypeDef *I2Cx , Status FLAG );
void I2C_SEND_ADDRESS(I2C_TypeDef* I2Cx, uint16_t ADDRESS , I2C_Direction DIRECTION);

#endif /* INC_STM32F103C6_I2C_DRIVER_H_ */
