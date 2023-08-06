
#ifndef US_H_
#define US_H_
#include "state.h"
enum
{
	US_busy
}US_Sensor_State_Id;


STATE_Define(US_Sensor_busy);


extern void (*US_Sensor_State)();


void US_Sensor_init();
int US_Get_Distance_Random(int min, int max, int count);

#endif /* US_H_ */
