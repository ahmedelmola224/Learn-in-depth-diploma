#ifndef _STATE_H
#define _STATE_H

#define STATE_define(_stateFunc_)  void ST_##_stateFunc_()
#define STATE(_stateFunc_) ST_##_stateFunc_

void speed_set(int s);
void distance_set(int d);


#endif