#ifndef ALGORITHM_H 
#define ALGORITHM_H 

#include "state.h"
#include "driver.h"

typedef enum 
{
	ALGO_PREESURE_DETECTION,
}ALGO_State;

extern void(*pf_algo_state)(void);
STATE_define(ALGO_PREESURE_DETECTION);
STATE_define(ALGO_HIGH_PRESSURE_DETECTED);


#endif