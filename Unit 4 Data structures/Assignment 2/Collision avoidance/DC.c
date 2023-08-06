
#include "DC.h"
static int DC_speed = 0;


void (*DC_Motor_State)();


void DC_Motor_init()
{

	printf("DC Motor init.\n");
}


void DC_Motor_Set(int speed)
{
	DC_speed = speed;
	printf("CA ---------------- speed = %d ---------------> DC Motor\n",DC_speed);

	DC_Motor_State = STATE(DC_Motor_busy);
}


STATE_Define(DC_Motor_idle)
{

	DC_Motor_State_Id = DC_Motor_idle;

	printf("DC Motor Idle State: speed = %d\n",DC_speed);

}

STATE_Define(DC_Motor_busy)
{

	DC_Motor_State_Id = DC_Motor_busy;

	printf("DC Motor Busy State: speed = %d\n",DC_speed);

	DC_Motor_State = STATE(DC_Motor_idle);

}
