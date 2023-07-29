#ifndef DC_MOTOR_H
#define DC_MOTOR_H
#include "STATE.h"
#include <stdio.h>
#include <stdlib.h>
typedef enum 
{
	DC_idle,
	DC_busy
}DC_MOTOR_state;

void DC_MOTOR_init();
STATE_define(DC_idle);
STATE_define(DC_busy);
extern void (*pDC_MOTOR_state)();

#endif