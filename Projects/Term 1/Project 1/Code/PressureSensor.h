#ifndef PRESSURE_SENSOR_H 
#define PRESSURE_SENSOR_H 

#include "state.h"
#include "driver.h"

typedef enum 
{
	PS_READING,
	PS_WAITING
}PS_State;


extern void(*pf_ps_state)(void);
void P_Sensor_init(void);
STATE_define(PS_READING);
STATE_define(PS_WAITING);






#endif
