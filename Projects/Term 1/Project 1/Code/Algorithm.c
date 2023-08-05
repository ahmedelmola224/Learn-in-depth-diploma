#include "Algorithm.h"

 
static int pVal=0;
static int pThreshould=20;
static ALGO_State algo_status_id;
 void(*pf_algo_state)(void)=STATE(ALGO_PREESURE_DETECTION);


 STATE_define(ALGO_PREESURE_DETECTION)
 {
    algo_status_id=ALGO_PREESURE_DETECTION;
    pVal>=pThreshould?set_alarm_state(1):set_alarm_state(0);
    pf_algo_state=STATE(ALGO_PREESURE_DETECTION);
 }



 void set_pressure(int val)
 {
    pVal=val;
 }