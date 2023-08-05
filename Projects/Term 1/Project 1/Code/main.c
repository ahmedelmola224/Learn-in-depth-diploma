#include <stdint.h>
#include <stdio.h>
#include "driver.h"
#include "PressureSensor.h"
#include "Algorithm.h"
#include "Alarm.h"

int main (){
	GPIO_INITIALIZATION();
	P_Sensor_init();
	Alarm_init();
	while (1)
	{
		//Implement your Design
		pf_ps_state();
		pf_algo_state();
		pf_alarm_state(); 
	}

}
