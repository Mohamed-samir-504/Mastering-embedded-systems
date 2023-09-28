#include "STM32F103C6_I2C_driver.h"
#include "STM32F103C6_GPIO_driver.h"

/*
 * =====================================================================================
 * 							Generic Variables
 * =====================================================================================
 */

I2C_config Global_I2C_Config[2] = {NULL,NULL};


/*
 * =====================================================================================
 * 							Generic Macros
 * =====================================================================================
 */

#define I2C1_INDEX    0
#define I2C2_INDEX    1

void MCAL_I2C_Init(I2C_TypeDef *I2Cx ,I2C_config *I2C_cfg ){
	uint16_t temp_reg=0, freq_range=0, result = 0;
	uint32_t PCLK1 = 8000000;

	if(I2Cx == I2C1){
		Global_I2C_Config[I2C1_INDEX] = *I2C_cfg;
		RCC_I2C1_CLK_EN();
	}
	else{
		Global_I2C_Config[I2C2_INDEX] = *I2C_cfg;
		RCC_I2C2_CLK_EN();
	}

	if(I2C_cfg->I2C_Mode == I2C_MODE_I2C){

		//-------------------------------------Timing init----------------------------------------------------------

		//in CR2 register, FREQ[5:0] bits -> peripheral clock frequency
		temp_reg = I2Cx->CR2;

		//clear FREQ[5:0] bits
		temp_reg &= ~(I2C_CR2_FREQ_MASK);

		//get pclk1 freq
		PCLK1 = MCAL_RCC_GetPCLK1Freq();

		//set FREQ[5:0] bits depending on pclk1 value
		freq_range = (uint16_t)(PCLK1/1000000);
		temp_reg |= freq_range;
		I2Cx->CR2 = temp_reg;

		//======================configure clock control register (CCR)=================================

		//disable selected I2C peripheral to configure time
		I2Cx->CR2 &= ~(I2C_CR1_PE);

		temp_reg = 0;

		//configure speed in standard mode
		if(I2C_cfg->Clock_Speed == I2C_CLCK_SM_50K || I2C_cfg->Clock_Speed == I2C_CLCK_SM_100K){

			//to understand this equation refer to lecture 7 in unit 8
			result = (uint16_t)(PCLK1 / (2 * I2C_cfg->Clock_Speed));
			temp_reg |= result;
			I2Cx->CCR = temp_reg;

			//Configure TRISE
			I2Cx->TRISE = freq_range + 1;  //to understand this equation refer to lecture 7 in unit 8



		}
		else{
			//fast mode not supported
		}

		//======================configure CR1 register=================================
		temp_reg = I2Cx->CR1;
		temp_reg |= (uint16_t)(I2C_cfg->ACK_Control | I2C_cfg->I2C_Mode | I2C_cfg->Stretch_Mode);
		I2Cx->CR1 = temp_reg;


		//======================configure OAR1 and OAR2 register=================================
		temp_reg = 0;
		if(I2C_cfg->Slave_Address.Enable_Dual_Add == 1){
			temp_reg = I2C_OAR2_ENDUAL;
			temp_reg |= I2C_cfg->Slave_Address.Secondary_Slave_Add << I2C_OAR2_ADD2_POS;
			I2Cx->OAR2 = temp_reg;
		}

		temp_reg = 0;
		temp_reg |= I2C_cfg->Slave_Address.Primary_Slave_Add << 1;
		temp_reg |= I2C_cfg->Slave_Address.Addressing_Slave_Mode;
		I2Cx->OAR1 = temp_reg;


	}


	else{
		//SMBUS not supported
	}

	//Interrupt enable for slave
	if(I2C_cfg->P_IRQ_Callback != NULL){
		I2Cx->CR2 |= (I2C_CR2_ITERREN);
		I2Cx->CR2 |= (I2C_CR2_ITEVTEN);
		I2Cx->CR2 |= (I2C_CR2_ITBUFEN);

		if(I2Cx==I2C1){
			NVIC_IRQ31_I2C1_EV_enable();
			NVIC_IRQ32_I2C1_ER_enable();
		}
		else{
			NVIC_IRQ33_I2C2_EV_enable();
			NVIC_IRQ34_I2C2_ER_enable();
		}

		I2Cx->SR1=0;
		I2Cx->SR2=0;
	}

	//enable I2C peripheral
	I2Cx->CR1 |= I2C_CR1_PE;

}
void MCAL_I2C_DeInit(I2C_TypeDef *I2Cx ){

	if(I2Cx==I2C1){
		NVIC_IRQ31_I2C1_EV_disable();
		NVIC_IRQ32_I2C1_ER_disable();
		RCC_I2C1_CLK_RESET();
	}
	else{
		NVIC_IRQ33_I2C2_EV_disable();
		NVIC_IRQ34_I2C2_ER_disable();
		RCC_I2C2_CLK_RESET();
	}
}

void MCAL_I2C_GPIO_Set_Pins(I2C_TypeDef *I2Cx ){

	GPIO_PinConfig_t PINCONFIG;
	if(I2Cx == I2C1)
	{
		// PB6 :SCL
		// PB7 :SDA
		PINCONFIG.GPIO_PinNumber =GPIO_PIN6;
		PINCONFIG.GPIO_MODE = GPIO_MODE_OUTPUT_AF_OD;
		PINCONFIG.GPIO_Output_Speed=GPIO_SPEED_10M ;
		MCAL_GPIO_Init(GPIOB, &PINCONFIG);

		PINCONFIG.GPIO_PinNumber =GPIO_PIN7;
		PINCONFIG.GPIO_MODE = GPIO_MODE_OUTPUT_AF_OD;
		PINCONFIG.GPIO_Output_Speed= GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOB, &PINCONFIG);
	}

	else
	{
		// PB10 :SCL
		// PB11 :SDA
		PINCONFIG.GPIO_PinNumber =GPIO_PIN10;
		PINCONFIG.GPIO_MODE = GPIO_MODE_OUTPUT_AF_OD;
		PINCONFIG.GPIO_Output_Speed= GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOB, &PINCONFIG);

		PINCONFIG.GPIO_PinNumber =GPIO_PIN11;
		PINCONFIG.GPIO_MODE = GPIO_MODE_OUTPUT_AF_OD;
		PINCONFIG.GPIO_Output_Speed= GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOB, &PINCONFIG);
	}
}



void MCAL_I2C_MASTER_TX(I2C_TypeDef *I2Cx , uint16_t ADDRESS , uint8_t* PTXBUFFER , uint32_t DATALEN , Stop_Condition STOP , Repeated_Start START){

	int i;

	//1. set the START bit in CR1 register to generate a start condition
	I2C_GENERATE_START(I2Cx,Enable,START);

	//2. wait for EV5
	//EV5: SB=1, cleared by reading SR1 register followed by writing DR register with Address.
	while(!I2C_GET_FLAG_STATUS(I2Cx,EV5));

	//3. send address
	I2C_SEND_ADDRESS(I2Cx,ADDRESS,Transmit);


	//4. wait for EV6
	//EV6: ADDR=1, cleared by reading SR1 register followed by reading SR2.
	while(!I2C_GET_FLAG_STATUS(I2Cx,EV6));

	//5. check for TRA, BUSY, MSL and TXE flags
	while(!I2C_GET_FLAG_STATUS(I2Cx,MASTER_BYTE_TRANSMITTING));


	//6. send data
	for(i=0; i<DATALEN; i++){

		I2Cx->DR = PTXBUFFER[i];

		//wait for EV8
		//EV8: TxE=1, shift register not empty, d. ata register empty, cleared by writing DR register
		while(!I2C_GET_FLAG_STATUS(I2Cx,EV8));

	}

	//7. wait for EV8_2
	//EV8_2: TxE=1, BTF = 1, Program Stop request. TxE and BTF are cleared by hardware by the Stop condition
	//while(!I2C_GET_FLAG_STATUS(I2Cx,EV8_2));


	//8. send stop condition
	if(STOP == WITH_STOP){
		I2C_GENERATE_STOP(I2Cx,Enable);
	}
}

void MCAL_I2C_MASTER_RX(I2C_TypeDef *I2Cx , uint16_t ADDRESS , uint8_t* PRXBUFFER , uint32_t DATALEN , Stop_Condition STOP , Repeated_Start START){

	int i;
	uint8_t index = (I2Cx == I2C1)?I2C1_INDEX:I2C2_INDEX;

	//1. set the START bit in CR1 register to generate a start condition
	I2C_GENERATE_START(I2Cx,Enable,START);

	//2. wait for EV5
	//EV5: SB=1, cleared by reading SR1 register followed by writing DR register with Address.
	while(!I2C_GET_FLAG_STATUS(I2Cx,EV5));

	//3. send address
	I2C_SEND_ADDRESS(I2Cx,ADDRESS,Receive);


	//4. wait for EV6
	//EV6: ADDR=1, cleared by reading SR1 register followed by reading SR2.
	while(!I2C_GET_FLAG_STATUS(I2Cx,EV6));

	I2Cx->CR1 |=(I2C_CR1_ACK);

	for( i=0; i<DATALEN; i++ )
	{
		//wait for EV7
		//EV7: RXNE = 1, clear by reading DR register
		while(!(I2C_GET_FLAG_STATUS(I2Cx, EV7)));

		PRXBUFFER[i]= I2Cx->DR;
	}


	I2Cx->CR1 &= ~(I2C_CR1_ACK);

	if( STOP == WITH_STOP )
	{
		I2C_GENERATE_STOP(I2Cx,Enable) ;
	}


	if(Global_I2C_Config[index].ACK_Control == I2C_ACK_ENABLE){
		//Re enable ACK
		I2Cx->CR1 |=(I2C_CR1_ACK);
	}

}

void I2C_GENERATE_START(I2C_TypeDef* I2Cx , FunctionalState NewState, Repeated_Start START){

	if(START != REPEATEDSTART){
		while( I2C_GET_FLAG_STATUS(I2Cx, I2C_BUSY));
	}

	if(NewState == Enable){
		I2Cx->CR1 |=I2C_CR1_START;
	}
	else{
		I2Cx->CR1 &= ~(I2C_CR1_START);
	}

}


Flag_Status I2C_GET_FLAG_STATUS( I2C_TypeDef *I2Cx , Status FLAG ){

	Flag_Status F_state ;
	volatile uint32_t dummyread;
	uint32_t flag1 = 0, flag2 = 0, lastevent;

	switch( FLAG )
	{
	case I2C_BUSY :
		if (I2Cx->SR2 & I2C_SR2_BUSY)
			F_state=SET ;
		else
			F_state=RESET ;
		break;

	case EV5 :
		if (I2Cx->SR1 & I2C_SR1_SB)
			F_state=SET ;
		else
			F_state=RESET ;
		break;

	case EV6 :
		if (I2Cx->SR1 & I2C_SR1_ADDR)
			F_state=SET ;
		else
			F_state=RESET ;


		break;

	case MASTER_BYTE_TRANSMITTING :
		flag1 = I2Cx->SR1;
		flag2 = I2Cx->SR2;
		flag2 = flag2 << 16;

		lastevent = (flag1 | flag2) & ((uint32_t)0x00FFFFFF);

		if((lastevent & FLAG) == FLAG){
			F_state = SET;
		}
		else{
			F_state = RESET;
		}
		break;

	case EV8 :
		if (I2Cx->SR1 & I2C_SR1_TXE)
			F_state=SET ;
		else
			F_state=RESET ;
		break;
	case EV8_2 :
		if (I2Cx->SR1 & I2C_SR1_BTF)
			F_state=SET ;
		else
			F_state=RESET ;
		break;

	case EV7 :
		if (I2Cx->SR1 & I2C_SR1_RXNE)
			F_state=SET ;
		else
			F_state=RESET ;
		break;

	}
	return F_state ;


}


void I2C_SEND_ADDRESS(I2C_TypeDef* I2Cx, uint16_t ADDRESS , I2C_Direction DIRECTION){

	ADDRESS = ADDRESS << 1;

	if(DIRECTION != Transmit){
		//set bit 0 to read
		ADDRESS |= 1<<0;
	}
	else{
		ADDRESS &= ~(1<<0);
	}

	I2Cx->DR = ADDRESS;
}

void I2C_GENERATE_STOP(I2C_TypeDef* I2Cx ,FunctionalState NewState){

	if(NewState == Enable){
		I2Cx->CR1 |= I2C_CR1_STOP;
	}
	else{
		I2Cx->CR1 &= ~(I2C_CR1_STOP);
	}
}



//void MCAL_I2C_SLAVE_TX(I2C_TypeDef *I2Cx ,uint8_t DATA)
//{
//	I2Cx->DR = DATA;
//}



//uint8_t MCAL_I2C_SLAVE_RX(I2C_TypeDef *I2Cx )
//{
//	return (uint8_t)I2Cx->DR;
//
//}


//void I2C1_EV_IRQHandler()
//{
//	volatile uint32_t READ = 0;
//
//	uint32_t TEMP_1, TEMP_2, TEMP_3;
//
//	TEMP_3 = (I2C1->SR1 & (I2C_SR1_STOPF));		// STOP DETECTION(SLAVE MODE)
//	TEMP_1 = (I2C1->CR2 & (I2C_CR2_ITEVTEN));	// EVENT INTERRUPT ENABLE
//	TEMP_2 = (I2C1->CR2 & (I2C_CR2_ITBUFEN));	// BUFFER INTERRUPT ENABLE
//
//
//
//	//CHECK STOP DETECTION
//
//	if(TEMP_1 && TEMP_3)
//	{
//		//CLEARD BY SOFTWARE READING THE SR1 REGISTER FOLLOWED BY A WRITE IN THE CR1 REGISTER, OR BY HARDWARE @ PE=0
//
//		I2C1->CR1 |= 0x0000;
//		SLAVE_STATUS(I2C1 , I2C_EV_STOP);
//	}
//
//
//	// CHECK ADDRESS MATCHED
//
//	TEMP_3 = (I2C1->SR1 & (I2C_SR1_ADDR));
//	if(TEMP_1 && TEMP_3)
//	{
//
//		// CHECK MASTER OR SLAVE MODE
//
//		if(I2C1->SR2 & (I2C_SR2_MSL))
//		{
//			// MASTER MODE
//		}
//		else
//		{
//			// SLAVE MODE
//			READ  = I2C1->SR1 ;
//			READ  = I2C1->SR2 ;
//			SLAVE_STATUS(I2C1 , I2C_EV_ADDR_MATCHED) ;
//		}
//	}
//
//
//	// DATA REGISTER EMPTY AT SLAVE TX
//
//
//	TEMP_3 = (I2C1->SR1 & (I2C_SR1_TXE));
//	if(TEMP_1 && TEMP_2 && TEMP_3)
//	{
//		//CLEARED BY SW WRITING TO THE DR REGISTER OR BY HW AFTER A START OR A STOP CONDITION WHEN PE=0
//		// CHECK MASTER OR SLAVE MODE
//
//		if(I2C1->SR2 & (I2C_SR2_MSL))
//		{
//			// MASTER MODE
//		}
//		else
//		{
//			// SLAVE MODE
//			SLAVE_STATUS(I2C1 , I2C_EV_DATA_REQ);
//		}
//	}
//	// DATS REGISTER NOT EMPTY AT SLAVE RECIEVE
//	TEMP_3 = (I2C1->SR1 & (I2C_SR1_RXNE));
//	if(TEMP_1 && TEMP_2 && TEMP_3)
//	{
//		// CHECK MASTER MODE OR SLAVE MODE
//		if(I2C1->SR2 & (I2C_SR2_MSL))
//		{
//			// Master mode
//		}
//		else
//		{
//			// SLAVE MODE
//			SLAVE_STATUS(I2C1 , I2C_DATA_REC);
//		}
//	}
//}

//void I2C1_ER_IRQHandler(void){}
//void I2C2_EV_IRQHandler(void){}
//void I2C2_ER_IRQHandler(void){}


//void SLAVE_STATUS(I2C_TypeDef* I2Cx , SLAVE_STATE STATE)
//{
//	uint8_t INDEX =  I2Cx == I2C1 ? 0 : 1 ;
//
//	switch(STATE)
//	{
//	case I2C_EV_STOP :
//		if(I2Cx->SR2 & (I2C_SR2_TRA))
//		{
//			//STOP CONDITION IS DETECTED ON THE BUS BY THE SLAVE AFTER AN ACK
//			Global_I2C_Config[INDEX].P_IRQ_CALL(I2C_EV_STOP);
//		}
//		break;
//	case I2C_EV_ADDR_MATCHED :
//		//ADDRESS NATCHED WITH THE OAR REGISTER CONTENT , GENERAL CALL
//		Global_I2C_Config[INDEX].P_IRQ_CALL(I2C_EV_ADDR_MATCHED);
//		break;
//	case I2C_EV_DATA_REQ :
//		if(I2Cx->SR2 & (I2C_SR2_TRA))
//		{
//			// THE APP LAYER SHOULD SEND THE DATA
//			Global_I2C_Config[INDEX].P_IRQ_CALL(I2C_EV_DATA_REQ);
//		}
//		break;
//	case I2C_EV_DATA_REC :
//		// TO CONFIRM THE SLAVE IN RECIEVER
//		if(!(I2Cx->SR2 & (I2C_SR2_TRA)))
//		{
//			// APPLICATION SHOULD READ DATA
//			Global_I2C_Config[INDEX].P_IRQ_CALL(I2C_EV_DATA_REC);
//		}
//		break;
//	}
