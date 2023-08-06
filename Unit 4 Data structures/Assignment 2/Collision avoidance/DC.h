

#ifndef DC_H_
#define DC_H_

#include "state.h"

//DC Motor states
enum
{
	DC_Motor_idle,
	DC_Motor_busy
}DC_Motor_State_Id;


STATE_Define(DC_Motor_idle);
STATE_Define(DC_Motor_busy);


extern void (*DC_Motor_State)();


void DC_Motor_init();

#endif /* DC_H_ */
