
#include "CA.h"
#include "US.h"
#include "DC.h"
void setup()
{
	US_Sensor_init();
	DC_Motor_init();
	printf("\n");

		//Set state pointers
	US_Sensor_State = STATE(US_Sensor_busy);
	CA_State = STATE(CA_Waiting);
	DC_Motor_State = STATE(DC_Motor_idle);
}

int main(){
	setup();
	int n = 15;

	while(n--){
		US_Sensor_State();
		CA_State();
		DC_Motor_State();
	}
	return 0;
}
