
#ifndef CA_H_
#define CA_H_

#include "state.h"


enum
{
	CA_waiting,
	CA_driving
}CA_State_Id;


STATE_Define(CA_Waiting);
STATE_Define(CA_Driving);


extern void (*CA_State)();

#endif /* CA_H_ */
