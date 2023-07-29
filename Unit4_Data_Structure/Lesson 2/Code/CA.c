#include "CA.h"

int CA_speed=0;
int CA_distance=0;
int CA_threshould=50;

CA_state CA_state_id;
void (*pCA_state)();//pointer to state of CA



STATE_define(CA_waiting)
{
	CA_state_id=CA_waiting;
	CA_speed=0;
	printf("CA_waiting.......distance=%d.......speed=%d\n",CA_distance,CA_speed);
	speed_set(CA_speed);
}

STATE_define(CA_driving)
{
	CA_state_id=CA_driving;
	CA_speed=30;
	printf("CA_driving.......distance=%d.......speed=%d\n",CA_distance,CA_speed);
	speed_set(CA_speed);

}
void distance_set(int d)
{
	CA_distance=d;
	(CA_distance>=CA_threshould)?(pCA_state=STATE(CA_driving)):(pCA_state=STATE(CA_waiting));

}