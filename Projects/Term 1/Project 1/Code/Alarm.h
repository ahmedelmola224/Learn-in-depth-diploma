#ifndef ALARM_H
#define ALARM_H

#include "state.h"
#include "driver.h"

typedef enum 
{
	ALARM_WAITING,
	ALARM_ON,
	ALARM_OFF
}ALARM_State;

extern void(*pf_alarm_state)(void);
void Alarm_init(void);
STATE_define(ALARM_WAITING);
STATE_define(ALARM_ON);
STATE_define(ALARM_OFF);


#endif