

#ifndef STATE_H_
#define STATE_H_

#include "stdio.h"
#include "stdlib.h"


#define STATE_Define(_StateFun_)	void ST_##_StateFun_()
#define STATE(_StateFun_)			ST_##_StateFun_


//states connection
void US_Sensor_Set_Distance(int d);
void DC_Motor_Set(int s);

#endif /* STATE_H_ */
