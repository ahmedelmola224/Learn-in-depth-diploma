#ifndef US_H
#define US_H

#include "STATE.h"
#include <stdio.h>
#include <stdlib.h>
typedef enum 
{
	US_busy
	
}US_state;

void US_init();
STATE_define(US_busy);

extern void (*pUS_state)();



#endif