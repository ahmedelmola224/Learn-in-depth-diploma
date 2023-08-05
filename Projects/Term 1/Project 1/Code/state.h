#ifndef _STATE_H
#define _STATE_H

#define STATE_define(_stateFunc_)  void ST_##_stateFunc_()
#define STATE(_stateFunc_) ST_##_stateFunc_

void set_pressure(int val);
//1->high    0->low
 void set_alarm_state(int val);

#endif