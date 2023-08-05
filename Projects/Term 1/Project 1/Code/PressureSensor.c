#include "PressureSensor.h"

 
static int pVal=0;
static PS_State ps_status_id;
 void(*pf_ps_state)(void)=P_Sensor_init;

void P_Sensor_init(void)
{
	pVal=0;
	pf_ps_state=STATE(PS_READING);

}

STATE_define(PS_READING)
{
	ps_status_id=PS_READING;
	pVal=getPressureVal();
	pf_ps_state=STATE(PS_WAITING);
	set_pressure(pVal);
	//to avoid getting the same value twice
	pf_ps_state();
}

STATE_define(PS_WAITING)
{
	ps_status_id=PS_WAITING;
	Delay(1000);
	pf_ps_state=STATE(PS_READING);

}

