#include "US.h"


US_state US_state_id;
void (*pUS_state)();//pointer to state of us

int generate_random(int l ,int r, int count)
{
	int i;
	for(i=0;i<count;i++)
	{
		int random_num=(rand()%(r-l+1))+l;
		return random_num;
	}
}

void US_init()
{
	//init the us hw
	printf("US init");
	pUS_state=STATE(US_busy);

}

STATE_define(US_busy)
{
	US_state_id=US_busy;
	//read from us
	int distance =generate_random(45,55,1);
	printf("US_busy......distance=%d \n",distance);
	distance_set(distance);
	pUS_state=STATE(US_busy);
	
}