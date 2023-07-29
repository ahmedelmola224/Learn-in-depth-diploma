#ifndef CA_H_
#define CA_H_
#include "STATE.h"
#include <stdio.h>
#include <stdlib.h>
typedef enum 
{
	CA_waiting,
	CA_driving
}CA_state;


STATE_define(CA_waiting);
STATE_define(CA_driving);

extern void (*pCA_state)();

#endif