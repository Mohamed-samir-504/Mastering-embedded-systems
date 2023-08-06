
#include "US.h"

int US_distance = 0;
void (*US_Sensor_State)();

void US_Sensor_init()
{
	//initialize US Sensor Driver
	printf("US Sensor init.\n");
}


STATE_Define(US_Sensor_busy){
	US_Sensor_State_Id = US_busy;

	US_distance = US_Get_Distance_Random(45,55,1);

	printf("US Sensor Busy State: distance = %d\n",US_distance);

	US_Sensor_Set_Distance(US_distance);

	US_Sensor_State = STATE(US_Sensor_busy);

}


int US_Get_Distance_Random(int min, int max, int count)
{
	int i, x;

	for(i = 0; i < count; i++)
	{
		x = (rand() % (max - min + 1)) + min;
	}

	return x;
}
