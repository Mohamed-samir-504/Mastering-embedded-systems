
#include "CA.h"
#include "state.h"

static int CA_distance = 0;
static int CA_speed = 0;
static int CA_threshold = 50;


void (*CA_State)();

void US_Sensor_Set_Distance(int d){

	CA_distance = d;
	(CA_distance <= CA_threshold)?(CA_State = STATE(CA_Waiting)):(CA_State = STATE(CA_Driving));

}

STATE_Define(CA_Waiting){
	CA_State_Id = CA_waiting;
	printf("CA Waiting State: distance = %d\t speed = %d\n",CA_distance ,CA_speed);

	CA_speed = 0;

	DC_Motor_Set(CA_speed);


}

STATE_Define(CA_Driving){
	CA_State_Id = CA_driving;
	printf("CA Driving State: distance = %d\t speed = %d\n",CA_distance ,CA_speed);

	CA_speed = 30;

	DC_Motor_Set(CA_speed);

}
