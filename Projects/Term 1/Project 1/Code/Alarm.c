#include "Alarm.h"


void(*pf_alarm_state)(void);
ALARM_State alarm_state_id;
static int alarm_state=0;
void Alarm_init(void)
{
	pf_alarm_state=STATE(ALARM_WAITING);
	alarm_state=0;
	//hw initializations

}
STATE_define(ALARM_WAITING)
{
	alarm_state_id=ALARM_WAITING;
	alarm_state==0?(pf_alarm_state=STATE(ALARM_OFF)):(pf_alarm_state=STATE(ALARM_ON));
	pf_alarm_state();
}

STATE_define(ALARM_ON)
{
	alarm_state_id=ALARM_ON;
	Set_Alarm_actuator(0);
	Delay(60*1000);
	pf_alarm_state=STATE(ALARM_WAITING);
}
STATE_define(ALARM_OFF)
{
	alarm_state_id=ALARM_OFF;
	Set_Alarm_actuator(1);
	pf_alarm_state=STATE(ALARM_WAITING);
}

void set_alarm_state(int val)
{
	alarm_state=val;
}